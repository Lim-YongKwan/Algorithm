#include<iostream>
#define endl "\n"

using namespace std;

int pascal[31][31];

void combine(int n,int k){
    pascal[0][0] = 1;
    pascal[1][0] = 1;
    pascal[1][1] = 1;

    for(int i = 1;i<=n;i++){
        for(int j = 0;j<=k;j++){
            
            if(j == i or j == 0){
                pascal[i][j] = 1;
                continue;
            }

            pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
        }
    }

    cout<<pascal[n-1][k-1];
}

int main(){
    int n,k;
    cin>>n>>k;
    combine(n,k);

    return 0;
}