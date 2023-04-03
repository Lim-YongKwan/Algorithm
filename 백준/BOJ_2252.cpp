#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> adj[32001];
vector<int> result;
int arr[32001];
int n,m;

void solve(){

    queue<int> q;

    for(int i = 1;i<=n;i++){
        if(arr[i] == 0){
            q.push(i);
            result.push_back(i);
        }
    }

    while(q.size() > 0){
        int cur = q.front();
        q.pop();
        for(int i = 0;i<adj[cur].size();i++){
            int next = adj[cur][i];
            arr[next]--;
            if(arr[next] == 0){
                q.push(next);
                result.push_back(next);
            }
        }
    }

    return;
}

int main(){
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        arr[b]++;
    }

    solve();

    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;

    return 0;
}