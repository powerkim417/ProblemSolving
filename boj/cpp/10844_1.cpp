#include <iostream>

using namespace std;

int dp[101][10] = {}; // [i자리][마지막 숫자 j]

int main(void){
    int n;
    cin>>n;
    dp[1][0] = 0;
    for (int i=1 ; i<=9 ; i++){
        dp[1][i] = 1;
    }
    for (int i=2 ; i<=n ; i++){
        for (int j=0 ; j<=9 ; j++){
            if (j!=0) dp[i][j] += dp[i-1][j-1];
            if (j!=9) dp[i][j] += dp[i-1][j+1];
            dp[i][j] %= 1000000000;
            // dp[i][j]를 항상 10억으로 나눠주기 때문에
            // 새로 쌓이는 값도 20억을 넘지 못하므로 항상 int 범위 내임이 보장
        }
    }
    int answer = 0;
    for (int j=0 ; j<=9 ; j++){
        answer += dp[n][j];
        answer %= 1000000000;
    }
    cout<<answer;
    return 0;
}