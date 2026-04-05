                        /* Better*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

int majorityelement(std::vector <int>a){
    if(!(a.empty())){
    std::map <int,int> mp;
    for(auto i=a.begin();i!=a.end();++i){
     mp[*i]++;
    }
    int Max=0;
    int resultkey=a[0];
    for(auto const&it:mp){
        int prev=Max;
        Max=std::max(Max,it.second);
        if (Max > prev) {
            resultkey = it.first;
            }
    }   
    return resultkey;
    }
    return -1;
}
int main(){
    std::vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    std::cout << "Majority Element is: " << majorityelement(nums) << std::endl;
    return 0;

}