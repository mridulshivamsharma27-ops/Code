#include <stdio.h>
#include <stdbool.h>

// Inserion at point x
int insertion(int arr[],int n,int pos,int val){
    if(pos>n || pos<0){
        printf("Invalid Position");
        return n;
    }
    else{
    for(int i=n-1;i>=pos;i--){
        arr[i+1]=arr[i];
    }
    arr[pos]=val;
}
   return n+1;
}
// Deletion at point x
int deletion(int arr[],int n,int pos){
    if(pos>=n || pos<0){
        printf("Invalid Position");
        return n;
    }
    else{
    for(int i=pos;i<n-1;i++){
        arr[i]=arr[i+1];
    }
}
    return n-1;
}
void linerasearch(int arr[],int n,int target){
bool flag=false;
int i;
for(i=0;i<n;i++){
    if(arr[i]==target){
        flag=true;
        break;
    }
}
if(flag==true){
    printf("Target(%d) is present in database at index %d",target,i);
}
else{
    printf("Target(%d) is not present in database",target);
}
}
int binarysearch(int arr[],int n,int Target){
    int low=0,high=n-1,mid=floor((low+high)/2);
    if(arr[mid]==Target){
        printf("Target(%d) is present in database at index %d",Target,mid);
        return mid;
    }
    else if(Target<arr[mid]){
        high=mid-1;
    }
    else if(Target>arr[mid]){
        low=mid+1;
    }
    if(low>high){
        printf("Target(%d) is not present in database",Target);
        return -1;
    } 
}
int main(){
    int arr[100],n,pos,val;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter the position and value to be inserted: ");
    scanf("%d %d",&pos,&val);
    n=insertion(arr,n,pos,val);
    printf("Array after insertion: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nEnter the position to be deleted: ");
    scanf("%d",&pos);
    n=deletion(arr,n,pos);
    printf("Array after deletion: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    linerasearch(arr,n,12);
    return 0;
}