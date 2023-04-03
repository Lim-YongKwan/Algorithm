#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define endl "\n"
#define INF 2000000000

using namespace std;

int graph[127][127];
int dijkstra[127][127];
int visited[127][127];

void solve(int vertex,int count){
    //다익스트라 배열[0][0] 은 graph[0][0]의 값 입력.
    dijkstra[0][0] = graph[0][0];
    //[0][0] 방문 체크. 
    visited[0][0] = 1;
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};

    //pq에 [0][0]값(거리), pair(x,y) 입력하자.
    priority_queue<pair<int,pair<int, int> >,vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
    pq.push(make_pair(graph[0][0],make_pair(0,0)));

    //0,0에서 n - 1, n - 1까지 이동을 시키자.
    //다익스트라에서 썼던 pq(거리,위치) 방식과 bfs에서 사용했었던 visited체크와 dx[4],dy[4]를 사용해 4방향을 돌아가는 방식을 사용하자.
    while(pq.size() > 0){
        int curX = pq.top().second.first;
        int curY = pq.top().second.second;
        int curCost = pq.top().first;
        pq.pop();

        if(dijkstra[curX][curY] < curCost){
            continue;
        }

        for(int i = 0;i<4;i++){
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];
            if(nextX >= 0 || nextX < vertex || nextY >= 0 || nextY < vertex){
                if(visited[nextX][nextY] == 0){
                    int nextCost = graph[nextX][nextY];

                    if(dijkstra[nextX][nextY] <= curCost + nextCost){
                        continue;
                    }

                    dijkstra[nextX][nextY] = curCost + nextCost;
                    pq.push(make_pair(nextCost + curCost,make_pair(nextX,nextY)));
                    visited[nextX][nextY] = 1;
                }
            }
        }
    }

    cout<<"Problem "<<count<<": "<<dijkstra[vertex - 1][vertex - 1]<<endl;

    return;
}

int main(){

    int n;
    int count = 0;
    while(cin>>n){
        count++;
        if(n == 0){
            break;
        }
        //graph배열에 증가되는 값 입력.
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cin>>graph[i][j];
            }
        }
        //dijkstra 배열에 모든 값을 20억 즉, 임의의 큰 값으로 입력.
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                dijkstra[i][j] = INF;
            }
        }
        //visited 배열 모두 0으로 초기화 => 아직 모든 곳을 가보지 못했다는 의미.
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                visited[i][j] = 0;
            }
        }

        solve(n,count);
    }
    return 0;
}