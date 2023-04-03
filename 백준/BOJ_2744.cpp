#include<iostream>
#include<string>
#define endl "\n"

using namespace std;

void solve(string s){
    for(int i = 0;i<s.length();i++){
        if(s[i]<'a'){
            s[i]+=32;
        }
        else{
            s[i]-=32;
        }
    }
    cout<<s<<endl;
}

int main(){
    string s;
    cin>>s;
    solve(s);
    return 0;
}