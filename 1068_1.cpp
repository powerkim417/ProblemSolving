#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[50];
bool visited[50] = {};
// 특정 노드를 지우면 그 노드의 자식들도 다 지워짐
int cnt = 0;

void dfs(int cur){
    visited[cur] = true;
    if (adj[cur].size() == 0){
        cnt++;
        return;
    }
    for (int next: adj[cur]){
        if (!visited[next]) dfs(next);
    }
}

int main(void){
    int n;
    cin>>n;
    int parent[50];
    int root;
    for (int i=0 ; i<n ; i++){
        cin>>parent[i];
        if (parent[i] == -1) root = i;
    }
    int remove;
    cin>>remove; // 버릴 노드
    for (int i=0 ; i<n ; i++){
        if (i==root || i==remove) continue;
        else adj[parent[i]].push_back(i);
    }
    // 이 상태에서 리프 노드의 수를 구하고, temp 역시 이에 카운트될 것이므로 -1을 뺀 값을 결과로 제출
    dfs(root);
    if (root == remove) cout<<"0";
    else cout<<cnt;
    return 0;
}