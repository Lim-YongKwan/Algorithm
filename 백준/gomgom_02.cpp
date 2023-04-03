#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<string, string> > rainbow(n);

    map<string, int> mp;
    int answer = 0;
    for(int i = 0;i<n;i++){
        cin>>rainbow[i].first;
        cin>>rainbow[i].second;
        if(mp[rainbow[i].first] >= 1){
            if(mp[rainbow[i].second] < 1){
                mp[rainbow[i].second]++;
                answer++;
            }
        }
        else if( mp[rainbow[i].second] >= 1){
            if(mp[rainbow[i].first] < 1){
                mp[rainbow[i].first]++;
                answer++;
            }
        }

        if(rainbow[i].first == "ChongChong" || rainbow[i].second == "ChongChong"){
            mp[rainbow[i].first]++;
            mp[rainbow[i].second]++;
            answer += 2;
        }
    }

    cout<<answer<<endl;

    return 0;
}