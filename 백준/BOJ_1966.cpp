#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

void queueback(){
    int temp = q.front();
    q.pop();

    for(int i = 0;i<q.size();i++){
        if(temp < q.front()){
            q.push(temp);
            temp = 0;
            break;
        }
        int q_front = q.front();
        q.pop();
        q.push(q_front);
    }

    if(temp == 0){
        return;
    }
    else{
        q.push(temp);
    }
    
    return;
}

int main(){
    int testcase;
    cin>>testcase;
    while(testcase--){
        int n,m;
        cin>>n>>m;
        for(int i = 0;i<n;i++){
            int temp;
            cin>>temp;
            q.push(temp);
        }

        for(int i = 0;i<m;i++){
            queueback();
        }

    }
    return 0;
}