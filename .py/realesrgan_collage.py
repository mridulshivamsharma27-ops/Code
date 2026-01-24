import os
import numpy as np
from PIL import Image, ImageEnhance
import torch
from basicsr.archs.rrdbnet_arch import RRDBNet
from realesrgan import RealESRGANer

def resize_to_fit(img, target_size, bg_color=(30, 30, 30)):
    """Resize image proportionally and pad to target_size."""
    target_w, target_h = target_size
    img_w, img_h = img.size
    scale = min(target_w / img_w, target_h / img_h)
    new_w, new_h = int(img_w * scale), int(img_h * scale)
    resized = img.resize((new_w, new_h), Image.Resampling.LANCZOS)
    canvas = Image.new("RGB", (target_w, target_h), bg_color)
    x = (target_w - new_w) // 2
    y = (target_h - new_h) // 2
    canvas.paste(resized, (x, y))
    return canvas

def add_border(img, border=5, color=(255, 255, 255)):
    """Add a border around the image."""
    w, h = img.size
    new_img = Image.new("RGB", (w + 2*border, h + 2*border), color)
    new_img.paste(img, (border, border))
    return new_img

def enhance_with_realesrgan(collage, scale=2, weights_path=r"C:\Code\Real-ESRGAN\weights\realesr-general-x4v3.pth"):
    """Enhance collage using Real-ESRGAN."""
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")
    print(f"🔧 Using device: {device}")
    
    # Initialize the model architecture (RealESRGAN_x4plus for general use)
    model = RRDBNet(num_in_ch=3, num_out_ch=3, num_feat=64, num_block=23, num_grow_ch=32, scale=4)
    
    # Set up the upsampler
    upsampler = RealESRGANer(
        scale=4,  # The model is trained for 4x upscaling
        model_path=weights_path,
        model=model,
        tile=400,  # Process in tiles to save memory
        tile_pad=10,
        pre_pad=0,
        half=True if device.type == 'cuda' else False  # Use FP16 on GPU for speed
    )
    
    # Convert PIL Image to numpy array (RGB -> BGR for cv2 compatibility)
    img_np = np.array(collage)[:, :, ::-1]  # RGB to BGR
    
    # Upscale
    try:
        output, _ = upsampler.enhance(img_np, outscale=scale/4)  # Adjust scale since model does 4x
    except Exception as e:
        print(f"⚠️ Enhancement failed: {e}")
        print("📌 Returning original image")
        return collage
    
    # Convert back to PIL Image (BGR -> RGB)
    output_rgb = output[:, :, ::-1]
    enhanced = Image.fromarray(output_rgb)
    
    return enhanced

def make_collages_to_pdf(folder_path, output_pdf, cell_size=(300, 300)):
    valid_exts = (".jpg", ".jpeg", ".png", ".bmp")
    files = [f for f in os.listdir(folder_path) if f.lower().endswith(valid_exts)]
    files.sort()
    
    if len(files) < 56:
        raise ValueError(f"Expected 56 images, found only {len(files)}")
    
    collages = []
    
    for i in range(0, len(files), 4):
        group = files[i:i+4]
        if len(group) < 4:
            break
        
        collage_w = (cell_size[0] + 10) * 2
        collage_h = (cell_size[1] + 10) * 2
        collage = Image.new("RGB", (collage_w, collage_h), color=(30, 30, 30))
        
        for idx, fname in enumerate(group):
            img = Image.open(os.path.join(folder_path, fname)).convert("RGB")
            img = resize_to_fit(img, cell_size)
            img = add_border(img, border=5, color=(255, 255, 255))
            
            x = (idx % 2) * (cell_size[0] + 10)
            y = (idx // 2) * (cell_size[1] + 10)
            collage.paste(img, (x, y))
        
        # Apply sharpening before AI upscaling
        collage = ImageEnhance.Sharpness(collage).enhance(1.5)
        
        # Enhance with Real-ESRGAN
        collage = enhance_with_realesrgan(collage, scale=2)
        
        collages.append(collage)
        print(f"✅ Collage {i//4 + 1} enhanced and added.")
    
    # Save all collages as PDF
    collages[0].save(output_pdf, save_all=True, append_images=collages[1:], resolution=300.0)
    print(f"\n🎉 Saved {len(collages)} collages into {output_pdf}")

if __name__ == "__main__":
    folder = r"C:\Code\images"
    output = r"C:\Code\Collage.pdf"
    make_collages_to_pdf(folder, output, cell_size=(300, 300))
