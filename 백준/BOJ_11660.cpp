#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;

long long board[1025][1025];

long long total_sum(pair<int, int> start, pair<int, int> end){
    long long answer = 0;
    int x1 = start.first;
    int y1 = start.second;
    int x2 = end.first;
    int y2 = end.second;

    answer = board[x2][y2] + board[x1 - 1][y1 - 1] - board[x1 - 1][y2] - board[x2][y1 - 1];

    return answer;
}

int main(){
    int n,m;
    cin>>n>>m;

    long long total = 0;

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            cin>>board[i][j];
        }
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            board[i][j] = board[i][j - 1] + board[i - 1][j] - board[i - 1][j - 1] + board[i][j];
        }
    }

    pair<int, int> start;
    pair<int, int> end;
    vector<long long> answer;

    for(int i = 0;i<m;i++){
        cin>>start.first;
        cin>>start.second;
        cin>>end.first;
        cin>>end.second;

        answer.push_back(total_sum(start,end));
    }

    for(int i = 0;i<answer.size();i++){
        cout<<answer[i]<<endl;
    }

    return 0;
}