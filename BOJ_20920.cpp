#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

bool compare(pair<string,int> str1, pair<string,int> str2){
    if(str1.second == str2.second){
        if(str1.first.size() == str2.first.size()){
            return str1.first < str2.first;
        }
        else{
            return str1.first.size() > str2.first.size(); 
        }
    }
    return str1.second > str2.second;
}

int main(){
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    
    map<string, int > word;

    for(int i = 0;i<n;i++){
        string temp;
        cin>>temp;
        if(temp.size()<m){
            continue;
        }
        if(word.find(temp) == word.end()){
            word[temp] = 0;

        }
        word[temp]++;
    }

    vector<pair<string, int> > word_refactor(word.begin(),word.end());
    sort(word_refactor.begin(),word_refactor.end(), compare);

    vector<pair<string, int> >::iterator iter;
    for(iter = word_refactor.begin(); iter != word_refactor.end(); iter++){
        cout<<iter->first <<endl;
    }

    return 0;
}