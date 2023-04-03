#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string s, char delimeter){
    vector<string> answer;
    string temp;
    stringstream ss(s);

    while(getline(ss,temp,delimeter)){
        answer.push_back(temp);
    }
    return answer;
}

int main(){
    int n;
    cin>>n;
    int answer = 0;

    for(int i = 0;i<n;i++){
        string temp;
        cin>>temp;
        vector<string> result = split(temp,'-');
        if(stoi(result[1])<=90){
            answer++;
        }
    }
    cout<<answer<<endl;
    return 0;
}