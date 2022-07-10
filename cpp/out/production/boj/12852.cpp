#include <iostream>

using namespace std;

int dp[1000001];
int nxt[1000001]; // i가 1이 되기 위해 줄어드는 최적의 경우
// n=10 인 경우 10 - 9 - 3 - 1이 최적이므로 dp[10] = 9, dp[9] = 3

// DP + 트래킹
int main(void){
    int n;
    cin>>n;
    dp[1] = 0;
    for (int i=2 ; i<=n ; i++){
        dp[i] = dp[i-1] + 1;
        nxt[i] = i-1;
        if (i%2==0){
            if (dp[i] > dp[i/2]+1){
                dp[i] = dp[i/2] + 1;
                nxt[i] = i/2;
            }
        }
        if (i%3==0){
            if (dp[i] > dp[i/3]+1){
                dp[i] = dp[i/3] + 1;
                nxt[i] = i/3;
            }
        }
    }
    cout<<dp[n]<<"\n";
    cout<<n;
    while (n!=1){
        n = nxt[n];
        cout<<" "<<n;
    }
    return 0;
}