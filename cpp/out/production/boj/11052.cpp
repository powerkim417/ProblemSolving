#include <iostream>
#include <algorithm>

using namespace std;

int dp[1001];

int main(void){
    int n;
    cin>>n;
    int p[n+1];
    for (int i=1 ; i<=n ; i++){
        cin>>p[i];
    }
    dp[0] = 0;
    dp[1] = p[1];
    for (int i=2 ; i<=n ; i++){
        dp[i] = 0;
        for (int j=1 ; j<=i ; j++){
            if (dp[i] < dp[i-j] + p[j]){
                dp[i] = dp[i-j] + p[j];
                // n-1개까지 샀을 때 1장짜리 팩을 샀을때, ...
            }
        }
    }
    cout<<dp[n];
}