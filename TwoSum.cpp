#include<iostream>
using namespace std;
int main(){
    char comma;
    int i=0,Target=7;
    int nums[]={3,2,4};
    int size=sizeof(nums)/sizeof(nums[0]);
    while(nums[i]+nums[i+1]!=Target){
        if(nums[i]+nums[i+1]==Target){
            break;
        }
        i++;
    }
    cout<<i<<" , "<<i+1<<endl;
    return 0;
}
 