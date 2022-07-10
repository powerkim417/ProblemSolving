#include <iostream>

using namespace std;

int dp[1001][1001];

int main(void){
    int n,k;
    cin>>n>>k; // 1~1000, 0~n
    for (int i=0 ; i<=n ; i++){
        for (int j=0 ; j<=k ; j++){
            if (j==0 || i==j) dp[i][j] = 1;
            else {
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%10007;
            }
        }
    }
    cout<<dp[n][k];
}