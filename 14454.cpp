#include <iostream>

using namespace std;

// abcd -> abcd dabc ca b c  d d a b
//         0123 4567 891011 12131415
// len=4, N이 8~15 사이일 때
// 9~15 = 0~6
// 8 = 7
// N = (N-1)%8
// -----
// len=4, N이 4~7 사이일 때
// 5~7 = 0~2
// 4 = 3
// N = (N-1)%4
// --
// N<=len일 때는 찾을 수 있음

// len * 2^t <= N < len * 2^(t+1) 를 찾고, 계속 MOD 연산 하면 됨

int main(void){
    string s;
    long long n;
    cin>>s>>n;
    n--;
    long long len = s.length();
    long long temp = len;
    while (temp <= n){ // len=4일 때 0~3이 temp=4, 4~7이 temp=8, 8~15가 temp=16
        temp *= 2;
    }
    temp /= 2;
    // 이제 temp는 해당 범위에서 가장 작은 값(8~15면 temp=8, 4~7이면 temp=4. 0~3일 때는 temp를 사용하지 않고 바로 출력)
    while (1){
        // cout<<n<<" "<<temp<<"\n";
        if (0<=n && n<len) break;
        while (temp>n) temp /= 2; // temp는 반씩 나뉘는데 n은 그보다 더 작게 나눠질 수 있어 기준점이 되어야 하는 temp가 n보다 커질 수 있다. 이를 방지하기 위해 temp를 n 이하로 나눠 맞춰야 함
        n = (n-1)%temp;
        temp /= 2;
    }
    cout<<s[n];
    return 0;
}