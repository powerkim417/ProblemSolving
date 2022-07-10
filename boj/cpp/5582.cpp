#include <iostream>

using namespace std;

int dp[4001][4001] = {}; // 각각 a[i], b[j]를 포함하고, 가장 긴 공통 부분 문자열
// 중간중간 끊어진 부분문자열의 합이 아니라 연속된 합이므로
// dp값이 단조증가가 아닌 늘었다 줄었다 형태로 진행되며, max값은 따로 탐색하는 식으로 설계해야 한다.

/* ex) 아래와 같은 예시를 상상하여 값을 관찰하면 점회식을 쉽게 유추할 수 있음!
ABAA
AABA

1101
0020
1103
1201
*/

int main(void){
    string a,b;
    cin>>a>>b;
    int alen = a.length();
    int blen = b.length();
    int answer = 0;
    dp[0][0] = 0;
    for (int i=0 ; i<alen ; i++){
        dp[i][0] = 0;
    }
    for (int j=0 ; j<blen ; j++){
        dp[0][j] = 0;
    }
    for (int i=0 ; i<alen ; i++){
        for (int j=0 ; j<blen ; j++){
            if (a[i]!=b[j]) dp[i][j] = 0;
            else { // a[i] == b[j]
                if (i==0 || j==0) dp[i][j] = 1;
                else { 
                    dp[i][j] = dp[i-1][j-1]+1;
                    // a[i]와 b[j]가 같으면,
                    // dp[i-1][j-1]의 결과에 각각 서로 같은 문자가 추가된 셈(+1)
                }

            }
            if (dp[i][j]>answer) answer = dp[i][j];
        }
    }
    // for (int i=0 ; i<alen ; i++){
    //     for (int j=0 ; j<blen ; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<answer;
    return 0;
}