                        /* Optimal */
#include<iostream>
#include<vector>

using namespace std;
int maxSubArray(std::vector<int>& nums) {
    int current_sum = 0;
    int max_so_far = nums[0]; 

    for (int x : nums) {
        current_sum = std::max(x, current_sum + x);
        
        max_so_far = std::max(max_so_far, current_sum);
    }
    return max_so_far;
}
int main(){

}