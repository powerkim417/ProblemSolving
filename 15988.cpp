#include <iostream>

using namespace std;

int dp[1000001];

int main(void){
    dp[1] = 1; // 1
    dp[2] = 2; // 2, 11
    dp[3] = 4; // 3, 12, 21, 111
    /* dp[4]의 경우
    3   1
    12  1
    21  1
    111 1 (여기까지 dp[3])
    2   2
    11  2 (여기까지 dp[2])
    1   3 (여기까지 dp[1])
    즉 dp[4] = dp[1]+dp[2]+dp[3]
    */
    for (int i=4 ; i<=1000000 ; i++){
        dp[i] = (dp[i-3]+dp[i-2])%1000000009;
        dp[i] = (dp[i]+dp[i-1])%1000000009;
        // 3개 한꺼번에 더하면 21억정도인 int 범위를 벗어날 수 있음
    }
    int t;
    cin>>t;
    int n;
    while (t--){
        cin>>n;
        cout<<dp[n]<<"\n";
    }
}