#include<iostream>
#define endl "\n"

using namespace std;

int snail[1001][1001];

int n;

void upside(int x,int y,int k);
void rightside(int x,int y,int k);
void leftside(int x,int y,int k);
void downside(int x,int y,int k);

void upside(int x,int y,int k){

    if(k == n-1){
        for(int i = 0;i<k;i++){
        int temp = x-1;
        snail[temp][y] = snail[x][y] + 1;
        x = temp;
        }
        return;
    }

    for(int i = 0;i<k;i++){
        int temp = x-1;
        snail[temp][y] = snail[x][y] + 1;
        x = temp;
    }
    rightside(x,y,k);
    return;
}
void rightside(int x,int y, int k){
    for(int i = 0;i<k;i++){
        int temp = y+1;
        snail[x][temp] = snail[x][y] + 1;
        y = temp;
    }
    downside(x,y,k+1);
    return;
}
void downside(int x, int y, int k){
    for(int i = 0;i<k;i++){
        int temp = x+1;
        snail[temp][y] = snail[x][y] +1;
        x = temp;
    }
    leftside(x,y,k);
    return;
}
void leftside(int x, int y, int k){
    for(int i = 0;i<k;i++){
        int temp = y-1;
        snail[x][temp] = snail[x][y] +1;
        y = temp;
    }
    if(k == n-1){
        upside(x,y,k);
        return;
    }

    upside(x,y,k+1);
    return;
}

void solve(){
    int temp = n/2;
    snail[temp][temp] = 1;

    upside(temp,temp,1);
    return;
}

int main(){
    int m;
    cin>>n>>m;
    solve();

    pair<int,int> result;

    for(int i = 0;i<n;i++){
        for(int j = 0; j <n;j++){
            cout<<snail[i][j]<<" ";
            if(snail[i][j] == m){
                result.first = i+1;
                result.second = j+1;
            }
        }
        cout<<endl;
    }
    cout<<result.first<<" "<<result.second<<endl;

    return 0;
}