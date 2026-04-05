#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include<limits>
#include<Algorithm>


using namespace std;

vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m-k+1, vector<int>(n-k+1, 0));
        for(int i=0; i<=m-k; i++){
            for(int j=0; j<=n-k; j++){
                vector<int> temp;
                for(int r=i; r<i+k; r++){
                    for(int c=j; c<j+k; c++){
                        temp.push_back(grid[r][c]);
                    }
                }
                sort(temp.begin(), temp.end());
                int diff = INT_MAX;
                for(int x=1; x<temp.size(); x++){
                    if(temp[x] != temp[x-1]) diff = min(diff, abs(temp[x] - temp[x-1]));
                }
                ans[i][j] = (diff == INT_MAX) ? 0 : diff;
            }
        }
        return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    vector<vector<int>> grid = {
        {1, 8, 3},
        {9, 4, 7},
        {2, 5, 6}
    };
    int k = 2;
    
    vector<vector<int>> res = minAbsDiff(grid, k);
    
    for (const auto& row : res) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }
    
    return 0;
}