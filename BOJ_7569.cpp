#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

queue<pair<int, pair<int, int> > > q;
int tomato[101][101][101];
int visited[101][101][101];
int n,m,h;
int total;

void bfs(){

    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int dh[2] = {1,-1};

    while(q.size() > 0){
        int curH = q.front().first;
        int curX = q.front().second.first;
        int curY = q.front().second.second;
        q.pop();

        //2차원에서 하듯이 똑같이 해주자.
        for(int i = 0;i<4;i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if(nextX >= 0 && nextX <n && nextY >= 0 & nextY <m){
                if(visited[nextX][nextY][curH] == 0){
                    if(tomato[nextX][nextY][curH] == 0){
                        tomato[nextX][nextY][curH] = tomato[curX][curY][curH] + 1;
                        visited[nextX][nextY][curH] = 1;
                        q.push(make_pair(curH,make_pair(nextX,nextY)));
                    }
                }
            }
        }
        //높이 양쪽이 되니 2차원에서 했던걸 응용해서 위아래를 추가하자.
        for(int i = 0;i<2;i++){
            int nextH = curH + dh[i];
            if(nextH >= 0 && nextH < h){
                if(visited[curX][curY][nextH] == 0){
                    if(tomato[curX][curY][nextH] == 0){
                        tomato[curX][curY][nextH] = tomato[curX][curY][curH] + 1;
                        visited[curX][curY][nextH] = 1;
                        q.push(make_pair(nextH,make_pair(curX,curY)));
                    }
                }
            }
        }
    }

    return;
}

int main(){
    cin>>m>>n>>h;
    for(int l = 0;l<h;l++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>tomato[i][j][l];
                if(tomato[i][j][l] == 0){
                    total++;
                }
                else if(tomato[i][j][l] == 1){
                    q.push(make_pair(l,make_pair(i,j)));
                }
            }
        }
    }
    if(total == 0){
        cout<<0<<endl;
        return 0;
    }
    bfs();
    
    int answer = 0;

    for(int l = 0;l<h;l++){
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(tomato[i][j][l] == 0){
                    cout<<-1<<endl;
                    return 0;
                }
                answer = max(answer, tomato[i][j][l]);
            }
        }
    }
    cout<<answer - 1<<endl;

    return 0;
}