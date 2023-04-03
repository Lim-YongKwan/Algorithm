#include<iostream>
#include<vector>
#define endl "\n"

using namespace std;

bool visit[9];
int health[10];
int n,k;
int total = 500;
int answer;
vector<int> kit;

void backtracking(int m){

    if(m == n){
        total = 500;
        int flag = 1;
        
        for(int i =0;i<kit.size();i++){
            total += kit[i];
            total -= k;
            if(total < 500){
                flag = 0;
                break;
            }
        }
        if(flag == 1){
            answer += 1;
        }
        return;
    }

    for(int i = 0;i<n;i++){
        if(visit[i] == true){
            continue;
        }

        visit[i] = true;
        kit.push_back(health[i]);
        backtracking(m+1);
        kit.pop_back();
        visit[i] = false;
    }
}

int main(){
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        cin>>health[i];
    }
    backtracking(0);
    cout<<answer<<endl;
    return 0;
}