#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string s,t;
int answer = 0;
void recursive(string str){
    if(str.size() == s.size()){
        if(str == s){
            answer = 1;
            return;
        }
        return;
    }

    if(str[0] == 'B'){
        string temp;
        for(int i = str.size() - 1;i>0;i--){
            temp += str[i];
        }
        recursive(temp);
    }
    if(str[str.size() - 1] == 'A'){
        string temp;
        for(int i = 0;i<str.size() - 1;i++){
            temp += str[i];
        }
        recursive(temp);
    }
    return;
}

int main(){
    cin>>s>>t;
    recursive(t);
    cout<<answer<<endl;

    return 0;
}