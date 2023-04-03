#include<iostream>
#include<sstream>
#include<vector>
#define endl "\n"

using namespace std;

vector<string> split(string str, char delimeter){
    vector<string> answer;
    stringstream ss(str);
    string temp;

    while(getline(ss, temp, delimeter)){
        answer.push_back(temp);
    }
    return answer;
}

vector<string> split_2(string str, char delimeter){
    vector<string> result;

    stringstream ss(str);
    string buffer;

    while(getline(ss,buffer,delimeter)){
        result.push_back(buffer);
    }
    
    return result;
}

int main(){
    string test;
    getline(cin, test);
    vector<string> result = split(test, ' ');

    // cout<<result[0]<<endl;

    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<endl;
    }

    return 0;
}