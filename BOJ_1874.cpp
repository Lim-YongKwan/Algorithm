#include<iostream>
#include<stack>
#include<vector>

#define endl "\n"

using namespace std;

int main(){
    int n;
    cin>>n;
    
    vector<int> integer(n,0);
    stack<int> sequence;
    vector<char> answer;
    int count = 1;

    for(int i = 0;i<n;i++){
        cin>>integer[i];
        while(count<=integer[i]){
            sequence.push(count);
            count++;
            answer.push_back('+');
        }
        if(integer[i] == sequence.top()){
            sequence.pop();
            answer.push_back('-');
        }
        else{
            cout<<"NO"<<endl;
            return 0;
        }
    }
    for(int i = 0;i<answer.size();i++){
        cout<<answer[i]<<endl;
    }

    return 0;
}