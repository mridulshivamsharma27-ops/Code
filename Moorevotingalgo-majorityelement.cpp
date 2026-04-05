                        /* Optimal*/
                        /* Moore voting Algorithm-> last man standing wins means first selest a man if another man is same then ++ otherwise 1 deduct then at last the man standing is majority element */
#include<iostream>
#include<vector>

using namespace std;
int majorityelement(vector <int>a){
    if(a.empty()) return -1;
    int count=0;
    int candidate=0;
    for (int i=0;i<a.size();i++){
        if(count==0){
        candidate=a[i];
        }
        if(a[i]==candidate) count++;
        else count--;
    }
    return candidate;
}
int main(){
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element is: " << majorityelement(nums) << std::endl;
    return 0;

}