#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 100000000;
int city[101][101];

void output(int n){
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cout<<city[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}

void floid(int n){

    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(city[i][j] > city[i][k] + city[k][j]){
                    city[i][j] = city[i][k] + city[k][j];
                }
            }
        }
        cout<<"-----"<<k<<"------"<<endl;
        output(n);
    }

    return;
}

int main(){
    int n;
    int m;
    cin>>n>>m;
    
    fill(city[0],city[n + 1],INF);

    for(int i = 0;i<m;i++){
        int a,b,temp;
        cin>>a>>b;
        cin>>temp;
        city[a][b] = min(city[a][b],temp);
    }

    for(int i = 1;i<=n;i++){
        city[i][i] = 0;
    }

    floid(n);

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(city[i][j] == INF){
                cout<<0<<" ";
                continue;
            }
            cout<<city[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}