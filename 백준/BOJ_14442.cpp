#include <iostream>
#include <queue>

using namespace std;

int n,m,k;
int board[1001][1001][11];
int visited[1001][1001][11];

void BFS(queue<pair<pair<int, int>, pair<int, int> > > locate){
    
    int dx[4] = {0,0,1,-1};
    int dy[4] = {1,-1,0,0};

    while(locate.size() > 0) {
        int curX = locate.front().first.first;
        int curY = locate.front().first.second;
        int curZ = locate.front().second.first;
        int curCount = locate.front().second.second;
        locate.pop();
        if(curX == n && curY == m){
            cout<<curCount<<endl;
            return;
        }
        for(int i = 0;i<4;i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if(nextX > 0 && nextX <=n && nextY > 0 && nextY <=m){ //범위 내부라면
                if(curZ < k){//만일 아직 통과한 벽돌 숫자가 한계 이하라면
                    if(board[nextX][nextY][0] == 1){
                        if(visited[nextX][nextY][curZ + 1] == 0){
                            locate.push(make_pair(make_pair(nextX,nextY),make_pair(curZ + 1, curCount + 1)));
                            visited[nextX][nextY][curZ + 1] = 1;
                        }
                    }
                    else if(board[nextX][nextY][0] == 0 ){
                        if(visited[nextX][nextY][curZ] == 0){
                            locate.push(make_pair(make_pair(nextX,nextY),make_pair(curZ, curCount + 1)));
                            visited[nextX][nextY][curZ] = 1;
                        }
                    }
                }
                else if(curZ == k){
                    if(board[nextX][nextY][0] == 0 ){
                        if(visited[nextX][nextY][curZ] == 0){
                            locate.push(make_pair(make_pair(nextX,nextY),make_pair(curZ, curCount + 1)));
                            visited[nextX][nextY][curZ] = 1;
                        }
                    }
                }
            }
        }
    }
    cout<<-1<<endl;
    return;
}

int main() {
    cin>>n>>m>>k;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char temp;
            cin>>temp;
            board[i + 1][j + 1][0] = temp - '0';
        }
    }

    queue<pair<pair<int, int>, pair<int, int> > > locate;
    locate.push(make_pair(make_pair(1,1),make_pair(0,1)));

    BFS(locate);

    return 0;
}