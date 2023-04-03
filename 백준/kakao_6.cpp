#include <string>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";

    vector<vector<string> > grid(n,vector<string>(m,""));

    int dict[4][2] = {{1,0},{0,-1},{0,1},{-1,0}};

    queue<pair<int, int> > start;
    start.push(make_pair(x-1,y-1));
    grid[x-1][y-1] = "";

    while(start.size()>0){
        //거리 = 현재 배열의 길이로 판단.
        //만일 거리가 k가 되거나 r,c 의 위치에 도달한다면 탈출.
        //l : 왼쪾 , r : 오른쪾 , u : 위쪽 , d : 아래쪾
        //사전순이기 때문에 d l r u 순으로 가자.
        pair<int,int> temp;
        temp = start.front();
        start.pop();
        if(grid[temp.first][temp.second].size() > k){
            break;
        }
        if(grid[r-1][c-1].size() > k){
            break;
        }

        for(int i = 0;i<4;i++){
            if(temp.first + dict[i][0] >= n or temp.second + dict[i][1] >= m or temp.first + dict[i][0] < 0 or temp.second + dict[i][1] < 0){
                continue;
            }
            
            start.push(make_pair(temp.first + dict[i][0],temp.second + dict[i][1]));

            if(i == 0){
                grid[temp.first + dict[i][0]][temp.second + dict[i][1]] = "d" + grid[temp.first][temp.second];
            }
            else if(i == 1){
                grid[temp.first + dict[i][0]][temp.second + dict[i][1]] = "l" + grid[temp.first][temp.second];
            }
            else if(i == 2){
                grid[temp.first + dict[i][0]][temp.second + dict[i][1]] = "r" + grid[temp.first][temp.second];
            }
            else if(i==3){
                grid[temp.first + dict[i][0]][temp.second + dict[i][1]] =  "u" + grid[temp.first][temp.second];
            }
        }
    }

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    if(grid[r-1][c-1].size() != k){
        answer = "impossible";
    }
    else{
        answer += grid[r-1][c-1];
    }

    return answer;
}