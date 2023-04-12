#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[100001][5];

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int max_temp = 0;
    
    for(int i = 0;i<land.size();i++){
        for(int j = 0;j<4;j++){
            dp[i][j] = land[i][j];
        }
    }
    
    if(land.size() == 1){
        max_temp = 0;
        max_temp = max(land[0][1],land[0][2]);
        max_temp = max(max_temp,land[0][3]);
        answer = max_temp;
        return answer;
    }
    
    for(int i = 0;i<land.size();i++){
        for(int j = 0;j<4;j++){
            switch(j) {
                case 0:
                    max_temp = 0;
                    max_temp = max(dp[i - 1][1],dp[i - 1][2]);
                    max_temp = max(max_temp,dp[i - 1][3]);
                    dp[i][0] += max_temp;
                    break;
                case 1:
                    max_temp = 0;
                    max_temp = max(dp[i - 1][0],dp[i - 1][2]);
                    max_temp = max(max_temp,dp[i - 1][3]);
                    dp[i][1] += max_temp;
                    break;
                case 2:
                    max_temp = 0;
                    max_temp = max(dp[i - 1][1],dp[i - 1][0]);
                    max_temp = max(max_temp,dp[i - 1][3]);
                    dp[i][2] += max_temp;
                    break;
                case 3:
                    max_temp = 0;
                    max_temp = max(dp[i - 1][1],dp[i - 1][2]);
                    max_temp = max(max_temp,dp[i - 1][0]);
                    dp[i][3] += max_temp;
                    break;            
            }
        }
    }
    
    max_temp = 0;
    max_temp = max(dp[land.size() - 1][1],dp[land.size() - 1][2]);
    max_temp = max(max_temp,dp[land.size() - 1][3]);
    max_temp = max(max_temp,dp[land.size() - 1][0]);
    answer = max_temp;
    
    return answer;
}