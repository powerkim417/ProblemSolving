#include <iostream>
using namespace std;
int main(void){
    /*
    if 4k
    상1 -> 창3
    상3 -> 창1. 창 win

    if 4k+1
    상1 -> 창1 -> 상3
    상1 -> 창3 -> 상1. 상 win

    if 4k+2
    상1 -> 창1. 
    상3 -> 창3. 창 win

    if 4k+3
    상3 -> 창1 -> 상3
    상3 -> 창3 -> 상1. 상 win
    */
    long long int n;
    cin>>n;
    if (n%2 == 0) cout<<"CY";
    else cout<<"SK";
    return 0;
}