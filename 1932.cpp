#include <iostream>
#include <algorithm>

using namespace std;
int dp[501][501]; // [i층][j번째 수를 택했을 때의 최대값]

int main(void){
    int n;
    cin>>n;
    int map[n+1][n+1];
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=i ; j++){
            cin>>map[i][j];
        }
    }
    dp[1][1] = map[1][1];
    dp[2][1] = map[1][1] + map[2][1];
    dp[2][2] = map[1][1] + map[2][2];
    int answer = 0;
    for (int i=3 ; i<=n ; i++){
        for (int j=1 ; j<=i ; j++){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + map[i][j];
            if (dp[i][j] > answer) answer = dp[i][j];
        }
    }
    cout<<answer;
}