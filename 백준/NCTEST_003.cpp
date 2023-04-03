#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>

using namespace std;

int solution(vector<int> paper, int n){
    int answer = 0;

    int temp1 = 0;
    int temp2 = 0;
    
    while(n--){
        for(int i = 0; i < paper.size(); i++){
            for(int k = i + 1; k < paper.size(); k += pow(2,k)){
                if(answer<paper[i] + paper[k]){
                    answer =paper[i] + paper[k];
                    temp1 = k;
                    temp2 = i;
                }
            }
        }
        paper[temp1] = answer;
        paper.erase(paper.begin() + temp2);

        for(int i = 0;i<paper.size();i++){
            cout<<"paper : "<<paper[i]<<" ";
        }
    }

 

    return answer;
}

int main(){
    vector<int> paper;
    for(int i = 0;i<5;i++){
        int temp;
        cin>>temp;
        paper.push_back(temp);
    }
    int n = 2;
    cout<<solution(paper,2);
    return 0;
}