#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n;

struct cmp{
    bool operator()(vector<int> a, vector<int> b){
        return a[1] > a[1];
    }
};

int main(){
    cin>>n;
    vector<vector<int> > foods(n,vector<int>(2,0));
    for(int i = 0;i<n;i++){
        cin>>foods[i][0]>>foods[i][1];
    }

    


    return 0;
}