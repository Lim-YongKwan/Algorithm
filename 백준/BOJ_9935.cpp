#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main(){
    string s;
    cin>>s;
    string bomb;
    cin>>bomb;

    string s3;
    
    for(int i = 0;i<s.size();i++){
        s3.push_back(s[i]);
            if(s3.size() >= bomb.size()){
                if(s3.substr(s3.size() - bomb.size(), bomb.size()) == bomb){
                    s3.erase(s3.size() - bomb.size(),bomb.size());
                }
            }
        
    }

    if(s3.size() <= 0){
        cout<<"FRULA"<<endl;
    }
    else{
        cout<<s3<<endl;
    }

    return 0;
}