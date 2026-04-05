/*better 1st variety->where pos =neg*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> rearrangeArray(vector<int>& nums) {
    vector<int> result(nums.size(),0);
    int neg=1,pos=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]<0){
            result[neg]=nums[i];
            neg+=2;
        }
        else{
            result[pos]=nums[i];
            pos+=2;
        }
    }
    return result;
}
int main(){
    
}
