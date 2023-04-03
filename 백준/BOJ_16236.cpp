#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n;
int fish[10];

int sum_bait(int n){
    int answer = 0;
    for(int i = 0;i<n;i++){
        answer += fish[i];
    }
    return answer;
}

void BFS(queue<pair<pair<int,int> ,pair<int, int> > > shark, vector<vector<int> > space){
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};

    //상어에는 x , y 좌표와 현재 크기 먹고 있는 물고기 수가 저장되어 있다.

    vector<vector<int> > visit(n,vector<int>(n,0));
    
    while(shark.size()>0){

        int shark_repeat = shark.size();
        while(shark_repeat--){

            int curx = shark.front().first.first;
            int cury = shark.front().first.second;
            int shark_size = shark.front().second.first;
            int shark_count = shark.front().second.second;
            shark.pop();

            for(int i = 0;i<4;i++){
                int nextx = curx + dx[i];
                int nexty = cury + dy[i];
                if(nextx < 0 or nextx>= n or nexty < 0 or nexty >= n){
                    continue;
                }
                else{
                    if(visit[nextx][nexty] == 0){
                        visit[nextx][nexty] = 1;
                        if(space[nextx][nexty] <= shark_size){
                            space[nextx][nexty] = 0;
                            shark_count++;
                            if(shark_size == shark_count){
                                shark_count = 0;
                                shark_size++;
                                shark.push(make_pair(make_pair(nextx,nexty),make_pair(shark_size + 1,0)));
                            }
                        }
                    }
                }
            }
        }
    }
    return;
}

int main(){
    cin>>n;
    vector<vector<int> > space(n, vector<int>(n,0));
    queue<pair<pair<int,int>, pair<int,int > > > shark;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin>>space[i][j];
            if(space[i][j] == 9){
                pair<pair<int,int>, pair<int,int> > temp;
                temp.first.first = i;
                temp.first.second = j;
                temp.second.first = 2;
                temp.second.second = 0;
                shark.push(temp);
            }
            else if(space[i][j] > 0){
                fish[space[i][j]]++;
            }
        }
    }

    cout<<sum_bait(shark.front().second.first)<<endl;

    if(sum_bait(shark.front().second.first)){
        BFS(shark,space);
    }

    return 0;
}