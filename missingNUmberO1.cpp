        /* Optimal-1 */
#include<iostream>
#include<vector>



using namespace std;
int findMissingNumbers(int *ar, int n,int N) {
    int expected_sum=((n*(n+1))/2);
    int found_sum=0;
    for(int i=0;i<N;i++){
        found_sum+=ar[i];
    }
    int digit=expected_sum-found_sum;
    return digit;
}
int main() {
    int my_array[] = {1, 2, 4, 5}; 
    
    int n = 5; 
    int N = sizeof(my_array) / sizeof(my_array[0]); 

    int x=findMissingNumbers(my_array, n, N);
    cout<<"Missing: "<< x<<endl;

    return 0;
}
