#include <iostream>

using namespace std;

int main(void){
    int a,b,c;
    cin>>a>>b>>c;
    /* 하루에 a장, 7일차에 b장 보너스. c장을 얻기 위한 최소 출석일
    2 2 2 2 2 2 2
                3 일 때
    1~6일차에 답이 나오는 범위: 1~12(0 초과 6a 이하)
    7일차에 답이 나오는 범위: 13~17(6a 초과 7a+b 이하)
    즉 c가 7a+b 단위로 규칙이 있음
    c를 7a+b 로 나눈 나머지가 0이거나 6a 초과면 7의 배수차에 답이 나오고,
    아닌 경우 7의 배수가 아닌 일차에 답이 나옴
    */
    int bonused_weeks = (c-1)/(7*a+b); // 마지막 주 이전까지의 보너스 횟수
    int rem = c - bonused_weeks*(7*a+b);
    if (rem > 6*a) // 7일차
        cout<<(bonused_weeks*7 + 7);
    else { // 1~6일차
        cout<<(bonused_weeks*7 + (rem-1)/a+1);
    }

    // // 하루에 a장, 7일차에 b장 보너스. c장을 얻기 위한 최소 출석일
    // // a a a a a a a+b a a a a ... 이런 식이므로
    // // 총 n일이라면 (n-1)*a + [(n-1)/7]*b < c <= n*a + [n/7]*b
    // // (1) n=7k 일 경우 7ak-a + bk-b < c <= 7ak + bk = k*(7a+b)
    // //     c / (7a+b) <= k < (a+b+c) / (7a+b)
    // // 두 끝의 차는 (a+b)/(7a+b) 이므로 0.xxx.. 즉 두 간격의 차가 0.대 이므로 두 사이에는 하나의 정수만 존재
    // // (2) n=7k+r 일 경우 (7k+r-1)*a + k*b < c <= 7ak+ar+bk = k*(7a+b) + ar
    // //     (c-ar)/(7a+b) <= k < (c+a-ar)/(7a+b)
    // // 이 역시 두 끝의 차가 a/(7a+b) 이므로 위와 같은 경우
    // // ar < 7a+b인 이유? r<7이므로 ar < 7a가 자명
    // int w = 7*a + b;
    // int k, r, n;
    // if (c/w == 0 || c/w > 6*a) { // n=7k
    // // c / (7a+b) <= k < (a+b+c) / (7a+b)
    
    // }
    // else { // n=7k+r
    // // (c-ar)/(7a+b) <= k < (c+a-ar)/(7a+b)

    // }
    // k = c / w;
    // r = (c-k*w) / a;
    // }
    // n = 7*k + r;
    // cout<<n;
}