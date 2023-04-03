#include<iostream>
#include <vector>

using namespace std;

int n,m;
int student[501][501];

void floid(){
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(student[i][k] + student[k][j] == 2){
                    student[i][j] = 1;
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
        student[a][b] = 1;
    }
    floid();

    int count = 0;
    int answer = 0;

    for(int i = 1;i<=n;i++){
        count = 0;
        for(int j = 1;j<=n;j++){
            if(student[i][j] == 1 || student[j][i] == 1){
                count++;
            }
        }
        if(count == n-1){
            answer++;
        }
    }
    cout<<answer<<endl;

    return 0;
}