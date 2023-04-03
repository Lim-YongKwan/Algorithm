#include <iostream>

using namespace std;

int main (){
    int n;
    cin>>n;
    
    int answer = 0; // temp가 n이 될 때까지 걸리는 시간.
    int temp = n; // n의 다음 값들을 temp로 지정.
    int units = 0; // 1의 자리 숫자.

    do{ //처음에 temp를 n으로 두었기에 do-while문을 선택.
        answer++; //count 증가 : 해당 
        units = temp % 10; //units 는 temp의 1의 자리 숫자.
        if(temp < 10){ //만일 temp가 10보다 작다면
            temp = temp * 10 + temp; //temp는 temp의 1의 자리 숫자를 10배하고 자기를 한번 더 더하자.
        }
        else{ //10보다 작다면
            temp = (temp / 10) + (temp % 10); //temp 는 10으로 나눈 몫과 10의 나머지를 더하자.
        }
        //해당 과정이 끝났뒤에 
        if(temp < 10){ //10보다 작다면
            temp = (units * 10) + temp; //temp는 이전의 1의 자리 숫자를 10배 한 값과 자신을 더한값.
        }
        else{ //10보다 크다면
            temp = (units * 10) +(temp % 10); //이전의 1의 자리 숫자를 10배 한 값과 지금의 1의 자리를 더한 값.
        }
    }while(temp != n); //만일 temp가 n이라면 멈추기.

    cout<<answer<<endl;
    return 0;
}