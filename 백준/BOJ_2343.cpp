#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> lecture;

int bluray(long long mid){ //bluray를 몇개를 만들 수 있는지를 판별하는 함수.
    int answer = 0;
    long long count = 0;

    for(int i = 0; i < n - 1 ;i++){ //뒤의 값을 더했을때 더 커지는 경우를 파악하기 위해서 n-1 까지만 돌리기로 함.
        count += lecture[i];

        if(count >= mid){ //만일 count가 mid보다 크거나 같다면
            if(count % mid == 0){ //나머지가 0이라면
                answer += (count / mid); //몫만큼 더해주자.
            }
            else{//나머지가 0이 아니라면
                answer += (count / mid) + 1; //몫에다가 1을 더해주자.
            }
            count = 0; //count 초기화 시키기.
        }
        else if(count + lecture[i + 1] > mid){ //만일 다음 강의를 더했을 때 초과가 된다면
            answer++; //answer에 1을 더해주고
            count = 0; //count를 초기화 시키자.
        }
    }

    //마지막 부분 더해주기.
    //위와 비슷한 형식이다.
    count += lecture[n - 1];
    if(count > mid){
        if(count % mid == 0){
            answer += (count / mid);
        }
        else{
            answer += (count / mid) + 1;
        }
    }
    else if(count <= mid){
        answer++;
    }

    //이렇게 총 몇개의 bluray가 만들어지는지를 파악한 뒤에 return을 해주자.
    return answer;
}

int main(){
    cin>>n>>m;
    lecture.resize(n);

    long long total = 0;

    for(int i = 0;i<n;i++){
        cin>>lecture[i];    
        total += lecture[i];
    }

    long long start = 1;
    long long high = total;
    long long mid = 0;
    long long answer = 0;
    long long count = 0;

    while(start<=high){ //이분 탐색 시작
        mid = (start + high) / 2;
        count = bluray(mid); //현재 값으로 몇개를 나눌 수 있는지 파악해보자.
        if(count > m){ //만일 파악한 값이 더 크다면
            start = mid + 1; //mid값을 증가시키자. mid 값이 커진다면 bluray 용량이 커지니 count가 작아진다.
        }
        else if(count <= m){ //만일 파악한 값이 더 작거나 같다면
            answer = mid; //answer로 저장해두고
            high = mid - 1; //용량을 더 줄이자.
        }
    }

    cout<<answer<<endl;

    return 0;
}