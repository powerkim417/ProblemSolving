#include <iostream>

using namespace std;

int dp[1001][1001]; /* [각 경찰차가 해결한 마지막 사건]
dp[0][0]: 둘다 출동 안하고 있는 상태
dp[1][0]: 경찰차1이 1번 사건에 출동
dp[2][1]: 경찰차2가 1번에 출동, 그 다음 경찰차1이 2번 사건에 출동
dp[3][2]: 1,2,1 or 2 2 1
*/
typedef pair<int,int> P;
// int: [3][2]의 경우 [0][2]에서 왔으면 0, [1][2]에서 왔으면 1.
// 즉 움직인 경찰차의 이전 위치
// int: 움직인 경찰차의 번호

// -> 이렇게 저장하지 말고 오기 전 이전의 좌표를 넣어도 됨;; [i-1][j] 이렇게

P prev_num[1001][1001];

struct point {
    int r;
    int c;
};

int dist(point a, point b){
    return (abs(a.r-b.r) + abs(a.c-b.c));
}

int abs(int x){
    if (x>0) return x;
    else return -x;
}

int main(void){
    int n,w;
    cin>>n>>w;
    point p1 = {1,1};
    point p2 = {n,n};
    point cp[w+1]; // 1~w
    int case_get[w+1]; // false: 경찰차1, true: 경찰차2
    dp[0][0] = 0;
    for (int t=1 ; t<=w ; t++){
        cin>>cp[t].r>>cp[t].c;
    }

    for (int i=0 ; i<=w ; i++){
        for (int j=0 ; j<=w ; j++){
            prev_num[i][j] = {-1,0};
        }
    }

    // [0][]/[][0] 초기화
    for (int i=1 ; i<=w ; i++){
        for (int j=1 ; j<=i ; j++){
            if (j==1) dp[i][0] = dist(p1, cp[1]);
            else dp[i][0] += dist(cp[j], cp[j-1]);
            if (j==1) dp[0][i] = dist(p2, cp[1]);
            else dp[0][i] += dist(cp[j], cp[j-1]);
        }
        prev_num[i][0] = {i-1, 1};
        prev_num[0][i] = {i-1, 2};
    }

    // [1][]/[][1] 초기화
    for (int i=2 ; i<=w ; i++){
        for (int j=2 ; j<=i ; j++){
            if (j==2) {
                dp[i][1] = dist(p1, cp[2]) + dist(p2, cp[1]);
                dp[1][i] = dist(p2, cp[2]) + dist(p1, cp[1]);
            }
            else {
                dp[i][1] += dist(cp[j], cp[j-1]);
                dp[1][i] += dist(cp[j], cp[j-1]);
            }
        }
        if (i==2){ // [2][1]은 [0][1]에서 오는 반면
            prev_num[2][1] = {0, 1};
            prev_num[1][2] = {0, 2};
        }
        else { // [3][1] 은 [2][1], [4][1]은 [3][1]에서 오므로 구분해줘야 함
            prev_num[i][1] = {i-1, 1};
            prev_num[1][i] = {i-1, 2};
        }
    }

    /* 인덱스 차이가 1인 경우를 먼저 초기화하려 했었으나,
    [4][3]의 값을 부여하는 과정에서 [4][0], [4][1]은 값이 있었지만 [4][2]는 값이 부여되기 전이라서
    올바른 값을 부여하지 못하는 문제가 발생.
    따라서 모든 값은 위에서 아래로, 왼쪽에서 오른쪽 순으로 값을 부여하는게 답이라고 판단되어
    아래의 for문에 조금 변형하여 끼워넣음 */

    // 두 인덱스 차이가 1이 아닌 경우는 단일 경우이므로 초기화 가능
    for (int i=2 ; i<=w ; i++){
        for (int j=2 ; j<=w ; j++){ // 차이가 1인 경우도 이 안에 넣어야 한다. 순서대로 값을 주지 않으면 중간에 잘못된 값이 전달될 수도 있으므로!
            if (i==j) continue;
            else if (abs(i-j) != 1) {
                if (i>j) {
                    dp[i][j] = dp[i-1][j] + dist(cp[i-1], cp[i]);
                    prev_num[i][j] = {i-1, 1};
                }
                else {
                    dp[i][j] = dp[i][j-1] + dist(cp[j-1], cp[j]);
                    prev_num[i][j] = {j-1, 2};
                }
            }
            else { // 차이가 1인 경우
                if (j==i+1){ // [i][i+1]
                    dp[i][i+1] = dp[i][0] + dist(p2, cp[i+1]);
                    prev_num[i][i+1] = {0, 2};
                    for (int k=1 ; k<=i-1 ; k++){ // k=0은 for문 전에서 이미 함
                        if (dp[i][i+1] > dp[i][k] + dist(cp[k], cp[i+1])){
                            dp[i][i+1] = dp[i][k] + dist(cp[k], cp[i+1]);
                            prev_num[i][i+1] = {k, 2};
                        }
                    }
                }
                else { // [i][i-1]
                    dp[i][i-1] = dp[0][i-1] + dist(p1, cp[i]);
                    prev_num[i][i-1] = {0, 1};
                    for (int k=1 ; k<=i-2 ; k++){
                        if (dp[i][i-1] > dp[k][i-1] + dist(cp[k], cp[i])){
                            dp[i][i-1] = dp[k][i-1] + dist(cp[k], cp[i]);
                            prev_num[i][i-1] = {k, 1};
                        }
                    }
                }
            }
            // 차이가 1인 경우는 따로 했음
        }
    }

    
    int min = 2147483647;
    int r,c; // w*w 행렬들(dp, prev_num)에서 이동 경로
    for (int i=0 ; i<w ; i++){
        // w에 도달한 모든 dp들에 대해서 확인
        if (dp[i][w] < min) {
            min = dp[i][w];
            r = i;
            c = w;
            case_get[w] = 2;
        }
        if (dp[w][i] < min) {
            min = dp[w][i];
            r = w;
            c = i;
            case_get[w] = 1;
        }
    }
    cout<<min<<"\n";

    for (int i=w-1 ; i>=1 ; i--){
        if (prev_num[r][c].second == 1) {
        /* 첫 경찰차가 움직인거면 행렬 경로의 이전 위치를
        prev_num[r][c].first로 돌려줘야 함 */
            r = prev_num[r][c].first;
        }
        else { // 두번째 경찰차가 움직인 경우
            c = prev_num[r][c].first;
        }
        case_get[i] = prev_num[r][c].second;
    }

    // for (int i=0 ; i<=w ; i++){
    //     for (int j=0 ; j<=w ; j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"----------\n";
    // for (int i=0 ; i<=w ; i++){
    //     for (int j=0 ; j<=w ; j++){
    //         cout<<"{"<<prev_num[i][j].first<<", "
    //         <<prev_num[i][j].second<<"} ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"----------\n";

    for (int i=1 ; i<=w ; i++){
        cout<<case_get[i]<<"\n";
    }

}