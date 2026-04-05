            /*Brute*/

#include<iostream>
#include<set>

using namespace std;
int un_nion(int *arr1,int n1,int *arr2,int n2,int *union_n){
    set<int> st;
    
    for(int i=0;i<n1;i++){
        st.insert(arr1[i]);
    }
    
    for(int i=0;i<n2;i++){
        st.insert(arr2[i]);
    }
    
    int a=0;
    
    for(auto it:st){
        union_n[a++]=it;
    }
    return a;


}
int main(){
    int arr1[]={1,1,2,3,4,5};
    int arr2[]={2,3,3,4,6,7};
    int a[20]={0};

    int size=un_nion(arr1, 6,arr2, 7, a);
    cout<<"Union Of Arrays: ";
    for(int i=0;i<size;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}