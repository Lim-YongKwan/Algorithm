#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n,m;
int visited[1001][1001];
vector<vector<int> > donut;

void bfs(int a, int b){

    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    queue<pair<int, int> > jun;
    jun.push(make_pair(a,b));

    while(jun.size() > 0){
        int curX = jun.front().first;
        int curY = jun.front().second;
        jun.pop();

        for(int i = 0;i<4;i++){
            int nextX = curX + dx[i]; //다음번 x좌표
            int nextY = curY + dy[i]; //다음번 y좌표

            if(nextX >= 0 && nextX <n && nextY >=0 && nextY <m){ //만약 범위 내라면
                if(visited[nextX][nextY] == 0){ //visited를 방문했을때 0이라면
                    if(donut[nextX][nextY] == 0){ //donut이 0이라면
                        visited[nextX][nextY] = 1; //visited 체크
                        donut[nextX][nextY] = 1; //donut 체크
                        jun.push(make_pair(nextX,nextY)); //큐에 추가해주기.
                    }
                }
            }

            else if(nextX == -1){
                nextX = n - 1;
                if(visited[nextX][nextY] == 0){
                    if(donut[nextX][nextY] == 0){
                        visited[nextX][nextY] = 1;
                        donut[nextX][nextY] = 1;                        
                        jun.push(make_pair(nextX,nextY));
                    }
                }
            }
            else if(nextX == n){
                nextX = 0;
                if(visited[nextX][nextY] == 0){
                    if(donut[nextX][nextY] == 0){
                        visited[nextX][nextY] = 1;
                        donut[nextX][nextY] = 1;
                        jun.push(make_pair(nextX,nextY));
                    }
                }
            }
            else if(nextY == -1){
                nextY = m - 1;
                if(visited[nextX][nextY] == 0){
                    if(donut[nextX][nextY] == 0){                
                        visited[nextX][nextY] = 1;
                        donut[nextX][nextY] = 1;
                        jun.push(make_pair(nextX,nextY));
                    }
                }
            }
            else if(nextY == m){
                nextY = 0;
                if(visited[nextX][nextY] == 0){
                    if(donut[nextX][nextY] == 0){
                        visited[nextX][nextY] = 1;
                        donut[nextX][nextY] = 1;
                        jun.push(make_pair(nextX,nextY));
                    }
                }
            }
        }
    }

    return;
}

int main(){
    int answer = 0;
    cin>>n>>m;
    donut.resize(n,vector<int>(m,0));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>donut[i][j];
        }
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(donut[i][j] == 0){
                bfs(i,j);
                answer++;
            }
        }
    }
    cout<<answer<<endl;

    return 0;
}