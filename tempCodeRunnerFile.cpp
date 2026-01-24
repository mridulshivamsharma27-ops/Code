#include <iostream>
using namespace std;
void printUnique(int arr[],int size);
int main() {
    int size=6;
    int arr[size]={1,2,2,4,1,6};
    printUnique(arr,size);
return 0;
} 
void printUnique(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        bool isUnique = true;
        for (int j = 0; j < size; j++) {
            if (i != j && arr[i] == arr[j]) {
                isUnique = false;
                break;
            }
        }
        if (isUnique) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}