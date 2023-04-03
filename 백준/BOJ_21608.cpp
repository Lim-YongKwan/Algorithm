#include <iostream>
#include <vector>
#include <map>

using namespace std;

void solve(vector<vector<int> > shark, int n){
    vector<vector<int> > student(n , vector<int>(n,0));

    map<int, pair<int,int> > shark_seat;

    if(shark.size() > 2){
        student[1][1] = shark[0][0];
        shark_seat.insert(make_pair(shark[0][0], make_pair(1,1)));
    }
    else if(shark.size() <= 2){
        student[0][0] = shark[0][0];
        shark_seat.insert(make_pair(shark[0][0],make_pair(0,0)));
    }

    vector<pair<pair<int, int >, int> > common_seat;

    for(int i = 1;i<n*n;i++){
        for(int j = 1;j<5;j++){
            auto item = shark_seat.find(shark[i][j]);
            if(item != shark_seat.end()){
                common_seat.push_back(make_pair(make_pair(0,0),0));
            }
            else{
                //아직 모름. 아마 제일 처음부분부터 돌려볼 것 같음.
                //빈칸이 가장 많고 앞쪽으로 구현.
            }
        }
    }
    return;
}

int main(){
    int n;
    cin>>n;
    
    vector<vector<int> > shark(n * n,vector<int>(5,0));

    for(int i = 0;i<n * n;i++){
        for(int j = 0;j<5;j++){
            cin>>shark[i][j];
        }
    }
    solve(shark, n);

    return 0;
}