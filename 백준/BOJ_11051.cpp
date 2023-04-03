#include<iostream>
#include<algorithm>
#include<string>
#define endl "\n"

using namespace std;

long long result[1001][1001];

void combination(int n,int k){

    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=k;j++){
            if(i == 0 ){
                result[i][j] = 1;
                continue;
            }
            if(j == 0 or j == i){
                result[i][j] = 1;
                continue;
            }
            result[i][j] = (result[i-1][j] + result[i-1][j-1])%10007;
        }
    }
    return;
}

int main(){
    int n,k;
    cin>>n>>k;
    combination(n,k);
    cout<<result[n][k]<<endl;
    return 0;
}