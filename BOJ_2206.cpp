#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
int board[1001][1001][2];
int visited[1001][1001][2];

void BFS(queue<pair<pair<int, int>, pair<int, int> > > person){

    int answer = 0;

    int dx[4] = {0,1,-1,0};
    int dy[4] = {1,0,0,-1};

    while(person.size() > 0){
        int curX = person.front().first.first;
        int curY = person.front().first.second;
        int curZ = person.front().second.first;
        int curCount = person.front().second.second;
        person.pop();

        // cout<<"curx : "<<curX;
        // cout<<" cury : "<<curY;
        // cout<<" curz : "<<curZ<<endl;

        if(curX == n && curY == m){
            cout<<curCount<<endl;
            return;
        }
        for(int i = 0;i<4;i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            int nextZ = curZ;
            if(nextX > 0 && nextX <=n && nextY > 0 && nextY <= m){
                if(nextZ == 0){ //아직 벽돌을 통과 안 했을때
                    if(board[nextX][nextY][0] == 0){ //벽돌이 아니다.
                        if(visited[nextX][nextY][nextZ] == 0){
                            person.push(make_pair(make_pair(nextX,nextY),make_pair(nextZ,curCount + 1 ) ));
                            visited[nextX][nextY][nextZ] = 1;
                        }
                    }
                    else if(board[nextX][nextY][0] == 1){ //벽돌을 만났다.
                        if(visited[nextX][nextY][nextZ] == 0){
                            person.push(make_pair(make_pair(nextX,nextY),make_pair( nextZ + 1, curCount + 1) )); // 1계단 위로 이동.
                            visited[nextX][nextY][nextZ] = 1;
                        }
                    }
                }
                else if(nextZ == 1){//벽돌을 통과함.
                    if(board[nextX][nextY][0] == 0){ //벽돌 아님.
                        if(visited[nextX][nextY][nextZ] == 0){
                            person.push(make_pair(make_pair(nextX,nextY),make_pair(nextZ, curCount + 1) ));
                            visited[nextX][nextY][nextZ] = 1;
                        }
                    }
                    //다음거가 벽돌이면 통과를 못하니 skip 하자.
                }
            }
        }
    }
    cout<<-1<<endl;
    return;
}

int main(){
    cin>>n>>m;

    char temp;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>temp;
            board[i + 1][j + 1][0] = temp - '0';
        }
    }
    //벽을 안 부수면 0
    //벽을 부수면 1

    queue<pair<pair<int, int>, pair<int, int> > > person;
    person.push(make_pair(make_pair(1,1),make_pair(0,1)));

    BFS(person);
    

    return 0;
}