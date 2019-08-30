#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

bool visited[1001];
vector<int> adj[1001];
queue<int> q;
stack<int> s;

void dfs(int x){
    visited[x] = true;
    cout<<x<<" ";
    for (int next: adj[x]){
        if (!visited[next]){
            dfs(next);
        }
    }
}

// void dfs(int start){
//     visited[start] = true;
//     cout<<start<<" ";
//     s.push(start);
//     while(!s.empty()){
//         int cur = s.top();
//         s.pop();
//         for (int next: adj[cur]){
//             if (!visited[next]){
//                 visited[next] = true;
//                 cout<<next<<" ";
//                 s.push(cur);
//                 s.push(next);
//                 break;
//             }
//         }
//     }
// }

void bfs(int start){
    q.push(start);
    visited[start] = true;
    while (!q.empty()){
        int cur = q.front();
        q.pop(); // 방문 완료
        cout<<cur<<" ";
        for (int next: adj[cur]){
            if (!visited[next]){
                q.push(next); // 방문 예정
                visited[next] = true;
                // 방문 예정인 곳은 다른 노드에서 나중에 방문하려 할 때
                // 방문되지 않아야 하므로
                // 방문 예정으로 등록될 때 이미 true로 해줘야 함

                // 아니면 다른 관점...
                // push할 때 visited = true해주지 않으면
                // 같은 노드가 여러번 push 될 수 있음

                // pop 뒤에 visited = true를 놓는 식의 코딩의 경우
                // push할 때 visited = true를 받지 못하여
                // 4 4 4와 같은 경우로 q에 여러번 들어가고, 
                // pop 과 출력 또한 여러번 나오는 것이다.

                // visited = true는 push때 넣고,
                // pop 뒤에 출력을 넣어도 되는 이유는
                // push 뒤에 visited=true가 들어가서
                // 노드가 여러번 들어가는걸 막았기 때문에
                // 나중에 pop도 하나씩만 된다. 성공!
            }
        }
    }
}

int main(void){
    int n,m,v;
    cin>>n>>m>>v;
    for (int i=1 ; i<=n ; i++){
        visited[i] = false;
    }
    for (int i=0 ; i<m ; i++){
        int a,b;
        cin>>a>>b;
        if (find(adj[a].begin(), adj[a].end(), b) == adj[a].end()){   
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    for (int i=1 ; i<=n ; i++){
        sort(adj[i].begin(), adj[i].end());
    }
    dfs(v);
    cout<<endl;
    for (int i=1 ; i<=n ; i++){
        visited[i] = false;
    }
    bfs(v);
}