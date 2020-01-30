#include <iostream>

using namespace std;

int dp[201][201];
// 0~n중 k개를 더해서 합이 n인 경우: dp[k][n]. k<=n+1
// dp[k][n] = dp[k-1][1] + dp[k-1][2] + .. + dp[k-1][n-1] + dp[k-1][n]
// dp[k][n] = dp[k][n-1] + dp[k-1][n]

/* dp[k][n] 둘다 0부터 시작
1 0 0 0 0
1 1 1 1 1 1
1 2 3 4 ..
1 3 6 10 ..
1 4 ..
*/

int main(void){
    int n,k;
    cin>>n>>k;
    for (int i=0 ; i<=n ; i++){
        dp[0][i] = 0;
    }
    for (int i=0 ; i<=k ; i++){
        dp[i][0] = 1;
    }
    for (int i=1 ; i<=k ; i++){
        for (int j=1 ; j<=n ; j++){
            dp[i][j] = (dp[i][j-1] + dp[i-1][j])%1000000000;
        }
    }
    cout<<dp[k][n];
    
}