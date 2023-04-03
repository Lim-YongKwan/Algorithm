#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;

    //가장 먼 곳에서부터 해치우자!
    long long nowlocate = 0;
    long long locate = n-1;
    long long passenger = cap;
    long long total = 0;

    for(int i = 0;i<deliveries.size();i++){
        total += deliveries[i];
    }

    for(int i = 0;i<pickups.size();i++){
        total += pickups[i];
    }

    while(total > 0){
        if(total< 0)
            break;

        passenger = cap;
        nowlocate = 0;
        
        for(long long i = locate;i>=0;i--){
            if(passenger <= 0){
                break;
            }

            if(deliveries[i] <= passenger and deliveries[i] > 0){//만약 해당 위치보다 태울 사람이 많다면
                total -= deliveries[i];
                passenger -= deliveries[i];
                deliveries[i] = 0;
                nowlocate = max(i,nowlocate);            
            }
            else if(passenger > 0 and passenger < deliveries[i]) {
                total -= passenger;
                passenger = 0;
                deliveries[i] -= passenger;
                nowlocate = max(i,nowlocate);            
            }
        }

        long long nowlocate_2 = nowlocate;
        passenger = cap;
        nowlocate = 0;

        for(long long i = locate;i>=0 ;i--){
            if(passenger <= 0){
                break;
            }

            if(pickups[i] <= passenger and pickups[i] > 0){
                total -= pickups[i];
                passenger -= pickups[i];
                pickups[i] = 0;
                nowlocate = max(i,nowlocate);            
            }
            else if(passenger > 0 and passenger < pickups[i]){
                total -= passenger;
                passenger = 0;
                pickups[i] -= passenger;
                nowlocate = max(i,nowlocate);            
            }
        }

        locate = max(nowlocate , nowlocate_2);
        answer =answer + (max(nowlocate,nowlocate_2)+1) * 2;
        cout<<max(nowlocate,nowlocate_2)+1<<endl;
    }

    return answer;
}