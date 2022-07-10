#include <iostream>

using namespace std;

int dp[1001][3]; // dp[k]: 처음 k개의 집을 칠하는데 드는 비용
// [k][0]: 마지막 집이 빨간색, [1]: 초록, [2]: 파랑

int min(int a, int b){
    if (a<b) return a;
    else return b;
}

int main(void){
    int n;
    cin>>n;
    int color[n][3];
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<3 ; j++){
            cin>>color[i][j];
        }
    }
    for (int j=0 ; j<3 ; j++){
        dp[1][j] = color[0][j];
    }
    for (int i=2 ; i<=n ; i++){
        dp[i][0] = min(dp[i-1][1]+color[i-1][0],
         dp[i-1][2]+color[i-1][0]);
        dp[i][1] = min(dp[i-1][2]+color[i-1][1],
         dp[i-1][0]+color[i-1][1]);
        dp[i][2] = min(dp[i-1][0]+color[i-1][2],
         dp[i-1][1]+color[i-1][2]);
    }
    int r = dp[n][0];
    int g = dp[n][1];
    int b = dp[n][2];
    int m1 = (r<g)?r:g;
    int m2 = (m1<b)?m1:b;

    cout<<m2;
}