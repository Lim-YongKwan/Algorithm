#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//menu, ingredeint, food가 주어진다.
//menu => [{가격,1,0,1..},{가격, 2,0,1}...]
//ingredient => [2,9,2] => 현재 준비되어 있는 재료의 양
//food => [3,3,3] => 최대 준비할 수 있는 menu의 숫자.

//기본적으로 주어진 벡터.
vector<vector<int > > menu;
vector<int> ingredient;
vector<int> food;

vector<int> receipe;
int answer = 0;

void cook(){
    vector<int> ingredient2;
    ingredient2 = ingredient;
    bool flag = true;
    int total = 0;
    for(int i = 0;i<receipe.size();i++){
        //total은 현재 레시피의 크기와 menu의 첫번째, 가격을 곱한 값이다.
        total += receipe[i] * menu[i][0];
        //j를 1부터(menu[i][0] 은 가격이니 1부터 돌린다.
        //1부터 모든 재료를 돌려보자.
        for(int j = 1;j<menu[i].size();j++){
            //ingredient2에서 menu[i][j]와 receipe[i]를 곱한 값이 0이상인지 아닌지 파악하자.
            ingredient2[j - 1] -= (menu[i][j] * receipe[i]);
            //만일 0보다 작다면 해당 레시피는 실패한 레시피다.
            if(ingredient2[j - 1] < 0){
                flag = false;
                break;
            }
        }
        //flag가 false라면 종료하자.
        if(flag == false){
            break;
        }
        //answer는 최댓값.
        answer = max(answer, total);
    }
    return;
}

void dfs(int count){
    //만일 receipe가 food 크기가 된다면
    if(receipe.size() == food.size()){
        cook();
        return;
    }
    //완탐.
    for(int i = 0;i<=food[count];i++){
        receipe.push_back(i);
        dfs(count + 1);
        receipe.pop_back();
    }
    return;
}

void solve(){
    vector<int> temp;
    temp.push_back(5000);
    temp.push_back(2);
    temp.push_back(3);
    temp.push_back(1);
    menu.push_back(temp);
    menu.push_back(temp);
    menu.push_back(temp);
    ingredient.push_back(12);
    ingredient.push_back(20);
    ingredient.push_back(30);
    food.push_back(10);
    food.push_back(3);
    food.push_back(0);
    dfs(0);
    cout<<answer<<endl;
}

int main(){
    solve();

    return 0;
}