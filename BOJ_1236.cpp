#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char> > castle(n,vector<char>(m,0));

    bool janitor = false;

    int height = 0;
    int width = 0;
    for(int i = 0;i<n;i++){
        janitor = false;
        for(int j = 0;j<m;j++){
            cin>>castle[i][j];
            if(castle[i][j] == 'X'){
                janitor = true;
            }
        }
        if(janitor == false){
            width++;
        }
    }

    for(int i = 0;i<m;i++){
        janitor = false;
        for(int j = 0;j<n;j++){
            if(castle[j][i] == 'X'){
                janitor = true;
            }
        }
        if(janitor == false){
            height++;
        }
    }

    cout<<max(height,width)<<endl;

    return 0;
}