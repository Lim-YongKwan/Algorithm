#include<iostream>
#define endl "\n"

using namespace std;

int budget[10001];

void solve(int n,int m){

    int high = 10000;
    int low = 0;
    int mid = 0;
    int answer = 0;

    long long total = 0;

    int Max = 0;
    for(int i = 0;i<n;i++){
        total += budget[i];
        if(Max<budget[i]){
            Max = budget[i];
        }
    }
    if(total<m){
        cout<<Max<<endl;
        return;
    }

    mid = (high + low) / 2;
    high = Max;


    while(low<=high){
        total = 0;
        mid = (high + low) / 2;

        for(int i = 0;i<n;i++){
            if(budget[i]<mid){
                total += budget[i];
            }
            else{
                total += mid;
            }
        }

        if(total>m){
            high = mid -1;
        }
        else if(total<=m){
            answer = mid;
            low = mid + 1;
        }
    }

    cout<<answer<<endl;
    return;
}

int main(){
    int n,m;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>budget[i];
    }
    cin>>m;
    solve(n,m);
    return 0;
}