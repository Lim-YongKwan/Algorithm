#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"

using namespace std;

vector<pair<int,int> > cctv;
vector<vector<int> > perm;
vector<int> recursive;
int board[10][10];
int board2[10][10];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;

void dfs(){
    if(recursive.size() == cctv.size()){
        perm.push_back(recursive);
        return;
    }

    for(int i = 0;i<4;i++){
        recursive.push_back(i);
        dfs();
        recursive.pop_back();
    }
    return;
}

//board배열을 graph배열과 일치시키자.
void boardEqual(){
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            board2[i][j] = board[i][j];
        }
    }
    return;
}

//board2 배열 내부에 0이 몇개 있는지 파악하자.
int boardCheck(){
    int answer = 0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(board2[i][j] == 0){
                answer++;
            }
        }
    }
    return answer;
}

bool OOP(int x,int y){
    return x<0 || x>= n || y <0 || y>=m;
}

void ups(int x, int y, int dir){
    dir %= 4;
    while(true){
        x += dx[dir];
        y += dy[dir];
        if(OOP(x,y) || board2[x][y] == 6){
            return;
        }
        if(board2[x][y] != 0){
            continue;
        }
        board2[x][y] = 7;
    }
    return;
}

int main(){
    cin>>n>>m;

    //0이 몇개 들어있는지 세는 변수.
    int total = 0;

    //입력 받자.
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>board[i][j];
            //만일 0이나 6이 아니라면 cctv이니 cctv에 좌표를 넣자.
            if(board[i][j] != 0 && board[i][j] != 6){
                cctv.push_back(make_pair(i,j));
            }
            //만일 0이라면 total에 총 몇개가 들어가는지 세자.
            if(board[i][j] == 0){
                total++;
            }
        }
    }

    //재귀를 이용해서 0~3까지 cctv.size()만큼 가져오자.(완탐으로 조합 만들기)
    dfs();

    for(int i = 0;i<perm.size();i++){
        boardEqual();

        for(int j = 0;j<cctv.size();j++){
            //dir는 perm[i][j] => perm은 순열이 들어있는 이차원 배열. perm[0] => {0,0,0}, perm[1] => {0,0,1} 식.
            int dir = perm[i][j];
            //x,y는 cctv[j]의 요소. j => cctv의 숫자.
            int x = cctv[j].first;
            int y = cctv[j].second;

            if(board[x][y] == 1){
                ups(x,y,dir);
            }
            else if(board[x][y] == 2){
                ups(x,y,dir);
                ups(x,y,dir+2);
            }
            else if(board[x][y] == 3){
                ups(x,y,dir);
                ups(x,y,dir+1);
            }
            else if(board[x][y] == 4){
                ups(x,y,dir);
                ups(x,y,dir+1);
                ups(x,y,dir+2);
            }
            else if(board[x][y] == 5){
                ups(x,y,dir);
                ups(x,y,dir+1);
                ups(x,y,dir+2);
                ups(x,y,dir+3);
            }
        }

        int val;
        val = boardCheck();
        total = min(total,val);
    }

    cout<<total<<endl;

    return 0;
}