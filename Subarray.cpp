#include <iostream>
using namespace std;

int main() {
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    for (int st = 0; st < n; st++)
    {   
        for (int end = 0; end < n; end++)
        {
            for (int i= st; i <=end; i++)
            {
                cout<<arr[i];
            }
            cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}