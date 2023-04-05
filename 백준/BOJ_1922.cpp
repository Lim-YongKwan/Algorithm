#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int,pair<int,int> > > graph;
int parent[1011];
int n,m;
int answer;

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
    for(int i = 0;i<m;i++){
        if(sameParent(graph[i].second.first,graph[i].second.second) == false){
            mergeUnion(graph[i].second.first,graph[i].second.second);
            answer += graph[i].first;
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int cost,destination,source;
        cin>>source>>destination>>cost;
        graph.push_back(make_pair(cost,make_pair(source,destination)));
    }
    for(int i = 1;i<=n;i++){
        parent[i] = i;
    }
    sort(graph.begin(),graph.end());
    solve();
    cout<<answer<<endl;
    return 0;
}