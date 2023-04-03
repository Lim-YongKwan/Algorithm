#include<iostream>
#include<vector>
#include<istream>
#include<sstream>
#include <regex>

using namespace std;

vector<string> split_3(string str, char delimeter){
    vector<string> answer;
    string buffer;
    istringstream iss(str);
    while(getline(iss,buffer,delimeter)){
        answer.push_back(buffer);
    }
    return answer;
}


vector<string> split(string str, char delimeter){
    istringstream iss(str);
    string buffer;

    vector<string> result;

    while(getline(iss,buffer, delimeter)){
        result.push_back(buffer);
    }
    return result;
}

vector<string> split_2(string str, string delimeter){
    vector<string> v;
    char *c = strtok((char*)str.c_str(), delimeter.c_str());
    while(c){
        v.push_back(str);
        str = strtok(NULL, delimeter.c_str());
    }
    return v;
}

int main(){
    // string str;
    // cin>>str;

    vector<vector<string> > temp(5,vector<string>(5));
    vector<string> temp_2;
    
    for(int i = 0;i<3;i++){
        string s;
        getline(cin,s);
        temp[i] = split_3(s,' ');
    }

    for(int i = 0;i<3;i++){
        for(int j = 0; j<3;j++){
            cout<<temp[i][j];
        }
        cout<<endl;
    }

    // vector<string> answer = split_2(str, "+-*");

    // for(int i = 0;i<answer.size();i++){
    //     cout<<answer[i]<<" ";
    // }

    return 0;
}