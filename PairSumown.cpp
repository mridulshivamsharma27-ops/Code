#include <iostream>
#include<vector>
#include <algorithm> 
using namespace std;
void vectorx( vector <int> &vec){
        int x;
    cout<<"Enter The Elements: "<<endl;
    for (;;)
    {
        cin>>x ;
        if (x<0) break;
        vec.push_back(x);
    }
    sort(vec.begin(), vec.end());
    cout << "Elements: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    return;
}
vector<int> pairsum(vector <int> vec,int TargetSUM){
     vector<int> ans;
    for (int i = 0; i < vec.size(); i++)
    {
    for (int j = i+1; j < vec.size(); j++)
    {
        if(vec[i]+vec[j]==TargetSUM){
            ans.push_back(vec[i]);
            ans.push_back(vec[j]);
            return ans;
            }
    }
    }
    return ans;
}

int main() {
    vector <int> vec,ans;
    int TargetSUM;

    vectorx(vec);
    cout<<endl;

    cout<<"Enter Your Target Sum: ";
    cin>>TargetSUM;
    cout<<endl;

    ans=pairsum(vec,TargetSUM);

    cout << "Pair Found: ";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
