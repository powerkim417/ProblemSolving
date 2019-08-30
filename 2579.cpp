#include <iostream>

using namespace std;

int stair[301];
int dp[301][3]; // n번째 계단까지, 연속 밟은 계단 수(1, 2)


// 연속 밟은 계단 수로 체크하는 것이 중요한 아이디어!!!

int max(int a, int b){
    if (a>b) return a;
    else return b;
}

int main(void){
    int n;
    cin>>n;
    for (int i=1 ; i<=n ; i++){
        cin>>stair[i];
    }
    dp[1][1] = stair[1];
    dp[1][2] = 0;
    dp[2][1] = stair[2];
    dp[2][2] = dp[1][1] + stair[2];

    for (int i=3 ; i<=n ; i++){
        dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + stair[i];
        dp[i][2] = dp[i-1][1] + stair[i];
    }
    cout<<max(dp[n][1], dp[n][2]);
}