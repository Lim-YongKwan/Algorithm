#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int board[20][20];
int n,m;



int main(){
    int answer = 0;
    cin>>n>>m;
    queue<pair<int, int> > blue;
    queue<pair<int, int> > red;

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            char temp;
            cin>>temp;
            if(temp == '#'){
                board[i][j] = -1;
            }
            else if(temp == 'B'){
                blue.push(make_pair(i,j));
            }
            else if(temp == 'R'){
                red.push(make_pair(i,j));
            }
            else if(temp == 'O'){
                board[i][j] = 1;
            }

        }
    }

    cout<<(answer ? 1 : 0)<<endl;
    return 0;
}