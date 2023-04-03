#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int, int> > graph[801];

vector<int> dijkstra(int start, int vertex){
    vector<int> distance(vertex,2000000000);
    distance[start] = 0;
    
    priority_queue<pair<int, int> , vector<pair<int, int> > ,greater<pair<int, int > > > pq;
    pq.push(make_pair(0,start));

    while(pq.size() > 0){
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if(distance[cur] != cost){
            continue;
        }

        for(int i = 0;i<graph[cur].size();i++){
            int next = graph[cur][i].first;
            int nCost = graph[cur][i].second;

            if(distance[next] <= cost + nCost){
                continue;
            }

            distance[next] = cost + nCost;
            pq.push(make_pair(cost + nCost,next));
        }
    }

    return distance;
}

int main(){
    int n,e;
    cin>>n>>e;

    for(int i = 0;i<e;i++){
        int source,destination,cost;
        cin>>source>>destination>>cost;
        graph[source - 1].push_back(make_pair(destination - 1,cost));
        graph[destination - 1].push_back(make_pair(source - 1,cost));
    }

    long long answer_1 = 0;
    long long answer_2 = 0;
    long long total = 0;
    int middle_start,middle_end;
    cin>>middle_start>>middle_end;

    vector<int> one_middleOne = dijkstra(0,n);
    vector<int> middleOne_middleTwo = dijkstra(middle_start - 1,n);
    vector<int> middleTwo_End = dijkstra(middle_end - 1,n);

    answer_1 += one_middleOne[middle_start - 1];
    answer_1 += middleOne_middleTwo[middle_end - 1];
    answer_1 += middleTwo_End[n - 1];

    answer_2 += one_middleOne[middle_end - 1];
    answer_2 += middleTwo_End[middle_start - 1];
    answer_2 += middleOne_middleTwo[n - 1];


    total = min(answer_1,answer_2);

    if(total >= 2000000000){
        cout<<-1<<endl;
    }
    else{
        cout<<total<<endl;
    }

    return 0;
}