#include <iostream>
#include <vector>
using namespace std;
bool checkarray(vector<int>& arr) {
    int n = arr.size();
    int count=0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= arr[i + 1]%n) {
            count++;
        }
        if(count>1) return false;
    }
    return true; 
}

int main() {
    vector<int> arr;
    int x;

    cout << "Enter elements of array (stop with 5): ";
    while (cin >> x) {
        if (x == 5) break;   // stop condition
        arr.push_back(x);    // add element to vector
    }

    if (arr.empty()) {
        cout << "No elements entered before 5!" << endl;
        return 0;
    }

    if (checkarray(arr)) {
        cout << "The array is sorted in non-decreasing order." << endl;
    } else {
        cout << "The array is not sorted in non-decreasing order." << endl;
    }
return 0;
}