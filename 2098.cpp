#include <iostream>

using namespace std;

// 비트마스킹!!
// 2^16가지의 상태를 효율적으로 표현하기 위함
int dp[(1<<16)][16]; // [이때까지 방문해온 노드집합(비트)][마지막 방문 노드]
// 위와 같은 상태정보 기준으로 했을 때 남은 방문들을 가장 짧게 방문하는 비용

int n;
int cost[16][16];
const int START_POINT = 0;
const int INF = 1000000*16;

bool visited(int bit, int k){
    return (bit & (1<<k));
}

int addvisit(int bit, int k){
    return (bit | (1<<k));
}

int min(int a, int b){
    return (a<b)?a:b;
}

// 뒤에서부터 더 작은 자명한 값들로 출발해서 앞에서 큰 값을 계산하는
// 재귀의 방법!!!!!
int TSP(int bit, int cur){
    if (dp[bit][cur]!=-1) return dp[bit][cur];
    if (bit == (1<<n)-1){ // 이번 state 설계에선 이게 초기값
        if (cost[cur][START_POINT] == 0)
            dp[bit][cur] = INF;
        else 
            dp[bit][cur] = cost[cur][START_POINT];
        return dp[bit][cur];
    }
    else {
        dp[bit][cur] = INF;
        for (int i=0 ; i<n ; i++){
            if (!visited(bit, i) && cost[cur][i] != 0){
                dp[bit][cur] = min(dp[bit][cur], TSP(addvisit(bit, i), i) + cost[cur][i]);
                // INF부터 시작해서 '다음에 i번째 칸으로 갈 때
                // dp[i visited bit][i] + cost[cur][i]한 값이
                // 가장 작은 값이 dp[bit][cur]가 된다.
            }
        }
    }
    return dp[bit][cur];
}

int main(void){
    cin>>n;
    for (int i=0 ; i<n ; i++){ // 도시: 0~n
        for (int j=0 ; j<n ; j++){
            cin>>cost[i][j];
        }
    }
    // 순회 여행 경로이므로 첫번째 마을을 시작점으로 잡아도 됨
    int visit = (1 << START_POINT); // 0번째 마을을 시작점으로 잡음
    for (int i=0 ; i<(1<<n) ; i++){
        for (int j=0 ; j<n ; j++){
            dp[i][j] = -1;
        }
    }
    cout<<TSP(visit, START_POINT);
}