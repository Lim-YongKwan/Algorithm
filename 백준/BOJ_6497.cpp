#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,pair<int,int> > > graph;
int parent[200010];
int n,m;
long long total;

void initParent(){
    for(int i = 0;i<=200005;i++){
        parent[i] = i;
    }
    return;
}

int find(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}

void mergeUnion(int x, int y){
    int a = find(x);
    int b = find(y);
    if(a == b){
        return;
    }
    parent[b] = a;
    return;
}

bool sameParent(int x, int y){
    int a = find(x);
    int b = find(y);
    if(a == b){
        return true;
    }
    return false;
}

void solve(){
    long long answer = 0;
    for(int i = 0;i<graph.size();i++){
        if(sameParent(graph[i].second.first,graph[i].second.second) == false){
            mergeUnion(graph[i].second.first,graph[i].second.second);
            answer += graph[i].first;
        }
    }
    cout<<total - answer<<endl;
    return;
}

int main(){
    while(true){
        cin>>n>>m;
        if(n == 0 and m == 0){
            break;
        }
        initParent();

        for(int i = 0;i<m;i++){
            int source,destination,cost;
            cin>>source>>destination>>cost;
            total += cost;
            graph.push_back(make_pair(cost,make_pair(source,destination)));
            graph.push_back(make_pair(cost,make_pair(destination,source)));
        }
        sort(graph.begin(),graph.end());
        solve();

        initParent();

        for(int i = 0;i<graph.size();i++){
            graph[i].first = 0;
            graph[i].second.first = 0;
            graph[i].second.second = 0;
        }
        total = 0;
    }
    return 0;
}