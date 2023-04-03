#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrack(){
    return;
}

int main(){
    int n,m,c;
    cin>>n>>m>>c;

    int total = min(n,m);
    long long answer = 0;

    vector<vector<int> > meeting(n,vector<int>(m,0));
    vector<int> nuniv(n,0);
    vector<int> muniv(m,0);

    for(int i = 0;i<c;i++){
        for(int j = 0;j<c;j++){
            cin>>meeting[i][j];
        }
    }

    for(int i = 0;i<n;i++){
        cin>>nuniv[i];
    }
    for(int i = 0;i<m;i++){
        cin>>muniv[i];
    }

    long long result = 0;

    backtrack();


    cout<<answer<<endl;


    return 0;
}