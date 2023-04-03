#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,k;
vector<long long> first_vector(30001,0);
vector<long long> second_vector(30001,0);

long long binary_sum(long long mid, int i){ //i번째 행렬에서 mid보다 작은 숫자가 몇개가 있는지 파악하는 함수.

    long long answer = 0;
    long long start = 0;
    long long high = n;
    long long middle = 0;

    while(start<=high){
        middle = (start + high + 1) / 2;
        if(first_vector[middle] * second_vector[i] <= mid){ //second_vector[i]는 i번째 행렬에 곱해지는 값을 의미.
                                                            //first_vector[middle]을 통해서 위치 파악.
                                                            //행렬을 곱해서 나온 값이 만일 mid값보다 작거나 같다면
            answer = middle;
            start = middle + 1;
        }
        else{ // mid값보다 크다면
            high = middle - 1;
        }
    }
    return answer;
}

long long vector_sum(long long mid){
    long long answer = 0;
    for(int i = 1;i<=n;i++){ //1부터 n까지 각 행에 몇개를 더할 수 있는지 판별.
        answer += binary_sum(mid,i); //lower bound로 풀고 싶었지만 그러자니 행렬을 만들어야 하고 그러면 시간초과가 나서 따로 구현했음.
    }
    return answer;
}

int main() {
    cin>>n>>k;

    for(int i = 1;i<=n;i++){
        cin>>first_vector[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>second_vector[i];
    }

    //이분 탐색을 쓰기 위해서 정렬을 해주자.
    sort(first_vector.begin() + 1,first_vector.begin() + n + 1);
    sort(second_vector.begin() + 1,second_vector.begin() + n + 1); 

    long long start = first_vector[1] * second_vector[1]; //시작은 제일 작은값으로 시작하자.
    long long high = first_vector[n] * second_vector[n]; //끝은 가장 높은 값.
    long long mid = 0; //mid 설정.
    long long answer = 0; //answer

    while(start<=high){ //이분 탐색 시작. 
        mid = (start + high) / 2; 
        if(vector_sum(mid) < k){ //두 벡터를 곱해서 나온 벡터에서 mid값 이하의 숫자가 k개 이하라면.
            start = mid+1; //start를 1 증가시켜주자.
        }
        else{ //아니라면
            answer = mid; //answer = mid
            high = mid - 1; //high 를 1 빼주자.
        }
    }
    cout<<answer<<endl; //닶 출력.

    return 0;
}