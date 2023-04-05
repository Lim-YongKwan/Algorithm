#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,pair<int,int> > > graph;
int parent[100001];
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
    if(find(x) == find(y)){
        return true;
    }
    return false;
}

void solve(){

    int max_answer = 0;

    for(int i = 0;i<graph.size();i++){
        if(sameParent(graph[i].second.first,graph[i].second.second) == false){
            mergeUnion(graph[i].second.first,graph[i].second.second);
            // cout<<"graph : ";
            // cout<<graph[i].second.first<<" "<<graph[i].second.second<<endl;
            max_answer = max(max_answer,graph[i].first);
            answer += graph[i].first;
        }
    }
    answer -= max_answer;

    return;
}

int main(){
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int source,destination,cost;
        cin>>source>>destination>>cost;
        graph.push_back(make_pair(cost,make_pair(source,destination)));
        graph.push_back(make_pair(cost,make_pair(destination,source)));
    }

    for(int i = 0;i<=n;i++){
        parent[i] = i;
    }
    sort(graph.begin(),graph.end());

    // for(int i = 0;i<graph.size();i++){
    //     cout<<"graph : "<<i<<" ";
    //     cout<<graph[i].second.first<<" "<<graph[i].second.second<<endl;
    // }
    solve();

    cout<<answer<<endl;
    return 0;
}