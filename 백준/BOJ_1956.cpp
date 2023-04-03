#include<iostream>
#include<algorithm>
#include <vector>

using namespace std;

const int INF = 10000000;
int v,e;
int country[401][401];

void output(){
    cout<<"----output-----"<<endl;
    for(int i = 1;i<=v;i++){
        for(int j = 1;j<=v;j++){
            cout<<country[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}

void floid(){
    for(int k = 1;k<=v;k++){
        for(int i = 1;i<=v;i++){
            for(int j = 1;j<=v;j++){
                if(country[i][j] > country[i][k] + country[k][j]){
                    country[i][j] = country[i][k] + country[k][j];
                }
            }
        }
    }
    return;
}

void solve(){
    floid();
    int answer = INF;
    for(int i = 1;i<=v;i++){
        if(answer > country[i][i]){
            answer = country[i][i];
        }
    }

    cout<< ((answer == INF) ? -1 :answer )<<endl;
    
    return;
}

int main(){
    cin>>v>>e;
    for(int i = 0;i<=v;i++){
        fill(country[i],country[i]+v + 1,INF);
    }

    for(int i = 0;i<e;i++){
        int a,b,c;
        cin>>a>>b;
        cin>>c;
        country[a][b] = c;
    }

    solve();

    return 0;
}