#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool ispalindrome(string s){
int n=s.length();
for(int i=0;i<n/2;i++){
    if(s[i]!=s[n-1-i]) return false;    
    return true;
}

}
int main(){
    string s;
    cout<<"Enter String: ";
    cin>>s;
    if(ispalindrome(s)) cout<<s<<" is a palindrome."<<endl;
    else cout<<s<<" is not a palindrome."<<endl;
   return 0;
}
