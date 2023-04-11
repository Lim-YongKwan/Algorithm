#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[20][20];
int n,m;

struct bead{
    int first;
    int second;
    int cnt;
};

queue<pair<int,int> > red;
queue<pair<int,int> > blue;

bool reachWall(int x, int y){
    return x<0 or x>=n or y<0 or y>=m;
}

void straight(int x, int y, int dir){
    while(true){
        x += dx[dir];
        y += dy[dir];
        if(board[x][y] == 1){
            return;
        }
        //만일 벽에 도달했다면
        if(board[x][y] == -1 or reachWall(x,y)){
            x -= dx[dir];
            y -= dx[dir];
            return;
        }
    }
    return;
}

void bfs(){
    return;
}

int main(){
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char temp;
            cin>>temp;
            if(temp == '#'){
                //벽은 -1
                board[i][j] = -1;
            }
            else if(temp == 'O'){
                //골인지점.
                board[i][j] = 1;
            }
            else if(temp == 'R'){
                red.push(make_pair(i,j));
            }
            else if(temp == 'B'){
                blue.push(make_pair(i,j));                
            }
        }
    }


    return 0;
}