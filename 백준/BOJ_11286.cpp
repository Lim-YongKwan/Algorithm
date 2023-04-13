#include <iostream>
#include <queue>
#include <algorithm>
#define endl "\n"

using namespace std;

struct cmp{
    bool operator()(int a, int b){
        if(abs(a) == abs(b)){
            return a > b;
        }
        return abs(a) > abs(b);
    }
};

int main(){
    int testcase;
    cin>>testcase;
    //1. 절대값 2. 작은값.
    priority_queue<int, vector<int>, cmp > pq;

    while(testcase--){
        int temp;
        cin>>temp;
        if(temp == 0){
            if(pq.size() == 0){
                cout<<0<<endl;
                continue;
            }
            cout<<pq.top()<<endl;
            pq.pop();
        }
        else{
            pq.push(temp);
        }
    }

    return 0;
}