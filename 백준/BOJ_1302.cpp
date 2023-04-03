#include<iostream>
#include<string>
#include<queue>
#include<map>
#include<algorithm>
#define endl "\n"
using namespace std;

int main(){
    int n;
    cin>>n;
    map<string,int> best;

    int max_count = 0;

    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        best[s]++;
        max_count = max(max_count,best[s]);
    }
    map<string,int>::iterator iter;
    for(iter = best.begin(); iter != best.end(); iter++){
        if(iter->second == max_count){
            cout<<iter->first<<endl;
            return 0;
        }
    }

    return 0;
}