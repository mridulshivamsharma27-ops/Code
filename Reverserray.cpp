#include <iostream>
constexpr int size=10;
using namespace std;
void reverse(int *arr,int *rev,int size){
    int i=0,j=size-1;
    while(i<size && j>=0 ){
        rev[i++]=arr[j--];
    }
    return ;
}
int main() {
    int a[size]={1,2,3,4,5,6,7,8,9,10};
    int b[size];
    cout<<"\t\t"<<"Original"<<"\t\t"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<a[i]<<"\t";
    } 
    cout<<endl;
    reverse(a,b,size);
    cout<<"\t\t"<<"Reverse"<<"\t\t"<<endl;
    for (int i = 0; i < size; i++)
    {
        cout<<b[i]<<"\t";
    }
    swap(a[10],b[10]);
    cout<<a[size-1];
return 0;
}