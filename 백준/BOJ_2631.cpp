#include<iostream>
#include<algorithm>
#define endl "\n"

using namespace std;

int cares[201];
int DP[201];

void solve(int n){

    int Max = 0;
    DP[0] =1;
    for(int i = 1;i<n;i++){
        DP[i] = 1;
        for(int j = 0;j<i;j++){
            if(cares[i]>cares[j]){
                if(DP[j] >= DP[i]){
                    DP[i] = DP[j] +1;
                }
                else{
                    continue;
                }
            }
        }
        if(Max<DP[i]){
            Max = DP[i];
        }
    }

    cout<<n- Max<<endl;

    return;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>cares[i];
    }
    solve(n);
    return 0;
}