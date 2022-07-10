#include <iostream>

using namespace std;

int dp[1000001];

int main(void){
    int n;
    cin>>n;
    dp[1] = 1; // 1
    dp[2] = 2; // 00, 11
    for (int i=3 ; i<=n ; i++){
        dp[i] = dp[i-2] // 끝에 00을 붙임
             + dp[i-1]; // 끝에 1을 붙임. 즉 두 사건은 독립일 수밖에 없음
        dp[i] %= 15746;
    }
    cout<<dp[n];
}