#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

//events의 길이 => 8. 즉, 완탐으로 풀수가 있다.

vector<pair<pair<int,int>,char> > costs;
int visited[20];
int max_total = 0;

vector<string> split(string s, char delimeter){
    vector<string> answer;
    istringstream iss(s);
    string buffer;

    while(getline(iss,buffer,delimeter)){
        answer.push_back(buffer);
    }

    return answer;
}

void backTrack(int now, int money,int n){

    if(money < 0){
        return;
    }
    max_total = max(now,max_total);
    if(money == 0){
        return;
    }

    if(n == costs.size()){
        return;
    }

    for(int i = 0;i<costs.size();i++){
        if(visited[i] == 0){
            visited[i] = 1;
            if(costs[i].second == 'x'){
                backTrack(now * costs[i].first.second, money - costs[i].first.first,n + 1);
            }
            else if(costs[i].second == '+'){
                backTrack(now + costs[i].first.second, money - costs[i].first.first,n + 1);
            }
            visited[i] = 0;
        }
    }

    return;
}

int solution(int n, int money, vector<string> events) {
    int answer = 0;

    vector<vector<string> > cost;
    for(int i = 0;i<events.size();i++){
        vector<string> temp;
        temp = split(events[i],' ');
        cost.push_back(temp);
    }

    for(int i = 0;i<cost.size();i++){
        pair<pair<int,int>,char> temp;
        temp.first.first = stoi(cost[i][0]);
        temp.second = cost[i][1][0];
        string temps = "";
        for(int j = 1;j<cost[i][1].size();j++){
            temps += cost[i][1][j];
        }
        temp.first.second = stoi(temps);
        costs.push_back(temp);
    }

    // for(int i = 0;i<costs.size();i++){
    //     cout<<costs[i].first.first<<" "<<costs[i].first.second<<" "<<costs[i].second<<endl;
    // }

    backTrack(n,money,0);
    answer = max_total;


    return answer;
}