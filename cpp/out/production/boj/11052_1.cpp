#include <iostream>

using namespace std;

int p[1001];
int dp[1001];

int main(void){
    int n;
    cin>>n;
    for (int i=1 ; i<=n ; i++){
        cin>>p[i];
    }
    dp[0] = 0;
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=i ; j++){
            if (dp[i-j] + p[j] > dp[i]) dp[i] = dp[i-j] + p[j];
        }
    }
    cout<<dp[n];
    return 0;
}