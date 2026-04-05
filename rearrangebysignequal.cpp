/*brute 1st variety->where pos =neg*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> rearrangebysign(vector<int> &nums){
    vector<int> pos,neg,result;
    for(int it:nums){
        if(it>=0){
        pos.push_back(it);
        }
        else{
        neg.push_back(it);
        }
    }
    for(int i=0;i<pos.size();i++){
        result.push_back(pos[i]);
        result.push_back(neg[i]);
    }
    return result;
}
int main(){

}