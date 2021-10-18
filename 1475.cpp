#include <iostream>

using namespace std;
   
int need[9] = {}; // 9가 필요한 경우 need[6]에 추가

int main(void){
    int n;
    cin>>n;
    while (n>0){
        if (n%10==9) need[6]++;
        else need[n%10]++;
        n /= 10;
    }
    need[6] = (need[6]+1)/2;
    int answer = 0;
    for (int i=0 ; i<9 ; i++){
        if (need[i]>answer) answer = need[i];
    }
    cout<<answer;
    return 0;
}