#include<iostream>
#include<queue>
#include<vector>
#define endl "\n"

using namespace std;

int fire_visit[1001][1001];

void fire_bfs(vector<vector<char> >& maze, queue<pair<int, int> > fire, int r, int c){
    fire_visit[fire.front().first][fire.front().second] = 0;
    int dict[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

    while(fire.size()>0){
        int fire_size = fire.size();
        while(fire_size--){
            
            int fire_x = fire.front().first;
            int fire_y = fire.front().second;
            fire.pop();

            for(int i = 0;i<4;i++){
                int next_x = fire_x + dict[i][0];
                int next_y = fire_y + dict[i][1];

                if(next_x >= 0 and next_x < r and next_y >= 0 and next_y < c){
                    if(maze[next_x][next_y] != '#'){
                        if(fire_visit[next_x][next_y] > fire_visit[fire_x][fire_y] + 1){
                            fire_visit[next_x][next_y] = fire_visit[fire_x][fire_y] + 1;
                            fire.push(make_pair(next_x, next_y));
                        }
                    }
                }
            }
        }
    }
    return;
}

int bfs(vector<vector<char> > maze, queue<pair<pair<int, int>, int > > jihhon, int r, int c){
    vector<vector<int> > visit(r, vector<int>(c, 0));
    visit[jihhon.front().first.first][jihhon.front().first.second] = 1;

    int dict[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};

    while(jihhon.size()>0){

            // cout<<"jihoon_x : "<<jihhon.front().first.first<<endl;
            // cout<<"jihoon_y ; "<<jihhon.front().first.second<<endl;

            int jihoon_x = jihhon.front().first.first;
            int jihoon_y = jihhon.front().first.second;
            int jihoon_num = jihhon.front().second;
            jihhon.pop();

            if(jihoon_x == 0 or jihoon_x == r-1 or jihoon_y == 0 or jihoon_y == c-1){
                return jihoon_num + 1;
            }

            for(int i = 0;i<4;i++){
                int next_x = jihoon_x + dict[i][0];
                int next_y = jihoon_y + dict[i][1];

            if(next_x >= 0 and next_x <r and next_y >= 0 and next_y < c){
                if(visit[next_x][next_y] == 0){
                    if(fire_visit[next_x][next_y] > jihoon_num + 1 and maze[next_x][next_y] != '#'){
                        visit[next_x][next_y] = 1;
                        jihhon.push(make_pair(make_pair(next_x, next_y), jihoon_num + 1));
                    }
                }
            }
        }        
    }

    return 0 ;
}

int main(){
    
    int r, c;
    cin>>r>>c;

    vector<vector<char> > maze(r, vector<char>(c,0));
    queue<pair<pair<int, int>,int> > jihoon;
    queue<pair<int ,int> > fire;

    for(int i = 0;i<r;i++){
        for(int j = 0;j<c;j++){
            cin>>maze[i][j];
            if(maze[i][j] == 'J'){
                jihoon.push(make_pair(make_pair(i,j),0));
            }
            else if(maze[i][j] == 'F'){
                fire.push(make_pair(i,j));
                fire_visit[i][j] = 0;
            }
            else{
                fire_visit[i][j] = 9999;
            }
        }
    }

    if(fire.size() > 0){
        fire_bfs(maze,fire,r,c);
    }
    
    int answer = bfs(maze,jihoon,r,c);

    if(answer > 0){
        cout<<answer<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }

    return 0;
}