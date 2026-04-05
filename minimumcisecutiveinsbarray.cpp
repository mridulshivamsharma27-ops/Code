#include<iostream>
#include<vector>
#include<set>
#include<climits>
#include<limits>


using namespace std;


vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
int m=grid.size();
int n=grid[0].size();
for(int i=0;i<=m-k;i++){
    for(int j=0;j<=n-k;j++){
        set <int> st;
        for(int a=i;a<=i+k-1;a++){
            for(int b=j;a<=j+k-1;b++){
                st.insert(grid[i][j]);
            }
        }
        int Minimumdiff=INT_MAX;
        auto prev=st.begin();
        auto curr=next(prev);

        while(curr!=st.end()){
            Minimumdiff=min(Minimumdiff,*curr-*prev);
            prev=curr;
            curr++;
        }

    }
}
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