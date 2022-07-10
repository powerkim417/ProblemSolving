#include <iostream>

using namespace std;

int sum[10001];

int psum(int s, int e){
    return (sum[e]-sum[s-1]);
}

// 이분탐색에서 ___--- 형태가 아닌 부합하는 조건을 찾는 문제인데도
// bool found 플래그를 사용하지 않아도 되게 짤 수 있다!!!!!

int main(void){
    int n, m;
    cin>>n>>m;
    sum[0] = 0;
    for (int i=1 ; i<=n ; i++){
        cin>>sum[i];
        sum[i] += sum[i-1];
        // cout<<sum[i]<<"\n";
    }
    int cnt = 0;
    // 배열 숫자가 전부 양수이므로 psum(i,i)~psum(i,n)은 증가수열
    // ---O+++ 또는 ---+++ 또는 ------ 또는 ++++++
    for (int i=1 ; i<=n ; i++){
        // cout<<"Level "<<i<<"\n";
        // L에 정답을 넣도록 설계
        int L = i;
        int R = n+1;
        int M;
        while (L+1<R){
            M = (L+R)>>1;
            // cout<<"L: "<<L<<", R: "<<R<<", M: "<<M<<"\n";
            if (psum(i, M)<=m){ // 정답을 포함하는 조건
                L = M;
            }
            else {
                R = M;
            }
        }
        // 이렇게 나오면 LR 0+ 이거나 LR -+ 인 경우로만 나온다.
        if (psum(i, L) == m) cnt++;
    }
    cout<<cnt;
    return 0;
}