#include<iostream>
#include<queue>

using namespace std; 

void dfs(int a, int b){
    queue<pair<long long, int> > prime;
    prime.push(make_pair(a,1));

    while(prime.size()>0){
        if(prime.front().first == b){
            break;
        }

        if(prime.front().first * 2 <= b){
            prime.push(make_pair(prime.front().first * 2 , prime.front().second + 1));
        }

        if(prime.front().first * 10 + 1<= b){
            prime.push(make_pair(prime.front().first * 10 + 1 , prime.front().second + 1));
        }

        prime.pop();
    }

    if(prime.size() <= 0){
        cout<<-1<<endl;
        return;
    }

    cout<<prime.front().second<<endl;

    return;
}

int main(){
    int a,b;
    cin>>a>>b;
    dfs(a,b);
    return 0;
}