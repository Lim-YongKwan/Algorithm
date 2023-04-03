#include<iostream>
#include<vector>
#include<algorithm>
#define endl "\n"

using namespace std;

void solve(vector<int>& sangCard, vector<int>& requestCard){
    sort(sangCard.begin(),sangCard.end());
    for(int i = 0;i<requestCard.size();i++){
        cout<<upper_bound(sangCard.begin(),sangCard.end(),requestCard[i]) - lower_bound(sangCard.begin(),sangCard.end(),requestCard[i])<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<int> sangCard(n);
    for(int i = 0;i<n;i++){
        cin>>sangCard[i];
    }

    int m;
    cin>>m;
    vector<int> requestCard(m);
    for(int i = 0;i<m;i++){
        cin>>requestCard[i];
    }
    solve(sangCard,requestCard);
    return 0;
}