#include <iostream>

using namespace std;

int dp[41][2] = {}; // i까지의 단계에서 j가 나오는 횟수

int main(void){
    int t, n;
    cin>>t;
    dp[0][0] = 1;
    dp[1][1] = 1;
    for (int i=2 ; i<=40 ; i++){
        dp[i][0] = dp[i-2][0]+dp[i-1][0];
        dp[i][1] = dp[i-2][1]+dp[i-1][1];
    }
    while (t--){
        cin>>n;
        cout<<dp[n][0]<<" "<<dp[n][1]<<"\n";
    }
}