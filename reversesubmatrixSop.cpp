                                                                /*Second Option*/

#include<iostream>
#include<vector>
/* size_t is unsigned int for indexing and counting ,it stores positive number from 0 to 2^64-1 and is indirectly available in vector  */
#include<iomanip>
/* setw stands for set width. It is a "stream manipulator" used in C++ to format your output by setting the number of character spaces the next value should occupy.
To use it, you must include the <iomanip> (Input/Output Manipulation) library */
using namespace std;

vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
    /*grid is a vector array, x->row index,y->column index,k->square submatrix dimension(like 3*3 or 2*2) */
    for(size_t i = y; i<y+k;++i){
        /* i = y: Starts at the left-most column of your submatrix ,i < y + k: Ends at the right-most column of your submatrix */
        for(size_t j=x, m=x+k-1; j<m; ++j, --m){
            swap(grid[j][i], grid[m][i]);
        }
    }

    return move(grid);
    /* In C++, return move(grid); is a performance optimization that tells the compiler to transfer ownership of the data instead of making a copy. */
    /* A Copy(The Hard Way) v/s A Move(The Smart Way)->You have two separate houses with identical stuff. v/s The furniture stays exactly where it was in the room, but the "owner" of the house has changed. The old owner now has an empty keychain  ,which is easier .Move wins.*/
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

    cout << "\nAfter Vertical Flip (3x3 at 1,1):" << endl;
    printGrid(myGrid);

    return 0;
}