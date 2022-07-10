#include <iostream>

using namespace std;

int dp[101][101][101] = {};

int max(int x, int y, int z){
    int t = (x>y)?x:y;
    return (t>z)?t:z;
}

// a,b의 LCS와 c를 비교하는 식으로 하면 안됨!
/*
Str1 : dababcf
Str2 : ababdef
Str3 : df

LCS(A,B) : ababf
LCS(LCS(A,B),C) : f
LCS(A,B,C) : df
*/
int main(void){
    string a, b, c;
    cin>>a>>b>>c;
    for (int i=1 ; i<=a.size() ; i++){
        for (int j=1 ; j<=b.size() ; j++){
            for (int k=1 ; k<=c.size() ; k++){
                if (a[i-1]==b[j-1] && b[j-1]==c[k-1]) dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                // else dp[i][j][k] = max(max(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]), max(dp[i-1][j-1][k], dp[i][j-1][k-1], dp[i-1][j][k-1]));
                else dp[i][j][k] = max(dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]);
                // 6개 비교를 할 필요가 없는 이유.. dp[i-1][j-1][k]가 최대였으면 [i-1][j][k]와 [i][j-1][k]에 반영되었을 것임
            }
        }
    }
    cout<<dp[a.size()][b.size()][c.size()];
    return 0;
}