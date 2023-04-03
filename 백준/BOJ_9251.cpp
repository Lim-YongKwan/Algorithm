#include<iostream>
#include<vector>
#include<string>
#define endl "\n"
using namespace std;

void LCS(string s1,string s2){

    vector<vector<int> > dp(s1.size() + 1,vector<int>(s2.size() + 1));

    for(int i = 1;i<=s1.size();i++){
        for(int j = 1;j<=s2.size();j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i -1][j -1] + 1;
            }
            else{
                if(dp[i-1][j] >= dp[i][j-1]){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i][j-1];
                }
            }
        }
    }

    cout<<dp[s1.size()][s2.size()]<<endl;
    
    return;
}

int main(){
    string lcs_first;
    string lcs_last;
    cin>>lcs_first>>lcs_last;
    LCS(lcs_first,lcs_last);
    return 0;
}