        /* brute force */
#include<iostream>
#include<algorithm>

using namespace std;
void maximumsubarraywithsumk(int *arr,int n,int k){
    int len=0;
 for(int i=0;i<n;i++){
    int sum=0;
 for(int j=i;j<n;j++){
    sum+=arr[j];
    if(sum==k)  len=max(len,j-i+1);

}
            cout<<"Maximum length found: "<<len<<endl;    
            return;
}
}
int main(){}
