#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
void vectorx(vector <int> &vec){
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
int main() {
    vector <int> vec;
    vectorx(vec);

return 0;
}