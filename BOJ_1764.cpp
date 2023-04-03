#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<string> hearing;
    vector<string> showing;
    for(int i = 0;i<n;i++){
        string temp;
        cin>>temp;
        hearing.push_back(temp);
    }
    for(int i = 0;i<m;i++){
        string temp;
        cin>>temp;
        showing.push_back(temp);
    }
    sort(hearing.begin(),hearing.end());
    sort(showing.begin(),showing.end());
    vector<string> answer;

    for(int i = 0;i<n;i++){
        if(binary_search(showing.begin(),showing.end(),hearing[i])){
            answer.push_back(hearing[i]);
        }
    }

    cout<<answer.size()<<endl;
    for(int i = 0; i<answer.size();i++){
        cout<<answer[i]<<endl;
    }

    return 0;
}