#include <iostream>
#include <sstream>
#include <vector>
#define endl "\n"

using namespace std;

vector<string> split(string str,char delimeter){
    vector<string> answer;
    istringstream iss(str);
    string buffer;

    while(getline(iss,buffer,delimeter)){
        answer.push_back(buffer);
    }

    return answer;
}

int main(){
    string s;
    while(getline(cin,s)){
        if(s == "# 0 0"){
            break;
        }
        vector<string> result;
        result = split(s,' ');
        if(stoi(result[1]) > 17 || stoi(result[2])>= 80){
            cout<<result[0]<<" Senior"<<endl;
        }
        else{
            cout<<result[0]<<" Junior"<<endl;
        }

    }
    return 0;
}