#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int board[510][510];
int n,m;

int main(){
    cin>>n>>m;
    //
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>board[i][j];
        }
    }
    return 0;
}