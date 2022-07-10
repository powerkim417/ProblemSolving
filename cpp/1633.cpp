#include <iostream>
#include <algorithm>

using namespace std;

int b[1001], w[1001];

int dp[1001][16][16]; // [i번째까지 봤을 때][흰팀 몇명][검은팀 몇명]

int max(int a, int b, int c){
    int t = (a>b)?a:b;
    return (t>c)?t:c;
}

int main(void){
    int n=1;
    while (cin>>b[n]>>w[n]){
        n++;
    }
    dp[1][0][0] = 0;
    dp[1][1][0] = b[1];
    dp[1][0][1] = w[1];
    for (int i=2 ; i<=n ; i++){
        for (int j=0 ; j<=i ; j++){
            for (int k=0 ; k<=i-j ; k++){
                // if (j>15 || k>15) continue;
                if (j==0 && k==0) dp[i][0][0] = 0;
                else if (j==0) dp[i][0][k] = max(dp[i-1][0][k-1]+w[i], dp[i-1][0][k]);
                else if (k==0) dp[i][j][0] = max(dp[i-1][j-1][0]+b[i], dp[i-1][j][0]);
                else dp[i][j][k] = max(dp[i-1][j-1][k] + b[i], dp[i-1][j][k-1] + w[i], dp[i-1][j][k]);
            }
        }
    }
    // int i=3;
    // for (int j=0 ; j<=i ; j++){
    //     for (int k=0 ; k<=i-j ; k++){
    //         cout<<dp[i][j][k]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<dp[n][15][15];
}
