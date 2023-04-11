#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int board[20][20];
int visitedRed[20][20];
int visitedBlue[20][20];
//구슬 2개가 이동한 곳 체크해줄 변수.
int n,m;
int lastAns;
//좌표, 거리값 저장할 각 구슬별 queue
queue<pair<pair<int, int>,int> > blue;
queue<pair<pair<int, int>,int> > red;

bool oop(int x, int y){
    return x <0 or x>= n or y <0 or y>= m;
}

pair<pair<int, int>,int> ups(int x, int y, int dir){
    //answer에 저장될 거는 좌표 위치 x, y 와 이동한 거리 count
    pair<pair<int, int>,int> answer;
    int count = 0;
    while(true){
        count++;
        x += dx[dir];
        y += dy[dir];
        //골인지점에 도착한다면
        if(board[x][y] == 1){
            answer.first.first = x;
            answer.first.second = y;
            answer.second = count;
            return answer;
        }
        //만일 벽에 부딪힌다면
        else if(oop(x,y) || board[x][y] == -1){
            //해당 위치에서 1뒤로 움직이고 return
            answer.first.first =  x - dx[dir];
            answer.first.second = y - dy[dir];
            answer.second = count - 1;
            return answer;
        }
    }
    return answer;
}

void bfs(){
    int cnt = 0;
    int redCost = 0;
    int blueCost = 0;
    //10번까지 움직여보자.
    while(redCost < 9 or blueCost < 9){
        pair<pair<int, int>,int> curRed = red.front();
        pair<pair<int, int>,int> curBlue = blue.front();
        redCost = red.front().second;
        blueCost = blue.front().second;
        red.pop();
        blue.pop();
        for(int i = 0;i<4;i++){
            pair<pair<int, int>,int> nextRed;
            nextRed = ups(curRed.first.first, curRed.first.second, i);
            pair<pair<int, int>,int> nextBlue;
            nextBlue = ups(curBlue.first.first, curBlue.first.second, i);

            //blue가 넣어지는 경우라면 다음 케이스로 넘기자.
            if(board[nextBlue.first.first][nextBlue.first.second] == 1){
                // cout<<"out : "<<endl;
                continue;
            }
            //정답이 나왔다면 바로 종료.
            if(board[nextRed.first.first][nextRed.first.second] == 1){
                // cout<<"answer : "<<endl;
                lastAns = 1;
                return;
            }

            //방향은 알고 있다. 즉, 둘의 위치가 겹친다면 
            if(nextRed.first.first == nextBlue.first.first && nextRed.first.second == nextBlue.first.second){
                //Red 구슬의 이동이 더 크다면
                if(nextRed.second > nextBlue.second){
                    //빨간구슬을 이전 위치로 옮기자.
                    nextRed.first.first -= dx[i];
                    nextRed.first.second -= dy[i];
                }
                //파란구슬도 마찬가지 작업을 해주자.
                else if(nextBlue.second >= nextRed.second){
                    nextBlue.first.first -= dx[i];
                    nextBlue.first.second -= dy[i];
                }
            }

            // red.push(make_pair(make_pair(nextRed.first.first, nextRed.first.second),redCost + 1));
            // blue.push(make_pair(make_pair(nextBlue.first.first, nextBlue.first.second),blueCost + 1));

            // cout<<"next Red : "<<nextRed.first.first<<" "<<nextRed.first.second<<endl;
            // cout<<"next Blue : "<<nextBlue.first.first<<" "<<nextBlue.first.second<<endl;
            //만일 방문을 하지 않았던 곳이라면
            if(visitedRed[nextRed.first.first][nextRed.first.second] == 0){
                //방문체크
                visitedRed[nextRed.first.first][nextRed.first.second] = 1;
                //현재좌표, 시도횟수 + 1 저장.
                red.push(make_pair(make_pair(nextRed.first.first, nextRed.first.second),redCost + 1));
            }
            if(visitedBlue[nextBlue.first.first][nextBlue.first.second] == 0){
                visitedBlue[nextBlue.first.first][nextBlue.first.second] = 1;
                blue.push(make_pair(make_pair(nextBlue.first.first, nextBlue.first.second),blueCost + 1));
            }
        }
        //이번에는 움직이지 못했지만 다음번에는 움직일 수 있는 경우가 생길 수 있다.
        //해당 경우를 위해서 횟수만 올린다음에 큐에 다시 넣어주자.
        if(red.size() == 0){
            red.push(make_pair(make_pair(curRed.first.first,curRed.first.second),redCost + 1));
        }
        if(blue.size() == 0){
            blue.push(make_pair(make_pair(curBlue.first.first,curBlue.first.second), blueCost + 1));
        }
    }
    return;
}


int main(){
    int answer = 0;
    cin>>n>>m;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char temp;
            cin>>temp;
            if(temp == '#'){
                board[i][j] = -1;
            }
            else if(temp == 'B'){
                blue.push(make_pair(make_pair(i,j),0));
                visitedBlue[i][j] = 1;
            }
            else if(temp == 'R'){
                red.push(make_pair(make_pair(i,j),0));
                visitedRed[i][j] = 1;
            }
            else if(temp == 'O'){
                board[i][j] = 1;
            }
        }
    }

    bfs();

    cout<<(lastAns ? 1 : 0)<<endl;
    return 0;
}