#include <iostream>

using namespace std;

int n, m;
bool map[1000][1000];
int dp[1000][1000] = {}; // (0,0)~(i,j)에서 (i,j)를 포함하는 가장 큰 정사각형의 넓이

int min(int a, int b, int c){
    int temp = (a>b)?b:a;
    return (temp>c)?c:temp;
}

int max(int a, int b, int c){
    int temp = (a>b)?a:b;
    return (temp>c)?temp:c;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    int answer = 0;
    char c;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>c;
            map[i][j] = (c=='1');
        }
    }
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            if (i==0 || j==0) dp[i][j] = map[i][j]; // 초기화
            else { //초기화 아닌 경우
                if (!map[i][j]) dp[i][j] = 0;
                else { // map[i][j] == 1
                    if (map[i-1][j] && map[i][j-1] && map[i-1][j-1]){ // 좌 좌상 상 모두 1일 때
                        dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;
                    }
                    else {
                        dp[i][j] = 1;
                    }
                }
            }
            if (answer < dp[i][j]) answer = dp[i][j];
        }
    }
    // for (int i=0 ; i<n ; i++){
    //     for (int j=0 ; j<m ; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<answer*answer;
    return 0;
}