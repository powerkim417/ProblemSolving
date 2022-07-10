#include <iostream>

using namespace std;

int dp[1001][1001] = {};

/*
  A C A Y K P
C 0 1 1 1 1 1
A 1 1 2 2 2 2
P 1 1 2 2 2 3
C 1 2 2 2 2 3
A 1 2 3 3 3 3
K 1 2 3 3 4 4
*/

int max(int a, int b){
    return (a>b)?a:b;
}

// 배열값이 0으로 초기화되므로 인덱스를 1~n으로 활용하면 인덱스 0일 때의 예외처리를 해줄 필요가 없어짐
int main(void){
    string a, b;
    cin>>a>>b;
    // i=0 또는 j=0일 때의 예외처리가 자동으로 됨
    for (int i=1 ; i<=a.size() ; i++){
        for (int j=1 ; j<=b.size() ; j++){
            // a,b 인덱스 유의
            if (a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    cout<<dp[a.size()][b.size()];
    return 0;
}