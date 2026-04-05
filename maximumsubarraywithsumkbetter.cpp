/* Better -> best case for negative and zero included maximum subarray with sum k means element in array has negative and zero values*/  

#include<iostream>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;
int longestsubarraywithsumk(vector<int> a,long long k){
    map<long long,int> ar;
    long long sum=0;
    int maxlen=0;
    for (int i=0;i<a.size();i++){
        sum+=a[i];
     if(sum==k){  maxlen=max(maxlen,i+1);
    }
    long long res=sum-k;
    if(ar.find(res)!=ar.end()){
        int len=i-ar[res];
        maxlen=max(maxlen,len);
    }
    if(ar.find(sum)==ar.end()){
    ar[sum]=i;
    }
}
return maxlen;
}
int main(){

}