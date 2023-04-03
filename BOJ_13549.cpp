#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int visited[200001];
int brother[200001];
int n,k;
int answer = 99999;

//0초 이동이 언제나 가장 빠르게 선행되어야 한다.

struct compare{
    bool operator()(pair<int ,int> a, pair<int, int> b){
        return a.second > b.second;
    }
};

void bfs(){

    priority_queue<pair<int, int>, vector<pair<int, int> >, compare > subin;

    subin.push(make_pair(n,0) );
    visited[n] = 1;
    brother[n] = 1;

    while(subin.size() > 0){
        int curX = subin.top().first;
        int curT = subin.top().second;
        subin.pop();

        if(curX == k){
            answer = curT;
            return;
        }

        if(curX + 1 <= 100000){
            //1. 방문을 하지 않았을 경우
            //2. 방문을 하였지만 방문했었을때보다 현재 경우가 더 작은 경우.

            if(visited[curX + 1] == 0){
                visited[curX + 1] = 1;
                brother[curX + 1] = curT + 1;
                subin.push(make_pair(curX + 1, curT + 1));
            }
            else if(visited[curX + 1] == 1){
                if(brother[curX + 1] > curT + 1){
                    brother[curX + 1] = curT + 1;
                    subin.push(make_pair(curX + 1, curT + 1));
                }
            }
        }

        if(curX - 1 >= 0){
            if(visited[curX - 1] == 0){
                visited[curX - 1 ] = 1;
                brother[curX - 1] = curT + 1;
                subin.push(make_pair(curX - 1 , curT + 1));
            }
            else if(visited[curX - 1] == 1){
                if(brother[curX - 1] > curT + 1){
                    brother[curX - 1] = curT + 1;
                    subin.push(make_pair(curX - 1, curT + 1));
                }
            }
        }

        if(curX * 2 <= 100000){
            
            if(visited[curX * 2] == 0){
                visited[curX * 2] = 1;
                brother[curX * 2] = curT;
                subin.push(make_pair(curX * 2, curT));
            }
            else if(visited[curX * 2] == 1){
                if(brother[curX * 2] > curT){
                    brother[curX * 2] = curT;
                    subin.push(make_pair(curX * 2, curT));
                }
            }
        }
    }

    return;
}

int main(){
    cin>>n>>k;
    
    bfs();

    cout<<answer<<endl;

    return 0;
}