#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"

using namespace std;

vector<int> graph[1010];
vector<int> result;
int adj[1010];
int n,m;

void topological(){

    queue<int> q;
    for(int i = 1;i<=n;i++){
        if(adj[i] == 0){
            q.push(i);
        }
    }

    while(q.size() > 0){
        int cur = q.front();
        q.pop();
        result.push_back(cur);

        for(int i = 0;i<graph[cur].size();i++){
            int next = graph[cur][i];
            adj[next] -= 1;
            if(adj[next] == 0){
                q.push(next);
            }
        }
    }

    return;
}

int main(){
    cin>>n>>m;

    while(m--){
        int num;
        cin>>num;
        if(num == 0){
            continue;
        }
        else if(num == 1){
            int b;
            cin>>b;
            continue;
        }

        int singer;
        cin>>singer;
        int subSinger;

        for(int i = 1;i<num;i++){
            cin>>subSinger;
            graph[singer].push_back(subSinger);
            adj[subSinger] += 1;
            singer = subSinger;
        }
    }

    topological();

    if(result.size() != n){
        cout<<0<<endl;
    }
    else{
        for(int i = 0;i<result.size();i++){
            cout<<result[i]<<endl;
        }
    }


    return 0;
}