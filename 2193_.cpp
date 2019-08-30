#include <iostream>
#include <cmath>
using namespace std;

long long int num[91] = {0, };
void dp(int i){
    if (i==1 || i==2) num[i] = 1;
    else if (i==3) num[i] = 2;
    else { // 4 이상인 경우
        // 10 이 먼저 오고, 나머지 n-2자리 중
        // 1은 0개 ~ 최대 (n-2+1)/2 개이고,
        // 겹치는걸 막기 위해
        // 이미 배정된 0 사이의 간격에 하나씩 들어가는 식으로 계산
    }
}

int main(void){
    int N;
    cin>>N;
    for (int i=1 ; i<=N ; i++) dp(i);
    cout<<num[N];
}