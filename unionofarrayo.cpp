            /*Optimal*/

#include<iostream>

using namespace std;
int un_nion(int *arr1,int n1,int *arr2,int n2,int *union_n){
    int i=0,j=0,k=0;
    while(i<n1 && j<n2){
    if(arr1[i]<arr2[j]){
        if (k == 0 || union_n[k - 1] != arr1[i]) {
            union_n[k++] = arr1[i];
            }
        i++;
        }
    else if(arr2[j]<arr1[i]){
        if (k == 0 || union_n[k - 1] != arr2[j]) {
        union_n[k++] = arr2[j];
            }
        j++;
        }

    else{
        if (k == 0 || union_n[k - 1] != arr1[i]) {
        union_n[k++] = arr1[i];
        }
        i++;
        j++;
        }
    }

    while (i < n1) {
        if (union_n[k - 1] != arr1[i]) union_n[k++] = arr1[i];
        i++;
    }

  
    while (j < n2) {
        if (union_n[k - 1] != arr2[j]) union_n[k++] = arr2[j];
        j++;
    }

    return k;
}
int main(){
    int arr1[]={1,1,2,3,4,5};
    int arr2[]={2,3,4,5,6};
    int a[20]={0};

    int size=un_nion(arr1, 6,arr2, 5, a);
    cout<<"Union Of Arrays: ";
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}