#include <iostream>
#include <string>
using namespace std;

string find_count(int n){
    string answer = "";
    int count = 0;

    for(int i = 666;;i++){
        answer = to_string(i);

        for(int j = 0;j<answer.length() - 2;j++){
            if(answer[j] == '6' && answer[j + 1] == '6' && answer[j + 2] == '6'){
                count++;
                break;
            }
        }
        if(count == n){
            return answer;
        }
    }

    return 0;
}

int main(){
    int n;
    cin>>n;

    string answer = "";
    answer = find_count(n);
    cout<<answer<<endl;



    return 0;
}