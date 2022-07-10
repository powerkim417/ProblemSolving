#include <iostream>
#include <cmath>
using namespace std;

long long int dp[91][2]; // [자리수][마지막 끝나는 숫자]
// dp[4][1]: 4자리고 마지막이 1로 끝나는 수의 갯수

int main(void){
    int n;
    cin>>n;
    dp[1][0] = 0;
    dp[1][1] = 1;
    for (int i=2 ; i<=n ; i++){
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }
    cout<<(dp[n][0] + dp[n][1]);
}