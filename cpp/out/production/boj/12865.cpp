#include <iostream>

using namespace std;

int dp[101][100001];
/* i번째 물건까지 탐색했을 때 
배낭에 들어간 물건 무게가 j일 때
넣은 가치의 최대값

dp[0][] 예외처리 번거로우니 i를 1부터 시작해서 값을 채우면 편함
*/

int max(int a, int b){
    return (a>b)?a:b;
}

// DP 냅색(knapsack) 문제
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin>>n>>k;
    int w[101], v[101];
    for (int i=1 ; i<=n ; i++){
        cin>>w[i]>>v[i];
    }
    // i번째 물건을 넣었을 때와 넣지 않았을 때 중 더 가치가 큰 값
    for (int i=1 ; i<=n ; i++){
        for (int j=k ; j>=1 ; j--){ // 2차원.. 역순도 된다
            if (j>=w[i]) dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
            else dp[i][j] = dp[i-1][j]; // 물건을 넣은 후의 무게가 j가 되려면 j>=w[i] 여야 하는데, 아닌 경우는 물건을 넣을 수가 없음
        }
    }
    // for (int i=1 ; i<=n ; i++){
    //     for (int j=0 ; j<=k ; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<dp[n][k];
    return 0;
}