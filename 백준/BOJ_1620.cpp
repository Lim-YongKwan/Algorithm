#include<iostream>
#include<map>
#include<vector>
#define endl "\n"

using namespace std;

bool isNumber(const string& str){
    return str.find_first_not_of("0123456789") == string::npos;
}

string name[100001];

int main(){
    int n,m;
    cin>>n>>m;
    map<string,int> pocket;
    for(int i = 1;i<=n;i++){
        string s;
        cin>>s;
        pair<string, int> temp;
        temp.first = s;
        temp.second = i;
        pocket.insert(temp);
        name[i] = s;
    }

    vector<string> result;
    for(int i = 0;i<m;i++){
        string s;
        cin>>s;
        result.push_back(s);
    }

    for(int i = 0;i<m;i++){
        isNumber(result[i]) ? cout<<name[stoi(result[i])]<<endl : cout<<pocket[result[i]]<<endl;
        // cout<<pocket[s]<<endl;
    }

    return 0;
}