#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
vector<vector<int>> reverseSubmatrix(vector<vector<int>> &grid, int x, int y, int k) {
    int startrow = x;
    int endrow = x + k - 1;
    
    int startcol = y;
    int endcol = y + k -1;
    for (int i = startrow; i < endrow; i++) {
        for (int j = startcol; j <= endcol; j++) {
            swap(grid[i][j], grid[endrow][j]);
        }
        endrow--;
    }
    return grid;
}

void printGrid(const vector<vector<int>>& grid) {
    for (const auto& row : grid) {
        for (int val : row) cout << setw(3) << val << " ";
        cout << endl;
    }
}

int main() {
    vector<vector<int>> myGrid = {
        { 1,  2,  3,  4,  5},
        { 6,  7,  8,  9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    cout << "Original Grid:" << endl;
    printGrid(myGrid);

    int startRow = 1, startCol = 1, size = 3;
    myGrid = reverseSubmatrix(myGrid, startRow, startCol, size);

    cout << "\nAfter Vertical Flip (3x3 block):" << endl;
    printGrid(myGrid);

    return 0;
}