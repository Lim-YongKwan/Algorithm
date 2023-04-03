#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l,c;
int visited[21];
vector<char> keys(c);
vector<char> answer(21);

void backtracking(int count){
    if(count == l){
        for(int i = 0;i<l;i++){
            cout<<answer[i];
        }
        cout<<endl;
        return;
    }
    for(int i = 0;i<c;i++){
        if(visited[i] == 0){
            visited[i] = 1;
            answer.push_back(keys[i]);
            backtracking(count + 1);
            visited[i] = 0;
            answer.pop_back();
        }
    }
    return;
}

int main(){
    cin>>l>>c;
    keys.resize(c);
    for(int i = 0;i<c;i++){
        cin>>keys[i];
    }
    cout<<"sort : "<<endl;
    sort(keys.begin(),keys.end());
    backtracking(1);

    return 0;
}