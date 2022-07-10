#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    // n = 5a + 3b
    // a+b의 최대를 구함
    int min = 1667; // 나올수 있는 봉지의 최대는 4998을 3으로 나눈 1666에 1을 더한 것
    for (int a=0 ; 5*a<=n ; a++){
        if ((n-5*a)%3 != 0) continue;
        int b = (n-5*a)/3;
        if (a+b<min) min = a+b;
    }
    if (min==1667) cout<<"-1";
    else cout<<min;
}