#include <iostream>

using namespace std;

/*
해법: N*M이 홀수면 1칸 빼고 다 채우며, N*M이 짝수면 다 채울 수 있다!
수학적 증명
1) N(세로)이 짝수일 때
ㅣㅣㅣㅣㅣㅣ
ㅣㅣㅣㅣㅣㅣ 처럼 2*1로 채우면 빈칸 없음이 자명

2) N이 홀수일 때
ㅣㅣㅣㅣㅣㅣ
ㅣㅣㅣㅣㅣㅣ
ㅡㅡㅡ 처럼 채우는데,
M마저 홀수라면 맨 마지막 칸에서 한칸이 남을 것이고
M이 짝수라면 한칸도 안남음 
*/

int main(void){
    long long int n,m;
    cin>>n>>m;
    long long int area = n*m;
    cout<<area/2;
}