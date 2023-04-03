#include <iostream>
#include <stack>
#define endl "\n"

using namespace std;

int war[101][101];
int visit[101][101];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void DFS(stack<pair<int, int> > &soldier, int n, int m)
{
    if (soldier.size() <= 0){
        return;
    }

    if(visit[soldier.top().first][soldier.top().second] == 1){
        return;
    }

    cout<<soldier.top().first<<" "<<soldier.top().second<<endl;

    visit[soldier.top().first][soldier.top().second] = 1;

    pair<int,int> temp = soldier.top();
    soldier.pop();
    
    for (int i = 0; i < 4; i++)
    {
        if (temp.first + dx[i] <= 0 or temp.first + dx[i] > n
        or temp.second + dy[i] <= 0 or temp.second + dy[i] > m) {
            if (visit[temp.first + dx[i]][temp.second + dy[i]] == 0) {
                if(war[temp.first][temp.second] == war[temp.first + dx[i]][temp.second + dy[i]]){
                    visit[temp.first + dx[i]][temp.second + dy[i]] = 1;
                    cout<<"visit 오류 : "<<endl;
                    pair<int,int> temp2;
                    temp2.first = temp.first + dx[i];
                    temp2.second = temp.second + dy[i];
                    soldier.push(temp2);
                    DFS(soldier,n,m);
                }
            }
        }
    }
    return;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> war[i][j];
        }
    }
    
    stack<pair<int, int > > soldier;

    int total = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(visit[i][j] == 0){
                pair<int,int> temp;
                temp.first = i;
                temp.second = j;
                soldier.push(temp);
                DFS(soldier, n, m);
                total++;
            }
        }
    }
    cout<<endl;
    cout<<total<<endl;

    return 0;
}