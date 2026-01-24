#include <iostream>
constexpr int size=10;
using namespace std;
int sum(int arr[],int size){
    int sum=0;
    for (int i = 0; i < size; i++)
    {
        sum+=arr[i];
    }
    return sum;
}
int product(int arr[],int size){
    int prod=1;
    for (int i = 0; i < size; i++)
    {
        prod*=arr[i];
    }
    return prod;
}
int max(int arr[],int size){
    int max=arr[0];
    for (int i = 0; i < size; i++)
    {
        if(arr[i]>max) max=arr[i];
        else continue;
    }
    return max;
}
int min(int arr[],int size){
    int min=arr[0];
    for (int i = 0; i < size; i++)
    {
        if(arr[i]<min)  min=arr[i];
        else continue;
    }
    return min;
}
void intersection(int arr[], int dsc[], int size, int inter[], int &interSize) {
    interSize = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (arr[i] == dsc[j]) {
                // Check if already added to avoid duplicates
                bool alreadyAdded = false;
                for (int k = 0; k < interSize; k++) {
                    if (inter[k] == arr[i]) {
                        alreadyAdded = true;
                        break;
                    }
                }
                if (!alreadyAdded) {
                    inter[interSize++] = arr[i];
                }
            }
        }
    }
}
void printUnique(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        bool isUnique = true;
        for (int j = 0; j < size; j++) {
            if (i != j && arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}
int main() {
    int dsc[size]={0};
    int spx[size]={1,2,3,4,5,7,8,9,29};
    int arr[size]={1,2,3,4,5,5,43,2,1,29};
    int inter[size];
    int interSize;
    cout<<sum(arr,size)<<endl;
    cout<<product(arr,size)<<endl;
    cout<<max(arr,size)<<endl;
    cout<<min(arr,size)<<endl;
    intersection(arr,spx,size, inter,interSize);
    cout << "Intersection: ";
    for (int i = 0; i < interSize; i++) {
        cout << inter[i] << " ";
    }
    cout << endl;
    cout << "Unique values: ";
    printUnique(arr, size);





return 0;
}