#include<string>
#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int keyboard[13][13];

int solution(vector<int> music){
    int answer = 0;
    
    keyboard[1][2] = 1;
    keyboard[1][3] = 1;
    
    keyboard[2][1] = 1;
    keyboard[2][3] = 1;

    keyboard[3][1] = 1;
    keyboard[3][2] = 1;
    keyboard[3][4] = 1;
    keyboard[3][5] = 1;

    keyboard[4][3] = 1;
    keyboard[4][5] = 1;

    keyboard[5][3] = 1;
    keyboard[5][4] = 1;
    keyboard[5][6] = 1;
    keyboard[5][7] = 1;

    keyboard[6][5] = 1;
    keyboard[6][7] = 1;

    keyboard[7][5] = 1;
    keyboard[7][6] = 1;
    keyboard[7][8] = 1;

    keyboard[8][7] = 1;
    keyboard[8][9] = 1;
    keyboard[8][10] = 1;
    
    keyboard[9][8] = 1;
    keyboard[9][10] = 1;
    keyboard[10][8] = 1;
    keyboard[10][9] = 1;
    keyboard[10][11] = 1;
    keyboard[10][12] = 1;
    keyboard[11][10] = 1;
    keyboard[11][12] = 1;
    keyboard[12][10] = 1;
    keyboard[12][11] = 1;

    int now_music = 1;
    for(int n = 0;n<music.size();n++){
        queue<pair<int, int> > nc;
        nc.push(make_pair(now_music,0));
        now_music = music[n];
        while(nc.size() > 0){
            if(nc.front().first == now_music){
                answer += nc.front().second;
                break;
            }
            for(int i = 1;i<=12;i++){
                if(keyboard[nc.front().first][i] == 1){
                    // cout<<"nc.first : "<<nc.front().first<<" nc.front().second: "<<nc.front().second<<endl;
                    nc.push(make_pair(i,nc.front().second + 1));
                }
            }
            nc.pop();
            // cout<<"-------------"<<endl;
        }
    }
    return answer;
}

int main(){
    vector<int> music(4,0);
    for(int i = 0;i<4;i++){
        cin>>music[i];
    }
    cout<<solution(music);
    return 0;
}