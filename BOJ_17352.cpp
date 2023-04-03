#include <iostream>

using namespace std;

int parent[300001];

int findUnion(int x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = findUnion(parent[x]);
}

void mergeUnion(int a, int b){
    a = findUnion(a);
    b = findUnion(b);
    if(a != b){
        parent[b] = a;
    }

    return;
}

int main(){

    for(int i = 0;i<300001;i++){
        parent[i] = i;
    }

    int n;
    cin>>n;
    int a, b;
    for(int i = 0;i<n-2;i++){
        cin>>a>>b;
        mergeUnion(a,b);
    }

    for(int i = 2;i<=n;i++){
        if(findUnion(1) != findUnion(i)){
            cout<<1<<" "<<i<<endl;
            break;
        }
    }

    return 0;
}