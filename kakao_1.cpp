#include <string>
#include <iostream>
#include <vector>
#include<sstream>
#include <map>

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

vector<int> split_2(string str, char delimeter){
    istringstream iss(str);
    string buffer;

    vector<int> result;

    while(getline(iss,buffer, delimeter)){
        result.push_back(stoi(buffer));
    }
    return result;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<string> dayType;
    vector<vector<int> > termDate;

    for(int i = 0;i<privacies.size();i++){
        vector<string> temp = split(privacies[i],' ');
        dayType.push_back(temp[1]);
        vector<int> temp_2 = split_2(temp[0],'.');
        termDate.push_back(temp_2);
    }

    map<string,int> privacy;
    for(int i = 0;i<terms.size();i++){
        vector<string> temp;
        temp = split(terms[i],' ');
        privacy.insert({temp[0],stoi(temp[1])});
    }

    vector<int> temp_today = split_2(today,'.');

    for(int i = 0;i<termDate.size();i++){
        termDate[i][1] += privacy.find(dayType[i])->second;

        if(termDate[i][1] > 12){
            termDate[i][0] = termDate[i][0] + ( (termDate[i][1] -1) / 12);
            termDate[i][1] %= 12;
            if(termDate[i][1] == 0){
                termDate[i][1] = 12;
            }
        }
        
        if(termDate[i][0] < temp_today[0]){
            answer.push_back(i+1);
        }
        else if(termDate[i][0] == temp_today[0] and termDate[i][1] < temp_today[1]){
            answer.push_back(i+1);
        }
        else if(termDate[i][0] == temp_today[0] and termDate[i][1] == temp_today[1] and termDate[i][2] <= temp_today[2]){
            answer.push_back(i+1);
        }
        
    }

    return answer;
}