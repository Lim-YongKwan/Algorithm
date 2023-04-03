#include <iostream>
#include <queue>

using namespace std;

int n,k;
pair<int, int> answer;
int visited[1000001];

struct compare{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second > b.second;
    }
};


void bfs(){

    priority_queue<pair<int, int>, vector<pair<int, int> >, compare> subin;
    visited[n] = 1;
    subin.push(make_pair(n,0));

    int flag = 0;

    while(subin.size() > 0){
        int curX = subin.top().first;
        int curT = subin.top().second;
        subin.pop();

        if(curX == k){
            answer.first = curT;
            answer.second++;
            flag = curT;
        }

        if(flag != 0 ){
            if(flag != curT){
                return;
            }
        }

        if(curX + 1 <= 100000){
            if(visited[curX + 1] == 0){
                visited[curX + 1] = curT + 1;
                subin.push(make_pair(curX + 1, curT + 1));
            }
            else if(visited[curX + 1] == curT + 1){
                subin.push(make_pair(curX + 1, curT + 1));
            }
        }

        if(curX - 1 >= 0){
            if(visited[curX - 1] == 0){
                visited[curX - 1] = curT + 1;
                subin.push(make_pair(curX - 1, curT + 1));
            }
            else if(visited[curX - 1] == curT + 1){
                subin.push(make_pair(curX - 1, curT + 1));
            }
        }

        if(curX * 2 <= 100000){
            if(visited[curX * 2] == 0){
                visited[curX * 2] = curT + 1;
                subin.push(make_pair(curX * 2, curT + 1));
            }
            else if(visited[curX * 2] == curT + 1){
                subin.push(make_pair(curX * 2, curT + 1));
            }
        }
    }


    return;
}

int main(){
    cin>>n>>k;

    bfs();

    cout<<answer.first<<endl;
    cout<<answer.second<<endl;

    return 0;
}