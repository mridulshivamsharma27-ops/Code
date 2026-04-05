/* Max subbaray which means array with maximum sum */
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>

using namespace std;

int maxSubArray(vector<int>& nums) {
    long long sum = 0;
    long long maxi = numeric_limits<long long> ::min();/* Important */

    for(int i = 0; i < nums.size(); i++) {
        sum += nums[i];

        if(sum > maxi) {
            maxi = sum;
        }

        if(sum < 0) {
            sum = 0;
        }
    }
    return (int)maxi;
}
int main(){
    
}
