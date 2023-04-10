#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> vec(n,0);
    for(int i = 0;i<n;i++){
        cin>>vec[i];
    }
    int k;
    cin>>k;
    sort(vec.begin(),vec.end());
    cout<<upper_bound(vec.begin(),vec.end(),k) - vec.begin() - (lower_bound(vec.begin(), vec.end(), k) - vec.begin());
    return 0;
}