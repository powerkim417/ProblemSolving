#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[20001];

/*
이분 그래프(Bipartite graph)
BFS, DFS 둘다 되며,
각 노드를 색칠한다고 생각.
이 때, 다음 탐색할 노드는 현재 노드와 다른색으로 색칠해야 한다.
다음 노드가 현재 노드와 같은 색이라면 이분 그래프가 안된다!
*/

// bool visited[20001] = {};
int color[20001] = {}; // 0: 미방문, 1/-1: 색깔
// 색깔 배열을 통해 visited 배열의 역할까지 수행 가능

bool isBP = true;

void dfs(int cur, int cur_color){
    // visited[cur] = true;
    color[cur] = cur_color;
    for (int next: adj[cur]){
        if (color[next]==cur_color){
            isBP = false;
            return;
        }
        if (color[next]==0){
            dfs(next, -cur_color);
        }
    }
}

int main(void){
    int k;
    cin>>k;
    int v, e;
    int a, b;
    for (int t=0 ; t<k ; t++){
        cin>>v>>e;
        isBP = true;
        for (int i=1 ; i<=v ; i++) {
            adj[i].clear();
            // visited[i] = false;
            color[i] = 0;
        }
        for (int i=0 ; i<e ; i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i=1 ; i<=v ; i++){
            // if (!visited[i]) dfs(i, 1);
            if (color[i]==0) dfs(i, 1);
            // 새로 방문하는 점의 색깔을 결정할 때 아무 색깔이나 넣어도 된다.
            // 기존 그래프랑 연결되지 않아 꼬일 일이 없기 때문!(기존 그래프와 연결되어 있었다면 !visited가 아니었겠지)
        }
        cout<<((isBP)?"YES\n":"NO\n");
    }
}