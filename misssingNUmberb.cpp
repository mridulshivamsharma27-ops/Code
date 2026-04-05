        /* Brute */
#include<iostream>


using namespace std;
void findMissingNumbers(int *ar, int n, int N) {
    for (int i = 1; i <= n; i++) {
        bool flag = 0;
        for (int j = 0; j < N; j++) {
            if (ar[j] == i) {
                flag = 1;
                break;
            }
        }
       
        if (flag == 0) {
            cout << i << " "; 
        }
    }
}
int main() {
    int my_array[] = {1, 2, 4, 5}; 
    
    int n = 5; 
    int N = sizeof(my_array) / sizeof(my_array[0]); 

    findMissingNumbers(my_array, n, N);


    return 0;
}
