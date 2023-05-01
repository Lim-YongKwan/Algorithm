#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> image) {
    vector<vector<int>> answer(image.size(),vector<int>(image[0].size() * 2,0));

    for(int i = 0;i<image.size();i++){
        for(int j = 0;j<image[i].size();j++){
            answer[i][j] = image[i][j];
        }
    }

    int count = 0;
    for(int i = 0;i<image.size();i++){
        count = image[i].size();
        for(int j = image[i].size() - 1;j>= 0;j--){
            answer[i][count] = image[i][j];
            count++;
        }
    }

    for(int i = image.size() - 1;i>= 0;i--){
        answer.push_back(answer[i]);
    }

    return answer;
}