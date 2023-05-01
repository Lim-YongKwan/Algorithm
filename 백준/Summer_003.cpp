#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

//이분탐색 문제.

vector<vector<int> > task;

bool binary(long long mid){
    // cout<<"----------"<<mid<<"------------"<<endl;
    bool answer = true;
    long long count = mid;
    //마감일을 기준으로 하는 pq;
    priority_queue<pair<int, int>,vector<pair<int,int> >, greater<pair<int,int> > > pq;

    int cnt = 0;

    for(int i = 0;i<=365;i++){
        count = mid;
        while(pq.size() > 0 && count > 0){
            // cout<<"i : "<<i<<" ";
            // cout<<"pq : "<<pq.size()<<" ";
            // cout<<pq.top().first<<" "<<pq.top().second<<endl;
            if(count >= pq.top().second){
                count -= pq.top().second;
                pq.pop();
            }
            else if(count < pq.top().second) {
                pair<int, int> temp;
                temp = pq.top();
                temp.second -= count;
                pq.pop();
                pq.push(temp);
                count = 0;
                break;
            }
        }

        if(pq.size() > 0){
            if(pq.top().first < i){
                answer = false;
                return answer;
            }
        }

        if(cnt > task.size() - 1){
            continue;
        }

        while(cnt <= task.size() - 1 && task[cnt][0] <= i){
            // cout<<"i : "<<i<<endl;
            pq.push(make_pair(task[cnt][1],task[cnt][2]));
            cnt++;
        }
        //한번에 여러개가 들어가는 경우 고려해야함.
    }

    // cout<<"answer : "<<answer<<endl;

    return answer;
}

long long solution(vector<vector<int>> tasks) {
    long long answer = 0;

    task = tasks;

    long long start = 1;
    long long end = 100000000000;
    long long mid = 0;

    while(start <= end){
        mid = (start + end) / 2;
        bool flag = binary(mid);
        if(flag == true){
            // cout<<"true : "<<answer<<endl;
            answer = mid;
            end = mid - 1;
        }
        else if(flag == false){
            // cout<<"false : "<<false<<endl;
            // answer = mid;
            start = mid + 1;
        }
    }

    return answer;
}