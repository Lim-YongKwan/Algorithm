#include<iostream>
#include<vector>
#include<algorithm>

#define endl "\n"

using namespace std;

int main(){
    int n;
    cin>>n;

    vector<pair<int, int> > company(n);
    int DP[16] = {0,};

    int answer = 0;

    for(int i = 1;i<=n;i++){
        cin>>company[i].first>>company[i].second;
        for(int j = 0;j<i;j++){
            if(company[j].first + j <= i and i + company[i].first <= n + 1 ){
                    DP[i] = max(DP[i] , DP[j] + company[i].second);
                    answer = max(answer , DP[i]);
            }
        }
    }

    cout<<answer<<endl;

    return 0;
}