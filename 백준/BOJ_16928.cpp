#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int,int> ladder;
map<int,int> snake;
int dp[111];

void solve(){

    //2부터 시작이라서 1은 0
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 1;
    dp[5] = 1;
    dp[6] = 1;
    dp[7] = 1;
    int count = 1;
    //아무런 방해가 없다면 i번쨰 도달 시점은 7 => 1, 8 => 2...
    for(int i = 7;i<=104;i+=6){
        for(int j = i;j>i - 6;j--){
            dp[j] = count;
        }
        count++;
    }

    //snake가 나오는 곳은 최댓값, 사다리는 사다리를 타는곳과 같은 값을 넣어주자.
    //사다리와 뱀이 같은 곳에 있을 수 없기에 중복검사는 필요 없음.
    for(int i = 1;i<=100;i++){
        if(snake[i] != 0){
            dp[i] = 2000000000;
        }
        if(ladder[i] != 0){
            dp[ladder[i]] = dp[i];
        }
    }

    //2부터 시작(1에는 아무것도 존재 못함)해서 앞의 6칸을 가보자.
    //만일 80이 사다리를 타고 와서 2번만에 왔다면 81,82,83,84,85,86을 검사해서
    //해당 위치가 사다리 타고 온 수 + 1, dp[현재] 중에 min인 값을 따르게 하자.
    for(int i = 2;i<=100;i++){
        for(int j = i + 1;j<= i + 6;j++){
            //snake는 무조건 피하자.
            if(dp[j] != 2000000000){
                dp[j] = min(dp[i] + 1, dp[j]);
            }
        }
    }

    //100번째 위치를 출력하자.
    cout<<dp[100]<<endl;

    //확인용 출력문
    // for(int i = 1;i<=100;i++){
    //     cout<<i<<" "<<dp[i]<<endl;
    // }

    return;
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        int a,b;
        cin>>a>>b;
        ladder[a] = b;
    }
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        snake[a] = b;
    }
    solve();

    return 0;
}