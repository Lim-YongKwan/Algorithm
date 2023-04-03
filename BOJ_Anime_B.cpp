#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<int> paper(n,0);

    for(int i = 0;i<m;i++){
        int temp;
        cin>>temp;
        paper[temp] = 1;
    }

    

    return 0;
}