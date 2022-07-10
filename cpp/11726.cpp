#include <iostream>

using namespace std;

int dp[1001] = {};

int main(void){
    int n;
    cin>>n;
    dp[1] = 1;
    dp[2] = 2;
    for (int i=3 ; i<=n ; i++){
        dp[i] = (dp[i-1] + dp[i-2])%10007;
        // dp[i-1]: [    ]ㅣ 형태
        // dp[i-2]: [    ]= 형태.
        // [    ]ㅣㅣ 형태는 전자에만 들어가도록
    }
    cout<<dp[n];
    return 0;
}