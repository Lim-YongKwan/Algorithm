#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
queue<pair<int,int> > q;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[111][111];
int visited[111][111];
int n,m;

int bfs(pair<int,int> point ,pair<int,int> destination){
    //시작은 0
    int answer = 0;
    q.push(point);
    //시작한곳 방문표시해주자.
    visited[point.first][point.second] = 1;
    
    //시작 -> 레버까지와 레버 -> 종료까지를 돌리자.
    while(q.size() > 0){
        //현재 위치 x,y좌표
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();
        for(int i = 0;i<4;i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            //범위 안에 있다면
            if(nextX >= 0 and nextX < n and nextY >= 0 and nextY < m){
                //방문을 아직 하지 않았고 벽이 아니라면
                if(visited[nextX][nextY] == 0 and board[nextX][nextY] == 0){
                    //방문체크
                    visited[nextX][nextY] = 1;
                    //큐에 넣어주기
                    q.push(make_pair(nextX,nextY));
                    //시간 1초 지난거 표시해주기.
                    board[nextX][nextY] = board[curX][curY] + 1;
                    //도착한 지점이 목표지점이라면
                    if(nextX == destination.first && nextY == destination.second){
                        //도착한 곳까지 걸린시간 return
                        return board[nextX][nextY];
                    }
                }
            }
        }
    }
    
    return answer;
}

int solution(vector<string> maps) {
    int answer = 0;
    n = maps.size();
    m = maps[0].size();
    pair<int,int> startPoint;
    pair<int,int> leverPoint;
    pair<int,int> endPoint;
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(maps[i][j] == 'S'){
                //시작 지점.
                startPoint.first = i;
                startPoint.second = j;
            }
            else if(maps[i][j] == 'E'){
                //출구 -> 3은 출구.
                endPoint.first = i;
                endPoint.second = j;
            }
            else if(maps[i][j] == 'L'){
                //레버 지점. 2는 레버
                leverPoint.first = i;
                leverPoint.second = j;
            }
            else if(maps[i][j] == 'X'){
                //벽 -> -1은 통과 못함.
                board[i][j] = -1;
            }
            else if(maps[i][j] == 'O'){
                board[i][j] = 0;
            }
        }
    }
    answer += bfs(startPoint,leverPoint);
    if(answer == 0){
        return -1;
    }
    while(q.size() > 0){
        q.pop();
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            visited[i][j] = 0;
            if(board[i][j] == -1){
                continue;
            }
            board[i][j] = 0;
        }
    }
    int temp = 0;
    temp = bfs(leverPoint, endPoint);
    if(temp == 0){
        return -1;
    }
    answer += temp;
    
    return answer;
}