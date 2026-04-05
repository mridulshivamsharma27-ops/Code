        /* Better */
#include<iostream>
#include<vector>



using namespace std;
void findMissingNumbers(int *ar, int n,int N) {
    vector <int> vec(n+1,0);
    for(int i=0;i<n;i++){
        vec[ar[i]]=1;
    }
    cout << "Missing: ";
    for (int i = 1; i <= n; i++) {
        if (vec[i] == 0) {
            cout << i << " ";
        }
        }
    cout << endl;
}
int main() {
    int my_array[] = {1, 2, 4, 5}; 
    
    int n = 5; 
    int N = sizeof(my_array) / sizeof(my_array[0]); 

    findMissingNumbers(my_array, n, N);


    return 0;
}
