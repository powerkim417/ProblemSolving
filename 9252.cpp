#include <iostream>
#define START make_pair(-1, -1)

using namespace std;

// 9251.LCS 문제에서 업그레이드된 문제
// 길이와 함께 LCS 자체를 출력해야 함

int dp[1000][1000]; // a[i], b[j]까지 LCS의 길이
// 연속 아닌 누적이므로 dp도 누적으로
pair<int, int> prv[1000][1000];

int max(int a, int b, int c){
    int t = (a>b)?a:b;
    return (t>c)?t:c;
}

/* ex)
ACAYKP
CAPCAK

010010
100100
010010
000000
000001
001000

011111
111222
122233
122233
122234
123334
*/

int main(void){
    string a,b;
    cin>>a>>b;
    int alen = a.length();
    int blen = b.length();
    dp[0][0] = (a[0]==b[0]);
    prv[0][0] = START;
    for (int i=1 ; i<alen ; i++){
        if (a[i]==b[0]) {
            dp[i][0] = 1;
            prv[i][0] = START;
        }
        else {
            dp[i][0] = dp[i-1][0];
            prv[i][0] = {i-1, 0};
        }
    }
    for (int j=1 ; j<blen ; j++){
        if (a[0]==b[j]) {
            dp[0][j] = 1;
            prv[0][j] = START;
        }
        else {
            dp[0][j] = dp[0][j-1];
            prv[0][j] = {0, j-1};
        }
    }
    for (int i=1 ; i<alen ; i++){
        for (int j=1 ; j<blen ; j++){
            if (a[i]==b[j]) {
                dp[i][j] = dp[i-1][j-1]+1;
                prv[i][j] = {i-1, j-1};
                // cout<<dp[i][j]<<": "<<a[i]<<"\n";
            }
            else {
                if (dp[i][j-1]>dp[i-1][j]) {
                    dp[i][j] = dp[i][j-1];
                    prv[i][j] = {i, j-1};
                }
                else {
                    dp[i][j] = dp[i-1][j];
                    prv[i][j] = {i-1, j};
                }
            }
        }
    }
    // for (int i=0 ; i<alen ; i++){
    //     for (int j=0 ; j<blen ; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    int answer = dp[alen-1][blen-1];
    cout<<answer;
    if (answer==0) return 0;
    cout<<"\n";
    string answer_str = "";
    int aloc = alen-1, bloc = blen-1;
    pair<int, int> pv;
    while (1){
        // cout<<aloc<<" "<<bloc<<"\n";
        if (make_pair(aloc, bloc) == START) break;
        pv = prv[aloc][bloc];
        if (dp[aloc][bloc]!=dp[pv.first][pv.second]){
        // dp가 바뀐 지점(aloc bloc부터 새로운 dp값인 경우)
            answer_str = a[aloc] + answer_str;
        }
        aloc = pv.first;
        bloc = pv.second;
    }
    cout<<answer_str;
    return 0;
}