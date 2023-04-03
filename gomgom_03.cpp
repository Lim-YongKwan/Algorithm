#include <iostream>

using namespace std;

int main(){
    int chicken_gom, pizza_gom, burger_gom;
    int chicken,pizza,burger;
    cin>>chicken_gom>>pizza_gom>>burger_gom;
    cin>>chicken>>pizza>>burger;

    if(chicken - chicken_gom > 0){
        pizza += (chicken - chicken_gom) / 3;
        chicken = chicken_gom + (chicken - chicken_gom) % 3;
    }
    if(pizza - pizza_gom > 0){
        burger += (pizza - pizza_gom) / 3;
        pizza = pizza_gom + (pizza - pizza_gom) % 3;
    }
    if(burger - burger_gom > 0){
        chicken += (burger - burger_gom) / 3;
        burger = burger_gom + (burger - burger_gom) % 3;
    }

    int answer = 0;

    if(chicken < chicken_gom){
        answer += chicken;
    }
    else{
        answer += chicken_gom;
    }
    if(pizza < pizza_gom){
        answer += pizza;
    }
    else{
        answer += pizza_gom;
    }
    if(burger < burger_gom){
        answer += burger;
    }
    else{
        answer += burger_gom;
    }

    cout<<answer<<endl;
    return 0;
}