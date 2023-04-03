#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define endl "\n"

using namespace std;

vector<int> building[501];
vector<int> result;
int cost[501];
int cost2[501];
int adj[501];
int n;

void topological(){
    queue<int> q;

    for(int i = 0;i<=n;i++){
        cost2[i] = cost[i];
    }
    
    for(int i = 1;i<=n;i++){
        if(adj[i] == 0){
            q.push(i);
        }
    }

    while(q.size() > 0){
        int cur = q.front();
        q.pop();

        for(int i = 0;i<building[cur].size();i++){
            int next = building[cur][i];
            adj[next]--;
            if(adj[next] == 0){
                q.push(next);
            }
            cost2[next] = max(cost2[next],cost2[cur] + cost[next]);
        }
    }

    for(int i = 1;i<=n;i++){
        cout<<cost2[i]<<endl;
    }

    return;
}

int main(){
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>cost[i];
        int b;
        while(cin>>b){
            if(b == -1){
                break;
            }
            adj[i]++;
            building[b].push_back(i);
        }
    }

    topological();

    return 0;
}