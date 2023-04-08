#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> graph[10000];
vector<int> result;
int subject[10000];
int deg[10000];
int n,m;

void topo(){
    queue<int> q;

    for(int i = 1;i<=n;i++){
        if(deg[i] == 0){
            q.push(i);
            subject[i] = 1;
            result.push_back(i);
        }
    }

    while(q.size() > 0){
        int cur = q.front();
        q.pop();
        for(int i = 0;i<graph[cur].size();i++){
            int next = graph[cur][i];
            deg[next]--;
            if(deg[next] == 0 ){
                q.push(next);
                subject[next] = subject[cur] + 1;
            }
        }
    }

    return;
}

int main(){
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int source,destination;
        cin>>source>>destination;
        deg[destination]++;
        graph[source].push_back(destination);
    }

    topo();

    for(int i = 1;i<=n;i++){
        cout<<subject[i]<<" ";
    }

    return 0;
}