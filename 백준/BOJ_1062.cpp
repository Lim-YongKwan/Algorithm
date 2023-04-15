#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

vector<string > anta;
int visited[28];
int n,k;
int answer;

//백트래킹 이용해서 26개중에서 k개 선발하기.
void backTrack(int idx,int cnt){
    if(cnt == k){
        int count = 0;
        bool flag = true;
        for(int i = 0;i<anta.size();i++){
            flag = true;
            for(int j = 4;j<anta[i].size() - 4;j++){
                // cout<<"anta : "<<anta[i][j] - 'a' + 1<<" ";
                if(visited[anta[i][j] - 'a' + 1] == 0){
                    flag = false;
                    break;
                }
            }
            // cout<<endl;
            if(flag == true){
                count++;
            }
        }
        answer = max(answer,count);
        return;
    }
    
    for(int i = idx;i<=26;i++){
        if(visited[i] == 0){
            visited[i] = 1;
            backTrack(i,cnt + 1);
            visited[i] = 0;
        }
    }
    
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k;
    for(int i = 0;i<n;i++){
        string s;
        cin>>s;
        anta.push_back(s);
    }
    //5미만이면 나올 수 있는 값이 없다.
    if(k<5){
        cout<<0<<endl;
        return 0;
    }
    else if(k >= 26){
        cout<<n<<endl;
        return 0;
    }
    //5이상이라면
    visited[1] = 1;
    visited[3] = 1;
    visited[9] = 1;
    visited[14] = 1;
    visited[20] = 1;

    k = k - 5;

    backTrack(0,0);

    cout<<answer<<endl;

    return 0;
}