#include <iostream>

using namespace std;

int main(void){
    int n, l, d;
    cin>>n>>l>>d;
    // 벨소리: 0~1, d~d+1, 2d~2d+1, ...
    // 노래 쉬는시간: l~l+5, 2l+5~2l+10, ..., (n-1)(l+5)-5 ~ (n-1)(l+5), nl+(n-1)5~
    
    // 쉬는시간 5초 안에 벨소리 1초가 들어가 있어야 함
    for (int i=1 ; i<=n-1 ; i++){ // n-1번의 쉬는시간동안
        // i(l+5)-5 ~ i(l+5)
        for (int j=0 ; j<5 ; j++){
            // i(l+5)-5+j 초 시점이 d의 배수인지 확인
            if ((i*l+5*i-5+j)%d == 0) {
                cout<<(i*l+5*i-5+j);
                return 0;
            }
        }
    }   
    // 다 못들으면 음악 끝난 후 첫 벨소리에서 듣게 됨
    // 음악 종료 시각: n*l+(n-1)*5
    int answer = 0;
    while (answer < n*l + (n-1)*5){
        answer += d;
    }
    cout<<answer;
    return 0;
}