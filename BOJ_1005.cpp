#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> adj[1005];
vector<int> result;
int cost[1005];
int cost2[1005];
int deg[1005];
int n,k,w;

void solve(){

    queue<int> q;
    
    for(int i = 1;i<=n;i++){
        if(deg[i] == 0){
            q.push(i);
            result.push_back(i);
            cost2[i] = cost[i];
        }
    }

    while(q.size() > 0){
        int cur = q.front();
        q.pop();

        for(int i = 0;i<adj[cur].size();i++){
            int next = adj[cur][i];
            deg[next]--;
            if(deg[next] == 0){
                q.push(next);
                result.push_back(next);
            }
            cost2[next] = max(cost2[next],cost2[cur] + cost[next]);
        }
    }
    cout<<cost2[w]<<endl;
    return;
}

void reset(){
    for(int i = 0;i<1002;i++){
        cost[i] = 0;
        cost2[i] = 0;
        deg[i] = 0;
    }

    result.clear();

    for(int i = 0;i<1002;i++){
        adj[i].clear();
    }
}

int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        cin>>n>>k;

        for(int i = 1;i<=n;i++){
            cin>>cost[i];
        }
        for(int i = 0;i<k;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            deg[b]++;
        }

        cin>>w;
        solve();
        reset();
    }
    return 0;
}