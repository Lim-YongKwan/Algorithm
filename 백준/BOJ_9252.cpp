#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"

using namespace std;

int lcs[1001][1001];
string str_lcs[1001][1001];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s1;
    string s2;
    cin>>s1>>s2;

    int s1_size = s1.size();
    int s2_size = s2.size();

    for(int i = 1; i <= s1_size; i++){
        for(int j = 1; j <= s2_size; j++){
            if(s1[i - 1] == s2[j - 1]){
                //둘이 같다면
                //좌측 상단 + 1을 하자.
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
            }
            else {
                //아니라면 위나 좌측중 더 긴 문자열 가져오기.
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
    }

    int save_temp = lcs[s1_size][s2_size];

    string answer = "";

    int x1 = s1_size;
    int y1 = s2_size;

    for(int row = s1_size; row >= 1; row--){
        for(int col = y1; col >= 1; col--){
            if(lcs[row][col] == lcs[row - 1][col]){
                    y1 = col;
                    break;
            }
            else if(lcs[row][col] == lcs[row][col - 1]) {
                continue;
            }
            else {
                answer = s1[row - 1] + answer;
            }
        }
    }


    cout<<lcs[s1_size][s2_size]<<endl;
    cout<<answer<<endl;

    return 0;
}