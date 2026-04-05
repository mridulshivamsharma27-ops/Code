#include <iostream>
#include <vector>
using namespace std;

void reversearray(vector<int>& arr) {
    int start = 0, end = arr.size() - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
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

    reversearray(arr);

    cout << "Reversed array is: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
