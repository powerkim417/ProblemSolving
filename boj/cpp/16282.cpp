#include <iostream>

using namespace std;

int main(void){
    long long int n;
    cin>>n;
    /*
    1번 나누는 경우
    1 먼저 두고,
    2 1 4 가 최대(7)
    2번 나누는 경우
    1 1 먼저 두고,
    6 1 3 1 12가 최대(23)
    3번 나누는 경우
    1 1 1 먼저 두고,
    16 1 4 1 8 1 32가 최대(63)
    ...
    i번 나누는 경우
    우선 1이 i개 있고,
    (i+1) 부터 시작해서 2배씩 증가하는 수가 총 (i+1)개.
    즉 초항 (i+1), 공비 2, 항수 (i+1)의 등비수열이 된다.
    즉 총합은 i + (i+1)(2^(i+1)-1)
    = (i+1)(2^(i+1))-1
    
    문제에서 n이 주어지면 n<=(i+1)(2^(i+1))-1을 만족하는
    가장 작은 i가 답이 된다.
    */
    long long int i = 1;
    while (1){
        // long long int의 연산이므로 1도 long long으로 캐스팅 해줘야 한다..
        if (n <= (i+1LL)*(1LL<<(i+1LL)) - 1LL){
            break;
        }
        i++;
    }
    cout<<i;
}