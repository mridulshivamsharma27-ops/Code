#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
    vector <int> vec={1,2,2,1,1};
    int n=vec.size();
    int frequency=0,Ans=0;
    for (int i = 0; i <n; i++)
    {
        if(frequency==0) {Ans=vec[i];}

        if(Ans==vec[i]) frequency++;
        else  frequency--;
    }
    
    cout<<Ans;
return 0;
}