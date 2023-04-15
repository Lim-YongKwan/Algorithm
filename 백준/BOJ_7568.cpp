#include <iostream>
#include <vector>
#include <algorithm>
#define endl "\n"
using namespace std;

int n;

int main(){
    cin>>n;
    vector<int> result;
    vector<pair<int, int> > height(n, pair<int,int>());
    for(int i = 0;i<n;i++){
        cin>>height[i].first>>height[i].second;
    }

    int answer = 0;
    for(int i = 0;i<n;i++){
        int x,y;
        x = height[i].first;
        y = height[i].second;

        for(int j = 0;j<n;j++){
            if(x < height[j].first && y < height[j].second){
                answer++;
            }
        }
        result.push_back(answer + 1);
        answer = 0;
    }

    cout<<result[0];
    for(int i = 1;i<result.size();i++){
        cout<<" "<<result[i];
    }
    cout<<endl;
    return 0;
}