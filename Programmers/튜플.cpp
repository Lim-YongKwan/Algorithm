#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <stack>
#include <map>
using namespace std;

vector<int> total[100001];
string str;
int max_point;

void split(string s){
    string buffer;
    vector<int> answer;
    istringstream iss(s);
    char delimeter = ',';
    int result = 0;
    while(getline(iss,buffer,delimeter)){
        answer.push_back(stoi(buffer));
        result++;
    }
    total[result] = answer;
    max_point = max(max_point,result);
    return;
}

vector<int> solution(string s) {
    vector<int> answer;    
    int startPoint;
    for(int i = 1;i<s.size() - 1;i++){
        if(s[i] == '{'){
            startPoint = i;
        }
        else if(s[i] == ','){
        }
        else if(s[i] == '}'){
            // str = substr()으로 시작인덱스 ,끝 인덱스 파악.
            //split으로 나누자.
            string temp;
            temp = s.substr(startPoint + 1,i - startPoint - 1);
            split(temp);
            // split(temp);
        }
    }
    
    //1. vector<vector<int > > 를 만들어서 제일 앞의 숫자는 해당 열의 숫자 카운트.
    //뒤에는 숫자들을 넣자.
    //2. 111같은 경우에는 string에서 넘어올때 
    vector<int>::iterator it;
    
    for(int i = 1;i<=max_point;i++){
        for(int j = 0;j<total[i].size();j++){
            it = find(answer.begin(),answer.end(),total[i][j]);
            if(it == answer.end()){
                answer.push_back(total[i][j]);
            }
        }
    }
    
    return answer;
}