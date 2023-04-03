#include <iostream>
#include <algorithm>

using namespace std;

int dp[101][100001];
int cost[101];
int value[101];
int n,k;

int main(){
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        cin>>cost[i]>>value[i];
    }

    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=k;j++){            
            if(j - cost[i] >= 0){
                dp[i][j] = max(dp[i - 1][j - cost[i]] + value[i], dp[i - 1][j]);
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout<<dp[n][k]<<endl;

    return 0;
}
