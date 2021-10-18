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
    for (int i=2 ; i<=n ; i++){
        dp[i][1] = dp[i-1][1] + map[i][1];
        for (int j=2 ; j<i ; j++){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + map[i][j];
        }
        // 기존 코드는 i=2까지 직접 할당하고 여기에서 새 값을 받을 때마다 answer를 갱신했는데, 이 경우 직접 할당한 부분이 실제 답일 때 answer와 비교하지 못하게 되므로 오류
        dp[i][i] = dp[i-1][i-1] + map[i][i];
    }
    int answer = dp[n][1];
    for (int j=2 ; j<=n ; j++){
        if (answer < dp[n][j]) answer = dp[n][j];
    }
    cout<<answer;
    return 0;
}