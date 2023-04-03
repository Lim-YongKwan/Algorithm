#include<iostream>
#include<vector>
#include <algorithm>
#include<queue>
#define endl "\n"
using namespace std;

int n,m;
int visited[15];
int answer = 100000000;
vector<pair<int, int> > delivery; //2를 넣을 벡터
vector<pair<int, int> > chicken; //1을 넣을 벡터.
vector<pair<int, int> > goobne; // 백트래킹을 통해 조합을 만들 벡터

void back_tracking(int k, int cnt){

    if(cnt == m){
        int min_dist;
        int min_answer = 0; //정답값.

        for(int i = 0;i<delivery.size();i++){ //배달갈 위치들
            min_dist = 100000000;
            for(int j = 0;j<goobne.size();j++){ //현재 있는 굽네 매장 위치들.
                min_dist = min(min_dist,abs(delivery[i].first - goobne[j].first) + abs(delivery[i].second - goobne[j].second));
            }
            min_answer += min_dist;
        }
        answer = min(answer,min_answer);
        return;
    }

    for(int i = k; i<chicken.size();i++){ //치킨집 갯수를 굽네에 조합으로 넣자.
        if(visited[i] == 0){
            visited[i] = 1;
            goobne.push_back(make_pair(chicken[i].first,chicken[i].second)); //굽네 매장을 바꿔주자.
            back_tracking(i, cnt + 1);
            goobne.pop_back();
            visited[i] = 0;
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    cin>>n>>m;
    int temp;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            cin >> temp;
            if(temp == 2){
                chicken.push_back(make_pair(i,j)); //2라면 매장에 추가해주자.
            }
            else if(temp == 1){
                delivery.push_back(make_pair(i , j)); 
            }
        }
    }

    back_tracking(0,0);
    cout<<answer<<endl;

    return 0;
}