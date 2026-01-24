#include<iostream>
#define count 5
using namespace std;
void reverse(int arr[5],int dsc[5]){
    for ( int i = 0; i < count; i++)
    {
       dsc[i]=0;
    }
    for ( int i = 0; i < count; i++)
    {
       dsc[count-1-i]+=arr[i];
    }
    return;
}
bool truth(int arr[5],int dsc[5]){
   bool flag =true;
for ( int i = 0; i < count; i++)
{
    if(arr[i]!=dsc[i]) { 
        flag=false;
        break;
    }
}return flag;
}
int main(){
int arr[5]={1,2,3,2,1};
int dsc[5];

cout<<"Original:  ";
for ( int i = 0; i < count; i++)
{
    cout<<arr[i]<<"  ";
}   cout<<endl;
reverse(arr,dsc);
cout<<"Reverse:  ";
for ( int i = 0; i < count; i++)
{
    cout<<dsc[i]<<"  ";
}   cout<<endl;
if (truth(arr, dsc)) {
    cout << "Palindrome Arrays!" << endl;
} else {
    cout << "Not a Palindrome arrays!" << endl;
}
return 0;

}