#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int scale[100][100];

void floid(){

    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(scale[i][k] + scale[k][j] == 2){
                    scale[i][j] = 1;
                }
            }
        }
    }

    return;
}

int main(){
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        scale[a][b] = 1;
    }

    floid();

    int count = 0;
    int count_2 = 0;
    int answer = 0;
    int weight = 0;
    weight = (n+1) / 2;
    for(int i = 1;i<=n;i++){
        count = 0;
        count_2 = 0;
        for(int j = 1;j<=n;j++){
            if(j == i){ //자기 자신은 제외
                continue;
            }
            if(scale[i][j] == 1){ //자기보다 크고 작은지를 알기 위해서 2개의 조건으로 나누었다.
                count++;
            }
            if(scale[j][i] == 1){
                count_2++;
            }
        }
        if(count >= weight or count_2 >= weight){
            answer++;
        }
    }
    cout<<answer<<endl;
    return 0;
}