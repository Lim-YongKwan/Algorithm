#include <iostream>
#include <map>

using namespace std;

int main(){
    int n;
    cin>>n;
    map<string,int> mp;
    for(int i = 0;i<n;i++){
        string s;
        int a;
        cin>>s>>a;
        mp[s] += a;
    }

    bool answer = false;

    if(mp["STRAWBERRY"] == 5){
        answer = true;
    }
    else if(mp["BANANA"] == 5){
        answer = true;
    }
    else if(mp["LIME"] ==5){
        answer = true;
    }
    else if(mp["PLUM"] == 5){
        answer = true;
    }

    cout<< (answer ? "YES" : "NO")<<endl;
    
    return 0;
}