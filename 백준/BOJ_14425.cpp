#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#define endl "\n"

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    map<string, int> aggregate;
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        pair<string,int> temp;
        temp.first = s;
        temp.second = 1;
        aggregate.insert(temp);
    }
    int answer = 0;
    for(int i = 0;i<m;i++){
        string s;
        cin>>s;
        if(aggregate.find(s) != aggregate.end()){
            answer++;
        }
    }
    cout<<answer<<endl;
    return 0;
}