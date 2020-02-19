#include <iostream>

using namespace std;

int dp[16][2]; // i일꺼를 j(골랐거나 안골랐거나)했을 때의 최대값

int max(int a, int b){
    return (a>b)?a:b;
}

int main(void){
    int n;
    cin>>n;
    int t[16], p[16];
    for (int i=1 ; i<=n ; i++){
        cin>>t[i]>>p[i];
        if (i+t[i] > n) p[i] = 0; // 기간 내에 못끝내는 상담은 받지 않도록
    }
    dp[1][0] = 0;
    dp[1][1] = p[1];
    for (int i=2 ; i<=n ; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = 
    }

}