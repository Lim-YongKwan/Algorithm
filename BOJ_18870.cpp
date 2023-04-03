#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<map>
#define endl "\n"

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> coordinate;
    vector<int> press;
    for(int i = 0;i<n;i++){
        int temp;
        cin>>temp;
        coordinate.push_back(temp);
        press.push_back(temp);
    }
    sort(press.begin(),press.end());
    press.erase(unique(press.begin(),press.end()), press.end());

    for(int i = 0; i<n; i++){
        auto it = lower_bound(press.begin(),press.end(),coordinate[i]);
        cout<< it-press.begin()<<" ";
    }

    return 0;
}