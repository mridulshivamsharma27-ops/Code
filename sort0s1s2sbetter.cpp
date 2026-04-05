/* Better */
#include<iostream>
#include<vector>
using namespace std;
vector <int>sort1s(vector<int> &nums){
    int count0=0,count1=0,count2=0;
    for(const auto &it:nums){
        if(it==0) count0++;
        else if(it==1) count1++;
        else if(it==2) count2++;
    }

    int i = 0;
    while (count0--) nums[i++] = 0;
    while (count1--) nums[i++] = 1;
    while (count2--) nums[i++] = 2;
    return nums;
}
int main(){

}