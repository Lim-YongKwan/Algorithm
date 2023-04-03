#include <string>
#include <vector>
#include <stack>
#include<algorithm>
#include <iostream>

using namespace std;

void bfs(vector<vector<int>>& town, stack<pair<int,int>> fire, stack<pair<int,int>> ice, int n, int m){
    
    int dict[10][3] = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1}};

    // while(fire.size()>0){
    //     vector<vector<bool>> visit(n+1, vector<bool>(n+1,0));
    //     int count = m;
    //     stack<pair<int, int> > high;
    //     high.push(fire.top());
    //     fire.pop();
    //     visit[high.top().first][high.top().second] = 1;


    //     while(count>0){
    //         pair<int ,int> temp;
    //         temp = high.top();
    //         high.pop();
    //         for(int i = 0;i<8;i++){
    //             if(temp.first + dict[i][0] < n and temp.second + dict[i][1] < n and temp.first + dict[i][0] >= 0 and temp.second + dict[i][1] >= 0){
    //                 if(visit[temp.first + dict[i][0]][temp.second + dict[i][1]] == 0){
    //                     town[temp.first+dict[i][0]][temp.second + dict[i][1]] += count;
    //                     visit[temp.first + dict[i][0]][temp.second + dict[i][1]] = 1;
    //                     high.push(make_pair(temp.first + dict[i][0],temp.second + dict[i][1]));
    //                 }
    //             }
    //         }            
    //         count--;
    //     }
    // }

    while(ice.size()>0){
        vector<vector<bool>> visit(n, vector<bool>(n,0));
        vector<vector<long long>> temp_town(n, vector<long long>(n,0));
        int count = m;
        stack<pair<int, int> > low;
        low.push(ice.top());
        ice.pop();
        visit[low.top().first][low.top().second] = 1;
        temp_town[low.top().first][low.top().second] -= m;
        pair<int ,int> temp;

        while(true){
            temp = low.top();
            low.pop();
            if(temp_town[temp.first][temp.second] == 0){
                break;
            }
            for(int i = 0;i<4;i++){
                if(temp.first + dict[i][0] < n and temp.second + dict[i][1] < n and temp.first + dict[i][0] >= 0 and temp.second + dict[i][1] >= 0){
                    if(visit[temp.first + dict[i][0]][temp.second + dict[i][1]] == 0){
                        temp_town[temp.first+dict[i][0]][temp.second + dict[i][1]] += temp_town[temp.first][temp.second];
                        visit[temp.first + dict[i][0]][temp.second + dict[i][1]] = 1;
                        low.push(make_pair(temp.first + dict[i][0],temp.second + dict[i][1]));
                    }
                }
            }
        }
        for(int i = 0;i<town.size();i++){
            for(int j = 0;j<town[i].size();j++){
                town[i][j] += temp_town[i][j];
            }
    }
    }

}

vector<vector<long long>> solution(int n, int m, vector<vector<int>> fires, vector<vector<int>> ices) {
    vector<vector<long long>> answer;

    vector<vector<int>> town(n, vector<int>(n, 0));
    stack<pair<int,int>> fire;
    stack<pair<int,int>> ice;

    for(int i = 0;i<fires.size();i++){
        int a = fires[i][0] -1;
        int b = fires[i][1] -1;
        fire.push(make_pair(a,b));
        town[a][b] = m;
    }

    for(int i = 0;i<ices.size();i++){   
        int a = ices[i][0] -1 ;
        int b = ices[i][1] -1 ;
        ice.push(make_pair(a,b));
        town[a][b] -= m;
    }

    bfs(town, fire, ice, n , m);

    for(int i = 0;i<town.size();i++){
        for(int j = 0;j<town[i].size();j++){
            cout<<town[i][j]<<" ";
        }
        cout<<endl;
    }

    return answer;
}