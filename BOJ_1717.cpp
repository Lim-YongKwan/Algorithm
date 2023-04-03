#include <iostream>
#define endl "\n"
using namespace std;

int parent[1000001];

int find(int a){
    if(parent[a] == a){
        return a;
    }
    return parent[a] = find(parent[a]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b){
        return;
    }
    parent[b] = a;
}

bool isUnion(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b){
        return true;
    }
    return false;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 1;i<=1000000;i++){
        parent[i] = i;
    }

    int n,m;
    cin>>n>>m;

    for(int i = 0;i<m;i++){
        int isFind, a, b;
        cin>>isFind>>a>>b;
        if(isFind == 0){
            merge(a,b);
        }
        else if(isFind == 1){
            if(isUnion(a,b) == 0){
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
    }

    return 0;
}