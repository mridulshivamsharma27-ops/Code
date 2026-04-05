#include<iostream>
#include<vector>
#include<algorithm>

int kthSmallest(std::vector<int> &arr, int k) {
    int size=arr.size();
    if(k>0 && k<=size){
        std::nth_element(arr.begin(),arr.begin()+(k-1),arr.end());
        return arr[k-1];
    }
    return -1 ;

}
int main(){
    std::vector <int> arr={10, 5, 4, 3, 48, 6, 2, 33, 53, 10};
    int k;
    std::cout<<"Enter k(Smallest Number): ";
    std::cin>>k;
    int result=kthSmallest(arr,k);
    if(result!=-1){
        std::cout<<"The "<<k<<"-th smalllest element is :"<<arr[k-1]<<std::endl;
    }
    else{
        std::cout<<"Invalid K value"<<std::endl;

    }
    return 0;
}