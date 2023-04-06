#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> adj[10010];
int deg[10010];
int cost[10010];
int cost2[10010];
int n;
int max_answer;

void solve(){

    queue<int> q;
    for(int i = 1;i<=n;i++){
        if(deg[i] == 0){
            q.push(i);
        }
        cost2[i] = cost[i];
    }
    
    while(q.size() > 0){
        int cur = q.front();
        q.pop();
        for(int i = 0;i<adj[cur].size();i++){
            int next = adj[cur][i];
            deg[next]--;
            if(deg[next] == 0){
                q.push(next);
            }
            cost2[next] = max(cost2[next],cost2[cur] + cost[next]);
        }
    }
    return;
}

int main(){
    cin>>n;
    for(int i = 1;i<=n;i++){
        int source = i;
        int price,num;
        cin>>price>>num;
        cost[i] = price;
        for(int j = 0;j<num;j++){
            int temp;
            cin>>temp;
            adj[temp].push_back(i);
            deg[i]++;
        }
    }
    solve();

    for(int i = 1;i<=n;i++){
        max_answer = max(max_answer,cost2[i]);
    }
    cout<<max_answer<<endl;

    return 0;
}