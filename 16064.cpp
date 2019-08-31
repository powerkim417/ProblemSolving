#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> slope; // 도착점, 길이
int cost[1001]; // i에서 가장 멀리 갈 수 있는 거리

vector<slope> adj[1001];
const int INF = 999*100;

int max(int a, int b){
    return (a>b)?a:b;
}

// 재귀로 탐색을 하는 경우
// 탐색은 앞부터 하지만
// 값은 뒤부터 배정된다.
int farest(int i){
    if (cost[i] != -1){
        // 이미 값이 배정이 된 경우는 연산 더 하지 않음
        return cost[i];
    }
    // 값이 아직 배정이 안된 경우
    cost[i] = 0; // 0으로 두고 계산 시작
    for (slope next: adj[i]){
        cost[i] = max(cost[i], farest(next.first) + next.second);
        // 다음 슬로프의 도착점에서 가장 멀리 갈 수 있는 곳 + 현재점부터 다음점까지의 거리
        // 이게 지금까지 알고 있던 현재점부터 가장 멀리 갈 수 있는 곳보다 크다면 갱신!

        // 그리고 뒤에서 계산이 완료된 값은 앞에서 갱신되지 않으므로 염려 X.
    }
    return cost[i];
}

int main(void){
    int n,m; // n: 점의 수, m: 선의 수
    cin>>n>>m;
    int s,t,c;
    for (int i=1 ; i<=n ; i++){
        cost[i] = -1;
    }
    for (int i=0 ; i<m; i++){
        cin>>s>>t>>c;
        adj[s].push_back({t, c});
    }
    int answer = 0;
    for (int i=1 ; i<=n ; i++){
        answer = max(answer, farest(i));
    }
    cout<<answer;
}