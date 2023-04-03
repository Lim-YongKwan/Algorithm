#include<iostream>
#include<string>
#include<vector>
#define endl "\n"

using namespace std;

void solve(string s){
    vector<char> answer;
    answer.push_back(s[0]);
    for(int i = 0;i<s.length();i++){
        if(s[i] == '-'){
            answer.push_back(s[i+1]);
        }
    }
    for(int i = 0;i<answer.size();i++){
        cout<<answer[i];
    }
    cout<<endl;
}

int main(){
    string s;
    cin>>s;
    solve(s);
    return 0;
}