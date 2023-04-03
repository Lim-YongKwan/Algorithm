#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"

using namespace std;
const int MAX = 20000 + 1;
const int INF = 987654321;
int V, E, K;

vector<pair<int, int> > graph[MAX];

vector<int> dijkstra(int start, int vertex){
    vector<int> distance(vertex,INF);
    distance[start] = 0;

    priority_queue<pair<int, int>,vector<pair<int, int> >,greater<pair<int, int> > > pq;
    pq.push(make_pair(0,start));

    while(pq.size()>0){
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

int main(void)
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    //정점 : V, 간선 : E, 시작: K
    cin>>V>>E>>K;

    for(int i = 0;i<E;i++){
        int source,destination,cost;
        cin>>source>>destination>>cost;
        graph[source - 1].push_back(make_pair(destination - 1,cost));
    }
    vector<int> result = dijkstra(K - 1,V); // 시작위치, 정점갯수 

    for(int i = 0;i<V;i++){
        if(result[i] == INF){
            cout<<"INF"<<endl;
        }
        else{
            cout<<result[i]<<endl;
        }
    }

    return 0;
}