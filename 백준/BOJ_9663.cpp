#include<iostream>
#include<vector>
#define endl "\n"

using namespace std;

int n;
int answer;
int visit[17][17];

void DFS(int x, int y, int count, int negative){
    count *= negative;
    visit[x][y] += count;

    for(int i = 0;i<n;i++){
        if(count+i-1<n){
            visit[count+i-1][y] += count;
        }
        if(count-i-1>0){
            visit[count-i-1][y] += count;
        }
        if(y+i<n){
            visit[count-1][y+i] += count;
        }
        if(y-i>0){
            visit[count-1][y-i] += count;
        }
    }

    for(int i = 1;i<n;i++){
        if(x-i>=0 and y-i>=0){
            visit[x-i][y-i] += count;
        }
        if(x-i>=0 and y+i<n){
            visit[x-i][y+i] += count;
        }
        if(x+i<n and y+i<n){
            visit[x+i][y+i] += count;
        }
        if(x+i <n and y-i>=0){
            visit[x+i][y-i] += count;
        }
    }
    return;
}

void dfsRelease(int x, int y, int count){
    visit[x][y] -= count;

    for(int i = 0;i<n;i++){
        if(count+i-1<n){
            visit[count+i-1][y] -= count;
        }
        if(count-i-1>0){
            visit[count-i-1][y] -= count;
        }
        if(y+i<n){
            visit[count-1][y+i] -= count;
        }
        if(y-i>0){
            visit[count-1][y-i] -= count;
        }
    }

    for(int i = 1;i<n;i++){
        if(x-i>=0 and y-i>=0){
            visit[x-i][y-i] -= count;
        }
        if(x-i>=0 and y+i<n){
            visit[x-i][y+i] -= count;
        }
        if(x+i<n and y+i<n){
            visit[x+i][y+i] -= count;
        }
        if(x+i <n and y-i>=0){
            visit[x+i][y-i] -= count;
        }
    }
    return;
}

void backtracking(int count){

    if(count == n+1){
        answer++;
        return;
    }

   for(int i = 0;i<n;i++){
        if(visit[count-1][i] != 0){
            continue;
        }
        DFS(count-1,i, count,1);
        backtracking(count+1);
        dfsRelease(count-1,i,count);
    }

    return;
}

int main(){
    cin>>n;
    backtracking(1);
    cout<<answer<<endl;
    return 0;
}