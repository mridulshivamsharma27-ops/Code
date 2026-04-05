#include<iostream>
#include<vector>
#include<algorithm>/* necessary for next_permutation*/

using namespace std;
/* vector<int> nextpermutation(vector <int>&nums){
    next_permutation(nums.begin(),nums.end());
    return nums;
} */
/* 
        use of stl-->
void nextPermutation(vector<int>& nums) {
    next_permutation(nums.begin(),nums.end());
    cout<<"The next permutation is"<<"\t";
    for(int i=0;i<nums.size();i++){
        cout << nums[i] << (i == nums.size() - 1 ? "" : ", ");
    }     
    cout<<endl;
    return;
} */

                                                /* optimal way to solve */
vector <int> nextpermutation(vector<int> &nums){
    int idx=-1;
    for(int i=nums.size()-2;i>=0;i--){
        if(nums[i]<nums[i+1]) {
            idx=i; 
            break;
        }
    }

    if(idx==-1) {
        reverse(nums.begin(),nums.end());
        return nums;
    }

    for(int i=nums.size()-1;i>idx;i--){
        if(nums[i]>nums[idx]) {
            swap(nums[i],nums[idx]); 
            break;
        }
    }
    reverse(nums.begin()+idx+1,nums.end());

    return nums;
}

int main(){

}