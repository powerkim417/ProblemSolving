#include <iostream>

using namespace std;

// 부분합 풀이 (DP 아님!)
/* FJ의 배열을 둘로 나누었을 때
(왼쪽 배열에서 HPS중 가장 많은 것의 갯수)+(오른쪽 배열에서 HPS중 가장 많은 것의 갯수)
를 구하면 된다.
*/

int FJ[100001][3] = {}; // i번째까지 j모양이 몇개인지(부분합 저장)

int maxCnt(int s, int e){ // [s, e]
    int cnt[3];
    for (int i=0 ; i<3 ; i++){
        cnt[i] = FJ[e][i]-FJ[s-1][i];
    }
    if (cnt[0]>cnt[1] && cnt[0]>cnt[2]) return cnt[0];
    else if (cnt[1]>cnt[0] && cnt[1]>cnt[2]) return cnt[1];
    else return cnt[2];
}

int main(void){
    int n;
    cin>>n;
    char temp;
    FJ[0][0] = 0, FJ[0][1] = 0, FJ[0][2] = 0;
    for (int i=1 ; i<=n ; i++){
        cin>>temp;
        for (int j=0 ; j<3 ; j++) FJ[i][j] = FJ[i-1][j];
        switch (temp){
            case 'H':
            FJ[i][0]++;
            break;
            case 'P':
            FJ[i][1]++;
            break;
            case 'S':
            FJ[i][2]++;
            break;
        }
    }
    int answer = maxCnt(0, n); // 구간을 안나눴을 때. HH..H, PP..P, SS..S를 냈을 때 중 최대값
    // 1~n
    for (int i=2 ; i<n ; i++){
        if (answer < maxCnt(1, i) + maxCnt(i+1, n)){
            answer = maxCnt(1, i) + maxCnt(i+1, n);
        }
    }
    cout<<answer;
    return 0;
}