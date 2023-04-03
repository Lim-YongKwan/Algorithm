#include <iostream>
#include <vector>

using namespace std;

void solve(string n){

    //제일 앞 자리부터 시작.
    //0~10까지 중에 fatal에 없는 가장 가까운걸 해야한다.
    //0 -> 10 으로 가면서 abs()가 가장 작은거 출력? -> 시작이 5고 4하고 6인데 뒤에가 6이 더 가깝다면 어떻게 풀어야 할까?
    //2가지 경우를 모두 킾했다가 마지막 결과 보고 출력?
    
    

    return;
}

int main(){
    string n;
    int m;
    cin>>n>>m;
    vector<char> fatal(m,0);

    for(int i = 0;i<m;i++){
        cin>>fatal[i];
    }

    return 0;
}