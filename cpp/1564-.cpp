#include <iostream>
#include <iomanip>

using namespace std;

int main(void){
    int N;
    cin>>N;
    // 0의 갯수는 팩토리얼을 소인수분해 했을 때 5의 갯수
    long long int answer = 9*8*7*6*5*4*3*2; // 362880
    answer /= 10; // 5가 하나이므로
    for (int i=10 ; i<=N ; i++){
        answer *= i;
        if (i%5==0) answer /= 10;
        if (i%25==0) answer /= 10;
        if (i%125==0) answer /= 10;
        if (i%625==0) answer /= 10;
        if (i%3125==0) answer /= 10;
        if (i%15625==0) answer /= 10;
        if (i%78125==0) answer /= 10;
        if (i%390625==0) answer /= 10;
        // i가 5의 거듭제곱의 배수인 경우 그 곱해주는 5의 갯수만큼 0이 생기므로 그걸 빼주는 작업
        // N<=1000000 이므로 그 이하 가장 큰 5의 거듭제곱인 390625까지만 본다.

        /* 갖고가야 할 나머지의 길이에 대한 고찰
        50272 * 9500 = 4'77584'(000)
        150272 * 9500 = 14'27584'(000)
        즉 i의 유효숫자가 적을 때는 끝 5자리가 바뀔 수 있으므로
        */
        
        // 몇으로 나눠줘야 할까...
        answer %= 1000000000000000000;
    }
    // <iomanip> 라이브러리를 이용한 zero-padding
    cout<<setfill('0')<<setw(5)<<answer%100000;
}