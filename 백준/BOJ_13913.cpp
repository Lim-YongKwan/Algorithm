#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int subin[100001];
int visited[100001];

void solution(int n, int k){

    //수빈이의 위치를 닮을 queue
    queue<int> count;
    count.push(n);
    visited[n] = 1;

    while(count.size() > 0){

        int curSubin = count.front();
        count.pop();

        //차례대로 수빈이가 이동하는 위치이며
        //if문을 통해서 갈수있는 곳인지 파악
        //visited를 이용해서 방문을 표시
        //subin이의 다음 좌표에 현재 위치 넣기.
        //queue에 수빈이의 다음 좌표 넣기.
        //만일 다음 좌표가 k라면 탈출.

        if(curSubin * 2 <= 100000 && visited[curSubin * 2] == 0){
            visited[curSubin * 2] = 1;
            subin[curSubin * 2] = curSubin;
            count.push(curSubin * 2);
            if(curSubin * 2 == k){
                return;
            }
        }
        if(curSubin + 1 <= 100000 && visited[curSubin + 1] == 0){
            visited[curSubin + 1] = 1;
            subin[curSubin + 1] = curSubin;
            count.push(curSubin + 1);
            if(curSubin + 1 == k){
                return;
            }
        }
        if(curSubin - 1 >= 0 && visited[curSubin - 1] == 0){
            visited[curSubin - 1] = 1;
            subin[curSubin - 1] = curSubin;
            count.push(curSubin - 1);
            if(curSubin - 1 == k){
                return;
            }
        }
    }

    return;
}


int main(){
    //n은 수빈이 위치, k는 동생 위치.
    int n,k;
    cin>>n>>k;

    solution(n,k);

    stack<int> answer;

    int locate = k;

    //locate가 n이 오기 전까지
    while(locate != n){
        //locate는 왔던 좌표로 이동한다.
        locate = subin[locate];
        //stack에 차례대로 담자.
        answer.push(locate);
    }

    cout<<answer.size()<<endl;

    while(answer.size() > 0){
        cout<<answer.top()<<" ";
        answer.pop();
    }
    cout<<k<<endl;

    return 0;
}