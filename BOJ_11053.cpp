#include<iostream>
#include<algorithm>
#define endl "\n"

using namespace std;

int sequence[1001];
int DP[1001];

void solve(int n){

    DP[0] = 1;
    int answer = 1;
    for(int i = 1;i<n;i++){
        DP[i] = 1;
        for(int j = 0;j<i;j++){
            if(sequence[i]>sequence[j]){
                if(DP[i]<= DP[j]){
                    DP[i] = DP[j] +1;
                }
            }
        }
        answer = max(answer,DP[i]);
    }
    cout<<answer<<endl;
    return;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>sequence[i];
    }
    solve(n);
    return 0;
}