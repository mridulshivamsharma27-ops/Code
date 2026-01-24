import os
import sys
import numpy as np
import torch
from PIL import Image, ImageEnhance
from realesrgan import RealESRGANer
from basicsr.archs.rrdbnet_arch import RRDBNet

def resize_to_fit(img, target_size, bg_color=(30,30,30)):
    """Resize image proportionally and pad to target_size."""
    target_w, target_h = target_size
    img_w, img_h = img.size
    scale = min(target_w / img_w, target_h / img_h)
    new_w, new_h = int(img_w * scale), int(img_h * scale)
    
    # High-quality resizing
    resized = img.resize((new_w, new_h), Image.Resampling.LANCZOS)
    
    # Paste onto background
    canvas = Image.new("RGB", (target_w, target_h), bg_color)
    x = (target_w - new_w) // 2
    y = (target_h - new_h) // 2
    canvas.paste(resized, (x, y))
    return canvas

def add_border(img, border=5, color=(255,255,255)):
    """Add a border around the image."""
    w, h = img.size
    new_img = Image.new("RGB", (w + 2*border, h + 2*border), color)
    new_img.paste(img, (border, border))
    return new_img

def enhance_with_realesrgan(collage, scale=2, weights_path="RealESRGAN_x4plus.pth"):
    """
    Enhance collage using Real-ESRGAN.
    converts PIL -> Numpy (BGR) -> AI Enhance -> PIL
    """
    # 1. Verify model file exists
    if not os.path.exists(weights_path):
        raise FileNotFoundError(f"⚠️ Model file missing: {os.path.abspath(weights_path)}")

    # 2. Setup Device (GPU or CPU)
    device = "cuda" if torch.cuda.is_available() else "cpu"
    
    # 3. Define Model Architecture (Required for RealESRGANer)
    model = RRDBNet(num_in_ch=3, num_out_ch=3, num_feat=64, num_block=23, num_grow_ch=32, scale=4)

    # 4. Initialize Upsampler
    upsampler = RealESRGANer(
        scale=4,
        model_path=weights_path,
        model=model,
        tile=0,                 # 0 = no tiling (faster), use 400 if you run out of RAM
        tile_pad=10,
        pre_pad=0,
        half=(device == 'cuda'), # Use half precision only on GPU
        device=device
    )

    # 5. Convert PIL Image (RGB) to Numpy Array (BGR)
    img_np = np.array(collage)
    img_np = img_np[:, :, ::-1] # Flip RGB to BGR for OpenCV/Model

    # 6. Run Enhancement
    # We use outscale=scale to get exactly 2x size (or whatever you set)
    output, _ = upsampler.enhance(img_np, outscale=scale)

    # 7. Convert Numpy Array (BGR) back to PIL Image (RGB)
    output = output[:, :, ::-1] # Flip BGR back to RGB
    return Image.fromarray(output)

def make_collages_to_pdf(folder_path, output_pdf, cell_size=(300, 300)):
    # 1. Gather Images
    valid_exts = (".jpg", ".jpeg", ".png", ".bmp", ".webp")
    files = [f for f in os.listdir(folder_path) if f.lower().endswith(valid_exts)]
    files.sort()

    if not files:
        print(f"❌ No images found in {folder_path}")
        return

    print(f"📂 Found {len(files)} images. Starting processing...")
    
    collages = []
    
    # 2. Process in batches of 4
    for i in range(0, len(files), 4):
        group = files[i:i+4]
        
        # Calculate Canvas Size
        collage_w = (cell_size[0] + 10) * 2
        collage_h = (cell_size[1] + 10) * 2
        collage = Image.new("RGB", (collage_w, collage_h), color=(30, 30, 30))

        # Place 4 Images
        for idx, fname in enumerate(group):
            img_path = os.path.join(folder_path, fname)
            try:
                img = Image.open(img_path).convert("RGB")
                img = resize_to_fit(img, cell_size)
                img = add_border(img, border=5, color=(255,255,255))
                
                # Grid positioning
                x = (idx % 2) * (cell_size[0] + 10)
                y = (idx // 2) * (cell_size[1] + 10)
                collage.paste(img, (x, y))
            except Exception as e:
                print(f"⚠️ Error loading {fname}: {e}")

        # Basic Sharpness
        collage = ImageEnhance.Sharpness(collage).enhance(1.5)
        
        # 3. Apply AI Enhancement (with fallback)
        try:
            # Assumes model file is in the same directory as this script
            script_dir = os.path.dirname(os.path.abspath(__file__))
            model_path = os.path.join(script_dir, "RealESRGAN_x4plus.pth")
            
            print(f"🔄 Enhancing Collage {i//4 + 1}...")
            collage = enhance_with_realesrgan(collage, scale=2, weights_path=model_path)
            print(f"   ✅ Enhanced successfully.")
        except FileNotFoundError as fnf:
            print(f"   ⚠️ {fnf}")
            print("   👉 Skipping AI enhancement (Standard quality saved).")
        except Exception as e:
            print(f"   ⚠️ AI Enhancement Failed: {e}")
            print("   👉 Saving un-enhanced version.")

        collages.append(collage)

    # 4. Save to PDF
    if collages:
        collages[0].save(output_pdf, save_all=True, append_images=collages[1:])
        print(f"\n🎉 SUCCESS! Saved {len(collages)} pages to: {output_pdf}")
    else:
        print("\n⚠️ No collages were generated.")

if __name__ == "__main__":
    # --- CONFIGURATION ---
    # Use 'raw string' notation (r"...") to avoid path errors on Windows
    input_folder = r"C:\Code\images"
    output_file = r"C:\Code\Collage.pdf"
    
    make_collages_to_pdf(input_folder, output_file, cell_size=(300, 300))