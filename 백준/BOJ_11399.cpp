#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> atm;
    for(int i = 0;i<n;i++){
        int temp;
        cin>>temp;
        atm.push_back(temp);
    }
    sort(atm.begin(),atm.end());

    int total = 0;
    for(int i = n; i>0 ;i--){
        total += i * atm[abs(n-i)];
    }
    cout<<total<<endl;

    return 0;
}