#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <iostream>
#include <sstream>

using namespace std;

int split(string s){
    int answer = 0;
    string buffer;
    istringstream iss(s);
    char delimeter = ':';
    vector<string> result;
    while(getline(iss,buffer,delimeter)){
        result.push_back(buffer);        
    }
    answer = stoi(result[0]) * 60 + stoi(result[1]);
    return answer;
}

vector<string> solution(vector<vector<string> > plans){
    vector<string> answer;
    vector<pair<int, pair<string,int> > > times;
    for(int i = 0;i<plans.size();i++){
        pair<int,pair<string,int> > temp;
        temp.first = split(plans[i][1]);
        temp.second.first = plans[i][0];
        temp.second.second = stoi(plans[i][2]);
    }
    sort(times.begin(),times.end());
    stack<pair<int, pair<string,int> > > stop;
    
    int n = plans.size();

    for(int i = 0;i<n;i++){
        while(stop.size() > 0 && stop.top().first + stop.top().second.second <= times[i].first){
            int now = stop.top().first + stop.top().second.second;
            answer.push_back(stop.top().second.first);
            stop.pop();
            // if(stop.size() > 0){
            //     stop.top().first = now;
            // }
        }
        if(stop.size() > 0 && stop.top().first + stop.top().second.second > times[i].first){
            stop.top().second.second -= times[i].first - stop.top().first;
        }
        stop.push(times[i]);
    }
    while(stop.size() > 0){
        answer.push_back(stop.top().second.first);  
        stop.pop();
    }

    return answer;
}