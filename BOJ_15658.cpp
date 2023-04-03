#include<iostream>
#include<algorithm>
#define endl "\n"

using namespace std;

int t;
int Max = -1000000000;
int Min = 1000000000;
int mathmetical[12];
int arithmetic[4];

void backtracking(int n, int total){
    if(n == t-1){
        Min = min(Min,total);
        Max = max(Max,total);
        return;
    }

    for(int i = 0;i<4;i++){
        int temp = total;
        if(arithmetic[i] <= 0 ){
            continue;
        }

        if(i == 0){
            total += mathmetical[n+1];
        }
        else if(i == 1){
            total -= mathmetical[n+1];
        }
        else if(i == 2){
            total *= mathmetical[n+1];
        }
        else{
            total /= mathmetical[n+1];
        }

        arithmetic[i]--;
        backtracking(n+1,total);
        total = temp;
        arithmetic[i]++;
    }
}

int main(){
    
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>t;
    for(int i = 0;i<t;i++){
        cin>>mathmetical[i];
    }

    for(int i = 0;i<4;i++){
        cin>>arithmetic[i];
    }

    backtracking(0,mathmetical[0]);
    cout<<Max<<endl;
    cout<<Min<<endl;
    return 0;
}