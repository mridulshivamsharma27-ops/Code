#include<stdio.h>
void merge(int *arr,int lb,int mid,int ub){
    int b[ub+1];
int i=lb;
int j=mid+1;
int k=lb;
while(i<=mid && j<=ub){
    if(arr[i]<=arr[j]){
        b[k]=arr[i];
        i++;
    }
    else{
        b[k]=arr[j];
        j++;
    }
    
    k++;
}
if(i>mid){
    while(j<=ub){
        b[k]=arr[j];
        j++;k++;
    }
}
else{
    while(i<=mid){
        b[k]=arr[i];
        i++;k++;
    }
}
for(int i=lb;i<=ub;i++){
    arr[i]=b[i];
}
}
void mergesort(int * a,int lb,int ub){
    if(lb<ub){
       int mid=lb+(ub+lb)/2;
        mergesort(a,lb,mid);
        mergesort(a,mid+1,ub);
        merge(a,lb,mid,ub);
    }
}