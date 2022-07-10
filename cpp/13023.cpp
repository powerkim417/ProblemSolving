#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[2000];
bool visited[2000];

/*
A-B-C-D-E 와 같은 친구관계가 존재하려면
특정 점에서 시작했을 때 깊이가 4 이상 탐색되어야 함
백트래킹이 들어가므로 BFS보다는 DFS가 편리(BFS도 가능하긴 하다는데.. 복잡한듯)
*/

bool found;
void dfs(int cur, int depth){ // depth가 2면 한다리 건너 친구
    // cout<<cur<<" "<<depth<<"\n";
    if (depth==5) {
        found = true;
        return;
    }
    visited[cur] = true;
    for (int next: adj[cur]){
        if (!visited[next]) dfs(next, depth+1);
    }
    visited[cur] = false;
}

int main(void){
    int n, m;
    cin>>n>>m;
    int a,b;
    for (int i=0 ; i<m ; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i=0 ; i<n ; i++){ // 각 노드가 시작점
        for (int j=0 ; j<n ; j++) visited[j] = false;
        found = false;
        // cout<<"----start point: "<<i<<"-----\n";
        dfs(i, 1);
        if (found) {
            cout<<"1";
            return 0;
        }
    }
    cout<<"0";
    return 0;
}