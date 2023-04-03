#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int> > graph[1001];

vector<int> dijkstra(int start,int vertex){
    vector<int> distance(vertex,1000000000);
    distance[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int> > ,greater<pair<int, int> > > pq;
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

            if(distance[next] <= nCost + cost){
                continue;
            }
            distance[next] = nCost + cost;
            pq.push(make_pair(nCost + cost, next));
        }
    }

    return distance;
}


int main(){
    int n,m;
    cin>>n>>m;
    n++;
    for(int i = 0;i<m;i++){
        int source,destination,cost;
        cin>>source>>destination>>cost;
        graph[source].push_back(make_pair(destination,cost));
    }
    int start,end;
    cin>>start>>end;

    vector<int> answer = dijkstra(start,n);

    cout<<answer[end]<<endl;

    return 0;
}