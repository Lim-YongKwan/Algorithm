#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

//벡터 생성
vector<int> vec(41,0);
//map(key-value)값을 이용해서 해당 문제를 풀도록 하자.
map<int,int> mp;

int n;
long long answer;

//오른쪽 합계
void right_sum(int loc, int total, int s){

    //만약 위치가 최종위치에 도달했다면
    if(loc == n){
        //map에 현재까지 더한 값을 더하자.
        mp[total]++;
        return;
    }

    //위치 loc을 1씩 더하기. total에 현재 숫자를 더하거나 말기
    right_sum(loc + 1, total + vec[loc], s);
    right_sum(loc + 1, total, s);
    return;
}

//왼쪽 합계
void left_sum(int loc, int total, int s){

    if(loc == n / 2){
        //map에 현재 요구하는 값 s에서 total을 뺀값이 있다면 있는만큼 더하자.
        //해당 값이 더했을때 answer이 될 수 있는 이유는
        //위에 있는 right가 먼저 실행이 끝난뒤에 mp[total] 에 나올 수 있는 값의 경우가 저장이 되어 있다.
        //그렇기에 left에서 나올 수 있는 total을 만약 s에서 뺐을때 해당값이 존재한다면
        //answer에 더할수가 있다.
        //만일 없다면 0으로 되어 있을 거기 때문이다.
        answer += mp[s-total];
        return;
    }

    left_sum(loc + 1, total + vec[loc], s);
    left_sum(loc + 1, total, s);
    return;
}

void solve(int s){

    //오른쪽하고 왼쪽으로 나누어서 더하자.
    right_sum(vec.size() / 2, 0,s);
    left_sum(0,0,s);

    //만약 s가 0이라면 1개를 빼자.
    //여기서 1개를 빼는 이유는 0은 왼쪽, 오른쪽 둘다 겹칠 수 있기 때문인걸로 추측.
    if(s == 0){
        cout<<answer - 1<<endl;
    }
    else{
        cout<<answer<<endl;
    }

    return;
}

int main(){
    int s;
    cin>>n>>s;

    vec = vector<int>(n,0);

    for(int i = 0;i<n;i++){
        cin>>vec[i];
    }

    solve(s);

    return 0;
}