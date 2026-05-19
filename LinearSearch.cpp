#include <iostream>
using namespace std;

int main() {
    int arr[]={12,13,15,17,18,87};
    int x=17;
    int idx=0;
    bool flag;
    for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++)
    {
        if(arr[i]==x)  
        {
            flag =true;
            idx=i;
            break;
        }
        else flag =false ;
    }
    if(flag==true){
        cout<<"The Target ("<<x<<") is on index: "<<idx<<"."<<endl;
    }
    else cout<<"The Target("<<x<<") is not present."<<endl;
    
    return 0;
}
