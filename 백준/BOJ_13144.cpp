#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> sequence(n,0);
    for(int i = 0;i<n;i++){
        cin >> sequence[i];
    }

    //두 포인터 알고리즘을 이용
    int start = 0;
    int end = 1;
    map<int, bool> bomb; // 메모리 제한과 시간을 보니 이진트리를 써야할 것 같애서 rb트리 구조인 map 사용
    bomb[sequence[start]] = true; // 우선  제일 처음 값 입력
    long long answer = 1; // answer는 1개가 넣어졌으니 1로 시작. 또한, 범위가 int를 넘어설 수 있기에 long long으로 지정.

    while(start<end && sequence.size() > end){ //start가 end와 동등해 지기 전이면서 동시에 end가 벡터의 마지막 위치에 닿기 전까지 돌리기.
        if(bomb[sequence[end]] == true){ //만일 bomb에 이미 들어가 있다면
            bomb.erase(sequence[start]);
            start++; //start를 1 진격
        }
        if(bomb[sequence[end]] == false && sequence.size() > end){ //만일 end가 아직 안 들어가있고 동시에 size보다 end값이 작다면
            bomb[sequence[end]] = true; //bomb에 벡터의 end 위치 입력.
            answer += bomb.size(); //answer는 bomb 사이즈 만큼 더해주자.
            end++; // end를 1 진격
        }
    }

    cout<<answer<<endl;

    return 0;
}