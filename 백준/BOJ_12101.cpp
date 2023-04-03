#include<iostream>
#include<vector>
using namespace std;

int n,k;
int cnt;
int oneTwoThree[3] = {1,2,3};
bool visit[12];
vector<int> times;

void backtracking(int m){
    if(m>n)
        return;
    if(m == n){
        cnt++;
        if(cnt == k){
            for(int i = 0;i<times.size();i++){
                cout<<times[i];
                if(i != times.size()-1){
                    cout<<"+";
                }
            }
            cout<<endl;
        }
        return;
    }

    for(int i = 0;i<3;i++){
        times.push_back(oneTwoThree[i]);
        backtracking(m+oneTwoThree[i]);
        times.pop_back();
    }
    return;
}

int main(){
    cin>>n>>k;
    backtracking(0);
    if(cnt == 0 or cnt < k){
        cout<<"-1"<<endl;
    }
    return 0;
}