#include <iostream>

using namespace std;

int city[201][201];
int parent[201];

int set_find(int a){
    if(parent[a] == a){
        return a;
    }
    return parent[a] = set_find(parent[a]);
}

void mergeUnion(int a, int b){
    a = set_find(a);
    b = set_find(b);
    if(a == b){
        return;
    }
    parent[b] = a;
    return;
}

int main(){
    int n,m;
    cin>>n>>m;

    for(int i = 0;i<201;i++){
        parent[i] = i;
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>city[i][j];
            if(city[i][j] == 1){
                mergeUnion(i,j);
            }
        }
    }

    int city;
    cin>>city;
    city = set_find(city - 1);
    string answer = "YES";

    for(int i = 0; i< m - 1;i++){
        int a;
        cin>>a;
        if(set_find(a - 1) != city){
            answer = "NO";
        }
    }

    cout<<answer<<endl;


    return 0;
}