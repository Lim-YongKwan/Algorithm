#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> augment;
    for(int i = 0;i<n;i++){
        int temp;
        cin>>temp;
        if(i == 0 or augment.back()<temp){
            augment.push_back(temp);
        }
        else{
            *lower_bound(augment.begin(),augment.end(),temp) = temp;
        }
    }
    cout<<augment.size()<<endl;
    return 0;
}