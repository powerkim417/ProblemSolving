#include <iostream>

using namespace std;

int dp[10001] = {}; // j만큼의 비용으로 얻을 수 있는 최대 메모리

int max(int a, int b){
    return (a>b)?a:b;
}

// dp 인덱스에 저장할 값이 메모리가 아니라 비용!!
int main(void){
    int N, M;
    cin>>N>>M;
    int m[100], c[100];
    int total_cost = 0;
    for (int i=0 ; i<N ; i++) cin>>m[i];
    for (int i=0 ; i<N ; i++) {
        cin>>c[i];
        total_cost += c[i];
    }
    for (int i=0 ; i<N ; i++){
        for (int j=total_cost ; j>=1 ; j--){
            if (j>=c[i]) dp[j] = max(dp[j], dp[j-c[i]]+m[i]);
        }
    }
    for (int j=1 ; j<=total_cost ; j++){
        if (dp[j] >= M) {
            cout<<j;
            break;
        }
    }
    return 0;
}