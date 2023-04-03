#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

vector<int> graph[32005];
vector<int> result;
int adj[32005];
int n,m;

void topo(){

    priority_queue<int,vector<int>,greater<int> > q;

    for(int i = 1;i<=n;i++){
        if(adj[i] == 0){
            q.push(i);
        }
    }

    while(q.size() > 0){
        int cur = q.top();
        q.pop();

        result.push_back(cur);

        for(int i = 0;i<graph[cur].size();i++){
            int next = graph[cur][i];
            adj[next]--;
            if(adj[next] == 0){
                q.push(next);
                adj[next] = -1;
            }
        }
    }
    
    return;
}

void topological(){

    topo();
    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<" ";
    }

    return;
}

int main(){
    cin>>n>>m;
    for(int i = 1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        adj[b]++;
    }
    topological();
    return 0;
}