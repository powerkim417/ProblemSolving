#include <iostream>

using namespace std;

/* a에 b를 c번 xor 하는 연산인데,
xor은 결합법칙이 성립되고
b xor b = 0 이므로
c가 짝수일 경우는 a xor 0
c가 홀수일 경우는 a xor b 만 남게 된다
*/
int main(void){
    int a,b,c;
    // 1101
    //   11
    // 1110
    cin>>a>>b>>c;
    if (c%2==0) cout<<(a ^ 0);
    else cout<<(a ^ b);
    return 0;
}