#include <iostream>

using namespace std;

const int INF = 1000000;
int n;
int graph[101][101];

void floid(){
    for(int k = 0;k<n;k++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(graph[i][k] + graph[k][j] == 2){
                    graph[i][j] = 1;
                }
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>graph[i][j];
        }
    }
    
    floid();

    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}