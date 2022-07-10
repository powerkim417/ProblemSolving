#include <iostream>

using namespace std;

int dp[10001] = {};

// 기본 아이디어는 i개의 동전으로 j 가격 만드는 dp이나,
// 메모리 초과를 막기 위해 1차원 냅색처럼 각 개의 동전의 경우를 덮어쓴다
int main(void){
    int n, k;
    cin>>n>>k;
    int coin[100];
    for (int i=0 ; i<n ; i++){
        cin>>coin[i];
    }
    dp[0] = 1;
    // 0~i번째 동전까지 사용하는 경우
    for (int i=0 ; i<n ; i++){
        for (int j=1 ; j<=k ; j++){
            if (j < coin[i]) continue;
            // i-1번째 동전까지 사용해서 j + i-1번째 동전까지 사용해서 j-coin[i]
            dp[j] = dp[j] + dp[j-coin[i]];
        }
    }
    cout<<dp[k];
    return 0;
}