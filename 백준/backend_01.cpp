#include <string>
#include <vector>
#include<iostream>
#include<sstream>

using namespace std;

vector<string> split(string str, char delimeter){
    istringstream iss(str);
    string buffer;
    vector<string> result;

    while(getline(iss,buffer, delimeter)){
        result.push_back(buffer);
    }
    return result;
}

string solution(vector<string> registered_list, string new_id) {
    string answer = "";

    int testcase = registered_list.size();
    while(testcase--){
        vector<string> client;
        string reg = registered_list[0];
        for(int i = 0;i<reg;i++){
            if(reg[i] <= 57){
                client = split(reg,reg[i]);
            }
        }
        vector<string>::iterator iter;
        iter = find(registered_list.begin(),registered_list.end(),new_id);
        if(iter != registered_list.end()){
            cout<<"find : "<<endl;
            int temp = stoi(client[1]);
            
        }
        else{
            cout<<"now find : "<<endl;
            answer = new_id;
        }
        
    }

    return answer;
}

int main(){
    vector<string> registered_list = {"card", "ace13", "ace16", "banker", "ace17", "ace14"};
    string new_id = "ace15";
    string answer = "ace15";
    if(solution(registered_list,new_id) != answer ){
        cout<<"wrong : "<<endl;
    }
    else{
        cout<<"right : "<<endl;
    }
    return 0;
}