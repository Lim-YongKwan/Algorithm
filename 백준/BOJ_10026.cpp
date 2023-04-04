#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int visited[110][110];
char board[110][110];
int n;

void bfs(int x, int y){
    //1. R하고 G 구분 못함.
    //2. 모두 구분함.

    queue<pair<int, int> > q;
    q.push(make_pair(x,y));

    while(q.size() > 0 ){
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for(int i = 0;i<4;i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if(nextX >= 0 and nextX < n and nextY >= 0 and nextY < n){
                if(visited[nextX][nextY] == 0){
                    if(board[nextX][nextY] == board[curX][curY]){
                        visited[nextX][nextY] = 1;
                        q.push(make_pair(nextX,nextY));
                    }
                }
            }
        }
    }
    return;
}

int operateBFS(){
    int answer = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(visited[i][j] == 0){
                bfs(i,j);
                answer++;
            }
        }
    }
    return answer;
}

int main(){
    cin>>n;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>board[i][j];
        }
    }

    int answer = 0;
    int secondAnswer = 0;

    answer = operateBFS();

    //visited 초기화 && boad에서 적녹색약이 구별을 못하니 Red를 모두 Green으로 바꾸자.ㄴ
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            visited[i][j] = 0;
            if(board[i][j] == 'R'){
                board[i][j] = 'G';
            }
        }
    }

    //다시 한번 bfs돌리기.
    secondAnswer = operateBFS();
    
    cout<<answer<<" "<<secondAnswer<<endl;


    return 0;
}