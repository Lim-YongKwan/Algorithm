#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int visited[100001];
int n,m;

vector<pair<int, int> > island[100001];

//파라메트릭 서치 + bfs
bool bfs(int sPosition, int ePosition, int mid){

    queue<int> truck;

    for(int i = 0;i<100001;i++){
        visited[i] = false;
    }

    truck.push(sPosition);
    visited[sPosition] = 1;

    while(truck.size() > 0){
        int curL = truck.front();
        truck.pop();

        if(curL == ePosition){
            return true;
        }

        for(int i = 0;i<island[curL].size();i++){
            int next = island[curL][i].first;
            int cost = island[curL][i].second;
            if(visited[next] == 0){
                if(mid <= cost){
                    visited[next] = 1;
                    truck.push(next);
                }
            }
        }
    }

    return false;
}

void parametric(int sPosition, int ePosition){
    int start = 1;
    int end = 1000000000;
    int mid;
    int result = 0;

    while(start <= end){
        mid = (start + end) / 2;
        if(bfs(sPosition,ePosition,mid) == true){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    cout<<end<<endl;

    return;
}

int main() {
    cin>>n>>m;

    for(int i = 0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        island[a].push_back(make_pair(b,c));
        island[b].push_back(make_pair(a,c));
    }

    int sPosition,ePosition;
    cin>>sPosition>>ePosition;

    parametric(sPosition,ePosition);

    return 0;
}