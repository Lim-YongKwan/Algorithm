#include<iostream>
#include<vector>
#define endl "\n"

using namespace std;

vector<int> answer;
bool visit[9];

void backtracking(int n, int m){
    if(m == n){
        for(int i = 0;i<n;i++){
            cout<<answer[i]<<" ";
        }
        cout<<endl;
        return;
    }

    for(int i =0;i<n;i++){
        if(visit[i] == true){
            continue;
        }
        visit[i] = true;
        answer.push_back(i+1);
        backtracking(n,m+1);
        answer.pop_back();
        visit[i] = false;
    }
}

void solve(int n){
    backtracking(n,0);
}

int input(){
    int n;
    cin>>n;
    return n;
}

int main(){
    int n = input();
    solve(n);
    return 0;
}