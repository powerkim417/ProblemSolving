#include <iostream>

using namespace std;

int dp[100001][3];
// [a][b]: a번째 칸까지 갔을 때, b: 0(마지막 선택이 없음), 1(마지막 선택이 위), 2(마지막 선택이 아래)

int max(int a, int b){
    return ((a>b)?a:b);
}

int max(int a, int b, int c){
    int temp = (a>b)?a:b;
    return ((temp>c)?temp:c);
}

int main(void){
    int T;
    cin>>T;
    for (int t=0 ; t<T ; t++){
        int n;
        cin>>n;
        int score[2][n+1];
        for (int i=0 ; i<2 ; i++){
            for (int j=1 ; j<=n ; j++){
                cin>>score[i][j];
            }
        }
        dp[1][0] = 0;
        dp[1][1] = score[0][1];
        dp[1][2] = score[1][1];
        for (int i=2 ; i<=n ; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1], dp[i-1][2]);
            // i번째 선택을 안하는 경우는 i-1번째까지 모든 경우가 다 됨.
            dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + score[0][i]; // 위
            // i번째에 위를 선택했다면 i-1번째는 선택을 안했거나 아래였거나.. 그리고 거기에 i번째 위 점수를 더해줌
            dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + score[1][i]; // 아래
        }
        cout<<max(dp[n][0], dp[n][1], dp[n][2])<<"\n";
    }
}