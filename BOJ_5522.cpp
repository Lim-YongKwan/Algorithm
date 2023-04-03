#include<iostream>
#include<vector>

using namespace std;

void solve(vector<int>& card){
    int total = 0;
    for(int i = 0;i<card.size();i++){
        cin>>card[i];
        total+= card[i];
    }
    cout<<total<<endl;
    return;
}

int main(){
    vector<int> card(5);
    solve(card);
    return 0;
}