#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Approach-1: Using Frequency Array */
// FIX 1: 'List<int>' is Java. In C++, use 'vector<int>'.
void recurPermute(vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans, vector<bool>& freq) {
    if (ds.size() == nums.size()) {
        ans.push_back(ds); 
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (!freq[i]) {
            freq[i] = true;          
            ds.push_back(nums[i]);   
            
            recurPermute(nums, ds, ans, freq);
            
            // Backtrack
            ds.pop_back();           
            freq[i] = false;         
        }
    }
}

// FIX 2: Renamed to permuteApproach1 to avoid conflict with Approach 2
vector<vector<int>> permuteApproach1(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> ds;
    vector<bool> freq(nums.size(), false); 
    
    recurPermute(nums, ds, ans, freq);
    return ans;
}

/* Approach-2: Using Swapping (Optimal Space) */
void recur1Permute(int index, vector<int>& nums, vector<vector<int>>& ans) {
    if (index == nums.size()) {
        ans.push_back(nums); 
        return;
    }

    for (int i = index; i < nums.size(); i++) {
        swap(nums[i], nums[index]);
        recur1Permute(index + 1, nums, ans);
        // Backtrack
        swap(nums[i], nums[index]);
    }
}

vector<vector<int>> permuteApproach2(vector<int>& nums) {
    vector<vector<int>> ans;
    recur1Permute(0, nums, ans);
    return ans;
}

int main() {
    vector<int> nums = {1, 2, 3};
    
    // Testing Approach 2
    vector<vector<int>> result = permuteApproach2(nums);
    
    cout << "Total Permutations: " << result.size() << endl;
    for(auto p : result) {
        cout << "[ ";
        for(int x : p) cout << x << " ";
        cout << "]" << endl;
    }

    return 0;
}