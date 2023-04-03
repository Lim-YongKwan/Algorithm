#include <iostream>
#include <vector>

using namespace std;

int board[101][101];

void floid(int n) {

    for(int k = 1;k<=n;k++) {
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(i == j){
                    board[i][j] = 0;
                }
                if(board[i][j] > board[i][k] + board[k][j]){
                    board[i][j] = board[i][k] + board[k][j];
                }
            }
        }
    }

    return;
}

void output(int n){
    for(int i = 1;i<=n;i++){
        for(int j =1;j<=n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}

int main(){
    int n,m;
    cin>>n>>m;
    
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=n;j++){
            board[i][j] = 10000000;
        }
    }

    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        board[a][b] = 1;
        board[b][a] = 1;
    }

    floid(n);

    int answer = 0;
    int temp = 1000000000;
    int temp_2 = 0;

    for(int i = 1;i<=n;i++){
        temp_2 = 0;
        for(int j = 1;j<=n;j++){
            temp_2 += board[i][j];
        }
        if(temp > temp_2){
            temp = temp_2;
            answer = i;
        }
    }

    cout<<answer<<endl;

    return 0;
}