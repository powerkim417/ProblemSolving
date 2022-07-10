#include <iostream>

using namespace std;

bool map[1023][2045] = {};
bool newmap[1023][2045] = {};

// 1: [1][1],              중심 (0, 0)
// 2: [3][5],              중심 (0+1, 0+2)
// 3: [7][13],             중심 (1+3, 2+4)
// 4: [15][29],            중심 (4+1, 6+8)
// 5: [31]                 중심 (5+15, 14+16)
// 6: [63]                      (20+1)
// 7: [127]                     (21+63)
// 8: [255]                     (84+1)
// 9: [511]                     (85+255)
// 10:[1023][2045]              (340+1, 1022)
// n: [2^n-1][2*(2^n-1)-1] 중심 (???, 2^n-2)

int pow2(int n){
    int ret = 1;
    while (n--) ret *= 2;
    return ret;
}

int r(int n){
    return pow2(n)-1;
}

int c(int n){
    return pow2(n+1)-3;
}

int main(void){
    int n;
    cin>>n;
    map[0][0] = true; // 1단계
    for (int t=2 ; t<=n ; t++){ // 2~n단계
        for (int i=0 ; i<r(t) ; i++){
            for (int j=0 ; j<c(t) ; j++){
                newmap[i][j] = false;
            }
        }
        for (int i=0 ; i<r(t-1) ; i++){ // 전 단계 삼각형 이동
            int low = ((t-1)%2==1) ? r(t-1)-1-i : i;
            int high = ((t-1)%2==1) ? r(t-1)+i : c(t-1)-i;
            int dr = (t%2==1) ? r(t-1) : 1;
            int dc = pow2(t-1);
            for (int j=low ; j<high ; j++){
                newmap[i+dr][j+dc] = map[i][j];
            }
        }

        // map으로 다시 옮기기
        for (int i=0 ; i<r(t) ; i++){
            int low = (t%2==1) ? r(t)-1-i : i;
            int high = (t%2==1) ? r(t)+i : c(t)-i;
            for (int j=0 ; j<c(t) ; j++){
                if (j>=low && j<high) map[i][j] = newmap[i][j];
                else map[i][j] = false;   
            }
        }
        
        // 새 삼각형 입히기(빗변)
        for (int i=0 ; i<r(t) ; i++){
            int low = (t%2==1) ? r(t)-1-i : i;
            int high = (t%2==1) ? r(t)+i : c(t)-i;
            map[i][low] = true;
            map[i][high-1] = true;
        }
        // 새 삼각형 입히기(밑변)
        if (t%2==1){ // 현재 홀수단계면 가장 아래층에 변
            for (int j=0 ; j<c(t) ; j++) map[r(t)-1][j] = true;
        } else { // 짝수단계면 가장 위층에 변
            for (int j=0 ; j<c(t) ; j++) map[0][j] = true;
        }
    }
    if (n%2==1){
        /* 홀수(정삼각형)
        i=0 -> j=r-1 ; i<c-r+1=r

        i -> j=r-1-i ; j<c-r+1+i=r+i

        i=r-2 -> j=1 ; j<c-1
        i=r-1 -> j=0 ; j<c
        */
        for (int i=0 ; i<r(n) ; i++){
            for (int j=0 ; j<r(n)-1-i ; j++) cout<<" ";
            for (int j=r(n)-1-i ; j<r(n)+i ; j++){
                cout<<((map[i][j])?"*":" ");
            }
            cout<<"\n";
        }
    }
    else {
        /* 짝수(역삼각형)
        i=0 -> j=0 ; j<c
        i=1 -> j=1 ; j<c-1

        i -> j=i ; j<c-i

        i=r-1 -> j=r-1 ; i<c-r+1=r
        */
        for (int i=0 ; i<r(n) ; i++){
            for (int j=0 ; j<i ; j++) cout<<" ";
            for (int j=i ; j<c(n)-i ; j++){
                cout<<((map[i][j])?"*":" ");
            }
            cout<<"\n";
        }
    }
    return 0;
}