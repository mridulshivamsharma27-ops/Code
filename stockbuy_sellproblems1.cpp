                                                /* Stock buy and sell problems */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int stockproblem(vector<int> nums){
    int minimum=nums[0];
    int profit =0;
    for(int i=1;i<nums.size();i++){
        int cost=nums[i]-minimum;
        profit=max(profit,cost);
        minimum=min(minimum,nums[i]);
    }
    return profit;
}
int main(){
    
}