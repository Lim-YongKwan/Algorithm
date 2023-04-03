#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<tuple>
#include<map>

#define endl "\n"

using namespace std;

vector<string> split(string str, char delimeter){
    vector<string> answer;
    string  buffer;
    istringstream iss(str);

    while(getline(iss, buffer , delimeter)){
        answer.push_back(buffer);
    }

    return answer;
}

int main(){

    map<string, tuple< int ,int ,int> > match;
    map<string,tuple< int, int, int> >::iterator iter;
    tuple< int, int, int> t1;

    for(int i = 0;i<4;i++){
        string temp;
        cin >> temp;
    }

    for(int i = 0;i<7;i++){
        string s1, s2;
        cin>>s1>>s2;
        int temp_1, temp_2, temp_3;
        cin>>temp_1>>temp_2>>temp_3;
        // make_tuple(s2,10,10,10);
        // match.insert(make_pair(s1,temp_1));
        // t1 = make_tuple(s2, temp_1, temp_2, temp_3);
        match[s1] = make_tuple(s2, temp_1, temp_2, temp_3);
    }

    // for(iter = match.begin(); iter != match.end(); iter++){
    //     cout<< iter->first<<" "<< iter->second <<endl;
    // }

    return 0;
}