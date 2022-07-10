#include <iostream>

using namespace std;

// Greedy 를 이용한 풀이
// 가장 오른쪽의 1을 떼주는게 2를 나누는거보다 더 빨리 떨어지므로 우선
// 두 작업 다 수를 감소시키는 작업인데,
// 변환 중 두 방법이 모두 불가능(1의 자리가 1이 아니거나 수 전체가 홀수인 경우)한 경우거나
// 중간값이 a보다 작아진다면 불가능
int main(void){
    int a,b;
    cin>>a>>b;
    int answer = 1;
    while (a<=b){
        if (a==b) {
            cout<<answer;
            return 0;
        }
        if (b%10==1) {
            b /= 10;
            answer++;
        }
        else if (b%2==0) {
            b /= 2;
            answer++;
        }
        else {
            cout<<"-1";
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}