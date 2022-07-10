#include <iostream>

using namespace std;

int dp[10001][3]; // [i번째 포도주][연속 j회]

int max(int a, int b){
    return (a>b)?a:b;
}

int main(void){
    int n;
    cin>>n;
    int wine[n+1];
    for (int i=1 ; i<=n ; i++){
        cin>>wine[i];
    }
    dp[1][0] = 0;
    dp[1][1] = wine[1]; 
    dp[2][0] = wine[1]; // 1번째 마시고 두번째 안마심
    dp[2][1] = wine[2];
    dp[2][2] = wine[1]+wine[2];
    for (int i=3 ; i<=n ; i++){
        dp[i][0] = max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
        dp[i][1] = dp[i-1][0] + wine[i];
        dp[i][2] = dp[i-1][1] + wine[i];
    }
    // for (int i=1 ; i<=n ; i++){
    //     cout<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<endl;
    // }
    cout<<max(max(dp[n][0], dp[n][1]), dp[n][2]);
}