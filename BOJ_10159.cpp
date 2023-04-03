#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int objects[2001][2001];
int n, m;

void floid(){

    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(objects[i][k] + objects[k][j] == 2){
                    objects[i][j] = 1;
                }
            }
        }
    }

    return;
}

int main(){
    cin>>n>>m;

    // fill(object[0],object[n+1],1);

    for(int i = 0;i<m;i++){
        int a, b;
        cin>>a>>b;
        objects[a][b] = 1;
    }

    floid();

    int count = 0;
    for(int i = 1;i<=n;i++){
        count = 0;
        for(int j = 1;j<=n;j++){
            if(objects[i][j] == 1 || objects[j][i] == 1){
                count++;
            }
        }
        cout<<n - count - 1<<endl;
    }

    return 0;
}