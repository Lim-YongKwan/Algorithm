#include<iostream>
#include<map>
#include<string>
#include<set>
#include<algorithm>
#define endl "\n"

using namespace std;

void another(string s){
    int total = 0;
    int len = s.length();
    int n = len;
    for(int j = 1;j<=len;j++){
        set<string> answer;
        for(int i = 0;i+j<=n;i++){
            string sub = s.substr(i,j);
            answer.insert(sub);
            cout<<"sub : "<<sub<<endl;
        }
        total += answer.size();
        // n--;
    }
    cout<<total<<endl;
    // cout<<answer.size()<<endl;
}

int main(){
    string s;
    cin>>s;
    another(s);
    return 0;
}