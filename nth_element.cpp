                                    /* K th Smallest element*/

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int k;
    int arr[]={10,5,4,3,48,6,2,33,53,10};
    int size=sizeof(arr)/sizeof(arr[0]);
    // sort(arr,arr+size);

    cout<<"Enter Your k(The Smallest element): ";
    cin>>k;

    /* if(k>0 && k<=size){
        cout << "The Smallest element (" << k << ") is " << arr[k - 1];
    }
    else{
        cout<<"k is Out of Bound!";
    } */

    // optimised part ->

    if (k > 0 && k <= size) {
        // Optimised: Only partitions the array around the k-th element
        // Average Time Complexity: O(n)
        nth_element(arr, arr + (k - 1), arr + size);

        cout << "The " << k << "-th smallest element is: " << arr[k - 1];
    }

    return 0;
}
/* nth_element is a partial sort in algorithm which sorts till our given  k value not full array
1.Partial Sort: It only puts the correct value at the $k^{th}$ position instead of sorting the whole array.
2.Smart Partitioning: It ensures all smaller values stay to the left and larger values stay to the right of that position.
3.Faster Performance: It runs in $O(n)$ time on average, making it much faster than $O(n \log n)$ for large datasets.
->Best Use Case: Use it when you only need a specific rank (like the median or 3rd smallest) and don't care about the order of the rest. */