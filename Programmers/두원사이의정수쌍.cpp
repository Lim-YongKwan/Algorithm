#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long binary(long long axisY, long long r, int dir){
    //r 은 원의 반지름.
    //axisY는 y축의 제곱값이다.
    
    long long answer = 0;
    long long start = 1;
    long long end = r;
    long long middle = 0;
    
    while(start <= end){
        middle = (start + end) / 2;
        
        if(middle * middle > axisY){
            end = middle - 1;
        }
        else if(middle * middle < axisY){
            start = middle + 1;
            answer = middle;
        }
        else if(middle * middle == axisY){
            //dir이 1이라면 1개를 제거해주고 돌려주자.
            //dir이 1일때 middle * middle => Y축이라는건 해당 dir의 끝에 점이 1개 추가로 있다는 의미이다.
            if(dir == 1){
                return middle - 1;
            }
            return middle;
        }
    }
    return answer;
}

long long solution(int r1, int r2) {
    long long answer = 0;
    //long long을 하는 이유는 r1,r2가 최대 1,000,000이라서 제곱을 하면 int값을 넘을 수 있기 때문.
    long long r;
    //y축의 제곱을 담당할 변수
    long long axisY1 = 0;
    long long axisY2 = 0;
    //y^2 = a^2 - x^2이니
    //1. y^2의 값을 얻은 후
    //2. 해당 값이 정수로 몇이 나오는게 최대인지 파악하면 해당 원의 x축에 있는 점을 알 수가 있다.
    
    r = r2;
    for(long long i = 0;i<r2;i++){
        axisY2 = r * r - i * i;
        answer += binary(axisY2,r,2);
    }
    
    r = r1;
    for(long long i = 0;i<r1;i++){
        axisY1 = r * r - i * i;
        answer -= binary(axisY1, r,1);
    }
    
    //사분면이 있으니 4를 곱해주자.
    answer *= 4;
    
    return answer;
}