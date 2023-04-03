#include<iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#define endl "\n"

using namespace std;

int visited[26];
int answer;
int r,c;

void dfs(int x, int y,int count, vector<vector<char> > destination) {

    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};

    answer = max(answer, count);

    for(int i = 0;i<4;i++){
        int nextX = x + dx[i];
        int nextY = y + dy[i];
        if(nextX < r && nextX >= 0 && nextY < c && nextY >= 0){
            if(visited[destination[nextX][nextY] - 'A'] == 0){
                visited[destination[nextX][nextY] - 'A'] = 1;
                dfs(nextX,nextY,count + 1,destination);
                visited[destination[nextX][nextY] - 'A'] = 0;           
            }
        }
    }
}

int main(int argc, char** argv)
{
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        answer = 0;
        cin>>r>>c;
        for(int i = 0;i<26;i++){
            visited[i] = 0;
        }
        vector<vector<char> > destination;
        destination.resize(r,vector<char>(c,0));

        for(int i = 0;i<r;i++){
            for(int j = 0;j<c;j++){
                cin>>destination[i][j];
            }
        }
        visited[destination[0][0] - 'A'] = 1;
        dfs(0,0,1,destination);

        cout<<"#"<<test_case<<" "<<answer<<endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}