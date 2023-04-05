#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

vector<pair<int,pair<int,int> > > tree; 
int parent[100005];
int v,e;
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
    for(int i = 0;i<e;i++){
        if(sameParent(tree[i].second.first,tree[i].second.second) == false){
            mergeUnion(tree[i].second.first,tree[i].second.second);
            answer += tree[i].first;
        }
    }
    return;
}

int main(){
    cin>>v>>e;
    for(int i = 1;i<=v;i++){
        parent[i] = i;
    }

    for(int i = 0;i<e;i++){
        int a,b,c;
        cin>>a>>b>>c;
        tree.push_back(make_pair(c,make_pair(a,b)));
    }
    sort(tree.begin(),tree.end());
    solve();
    cout<<answer<<endl;
    return 0;
}