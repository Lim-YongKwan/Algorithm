#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> blob(n);
    for(int i = 0;i<n;i++){
        cin>>blob[i];
    }

    vector<long long> tower(n);
    tower[0] = blob[0];
    tower[n-1] = blob[n-1];

    for(int i = 1;i<n-1;i++){
        tower[i] = blob[i] + min(blob[i-1],blob[i+1]);
    }

    cout<<*max_element(tower.begin(),tower.end())<<endl;

    return 0;
}