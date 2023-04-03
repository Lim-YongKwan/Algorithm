#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int> > gorani(n + 1,vector<int>(m + 1,0) );

    pair<int, int> loc;
    int min_gorani = 55;

    for(int i = 1;i<n;i++){
        cin>>gorani[i][1];
        if(gorani[i][1] < min_gorani){
            min_gorani = gorani[i][1];
            loc.first = i;
            loc.second = 1;
        }
    }

    for(int i = 1;i<=m;i++){
        cin>>gorani[n][i];

        if(gorani[n][i] < min_gorani){
            min_gorani = gorani[n][i];
            loc.first = n;
            loc.second = i;
        }
    }

    if(min_gorani == 0){
        cout<<loc.first<<" "<<loc.second<<endl;
    }
    else{
        if(loc.second == 1){
            cout<<loc.first<<" "<<loc.second + min_gorani<<endl;
        }
        else{
            cout<<loc.first - min_gorani<<" "<<loc.second<<endl;
        }
    }


    return 0;
}