#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[501];
bool visited[501] = {};
int cnt;
bool cycle;

// 그래프에서 트리의 갯수를 찾는 문제
// 컴포넌트 단위로 트리 여부(사이클이 없는지!)를 확인
// 무향 그래프에서의 사이클 찾기!!!!
// 무향 그래프이므로 사이클 탐지 과정에서 방금 지났던 정점으로 다시 돌아갈 수도 있는데, 이를 막아야 함

void dfs(int cur, int prev){
    visited[cur] = true;
    // cout<<"visited["<<cur<<"] = true\n";
    for (int next: adj[cur]){
        if (next == prev) continue; // 왔던 길로 다시 돌아오는거 제외
        // cout<<"Verifying.. visited["<<next<<"] = "<<visited[next]<<"\n";
        if (visited[next]) cycle = true; // 방금 왔던 길이 아닌데 이미 방문된 곳이 있다면 사이클.
        else dfs(next, cur);
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    int t = 1;
    int a, b;
    while (cin>>n>>m){
        cnt = 0;
        if (n==0 && m==0) break;
        cout<<"Case "<<t++<<": ";
        for (int i=1 ; i<=n ; i++){
            adj[i].clear();
            visited[i] = 0;
        }
        for (int i=0 ; i<m ; i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i=1 ; i<=n ; i++){
            if (!visited[i]) {
                cycle = false;
                dfs(i, -1); // 첫 턴에는 prev값을 쓰지 않으므로 의미 없는 값을 넣어보냄
                if (!cycle) cnt++;
            }
        }
        if (cnt == 0) cout<<"No trees.\n";
        else if (cnt == 1) cout<<"There is one tree.\n";
        else cout<<"A forest of "<<cnt<<" trees.\n";
    }
    return 0;
}