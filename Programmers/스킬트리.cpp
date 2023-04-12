#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//cbd -> skill_trees[i] 로 파악하는게 아니라 skill_trees[i] -> cbd로 파악을 해야 한다.

bool skillTo(string s1, string s2){
    bool answer = true;
    int count = 0;
    for(int i = 0;i<s2.size();i++){
        for(int j = 0;j<s1.size();j++){
            if(s2[i] == s1[j]){
                if(count != j){
                    return false;
                }
                count++;
            }
        }
    }
    
    return answer;
}

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(int i = 0;i<skill_trees.size();i++){
        bool flag = true;
        flag = skillTo(skill,skill_trees[i]);
        if(flag){
            answer++;
        }
    }
    
    return answer;
}