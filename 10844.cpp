#include <iostream>

using namespace std;

long long int dp[101][10]; // [i자리][끝 수가 j]

int main(void){
    int N;
    cin>>N;
    dp[1][0] = 0;
    for (int j=1 ; j<=9 ; j++){
        dp[1][j] = 1;
    }
    for (int i=2 ; i<=N ; i++){
        dp[i][0] = dp[i-1][1];
        for (int j=1 ; j<=8 ; j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
        }
        dp[i][9] = dp[i-1][8];
    }
    int sum = 0;
    for (int j=0 ; j<=9 ; j++){
        sum += dp[N][j];
        sum %= 1000000000;
    }
    cout<<sum;
}