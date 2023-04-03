#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int dset[30];

string solution(string source) {
    string answer = "";
    int total = source.size();
    for(int i = 0;i<source.size();i++){
        dset[source[i]-'a']++;
        // cout<<source[i] - 'a'<<endl;
    }

    while(total > 0){
        for(int i = 0;i<26;i++){
            if(dset[i] > 0){
                dset[i]--;
                answer += ('a'+ i);
                total--;
            }
        }
    }


    return answer;
}

int main(){
    
    cout<<solution("bbaabd");
    return 0;
}