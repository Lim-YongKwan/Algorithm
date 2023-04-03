#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<pair<int, int> > answer;

void stack_clear(stack<pair<int, int> > & building){
    while(building.size() > 0){
        building.pop();
    }
    return;
}

void stack_count(stack<pair<int, int> >& building, int now){

    while(building.size()>0){
        if(now < building.top().first){
            return;
        }
        building.pop();
    }
    return;
}

void stack_output(stack<pair<int, int> > building){
    cout<<"-----building-----"<<endl;
    while(building.size() > 0 ){
        cout<<building.top().first<<" " <<building.top().second<<endl;
        building.pop();
    }
    return;
}

void output(int n){
    for(int i = 0;i<answer.size();i++){
        if(answer[i].first == 0){
            cout<<"0"<<endl;
            continue;
        }
        cout<<answer[i].first<<" "<<answer[i].second<<endl;
    }}

int main(){
    int n;
    cin>>n;
    vector<pair<int, int> > tower(n);
    for(int i = 0;i<n;i++){
        cin>>tower[i].first; // 건물 높이.
        tower[i].second = i + 1; //건물숫자 표시를 위해서 + 1 체크해줌.
    }

    answer.resize(n); //answer 답변 크기 resize
    stack<pair<int, int> > building; // 첫번째는 높이 두번째는 건물 숫자.

    building.push(make_pair(tower[0].first,1)); // building에 tower[0]의 높이와 1을 넣어주자.

    for(int i = 1;i<n;i++){
        if(building.top().first < tower[i].first) { //만일 stack의 가장 위의 높이보다 현재 tower의 높이가 더 크다면
            //stack의 내부에 숫자를 넣어주는 로직.
            stack_count(building, tower[i].first);
            answer[i].first += building.size();
            if(building.size() > 0) {
                answer[i].second = building.top().second;
            }
            building.push(make_pair(tower[i].first, tower[i].second));
        }
        else{
            answer[i].first += building.size();
            answer[i].second = building.top().second;
            building.push(make_pair(tower[i].first, tower[i].second));
        }
    }

    stack_clear(building);
    building.push(make_pair(tower[n-1].first,n));

    for(int i = n - 2;i>=0;i--){
        if(building.top().first < tower[i].first) { //만일 stack의 가장 위의 높이보다 현재 tower의 높이가 더 크다면
            //stack의 내부에 숫자를 넣어주는 로직.
            stack_count(building, tower[i].first);
            answer[i].first += building.size();
            if(building.size() > 0){
                answer[i].second = min(answer[i].second, building.top().second);
            }
            building.push(make_pair(tower[i].first, tower[i].second));
        }
        else{
            cout<<"building : "<<building.top().first<<" "<<building.top().second<<endl;
            answer[i].first += building.size();
            if(building.size() > 0){
                answer[i].second = min(answer[i].second, building.top().second);
            }
            building.push(make_pair(tower[i].first, tower[i].second));
        }
    }

    output(n);

    return 0;
}