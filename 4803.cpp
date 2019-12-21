#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[501];
bool visited[501];
bool finished[501];
int comp;
bool cycle;

void dfs(int i, int p){
    visited[i] = true;
    for (int next: adj[i]){
        if (p == next) continue; // 부모로 다시 올라가는거 방지
        if (!visited[next]) dfs(next, i);
        else {
            if (!finished[next]) { // 사이클 발견
                cycle = true;
            }
        }
    }
    finished[i] = true;
}

int main(void){
    int n=-1, m=-1;
    int t=1;
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    while (1) {
        cin>>n>>m;
        if (n==0 && m==0) break;
        cout<<"Case "<<(t++)<<": ";

        comp = 0;
        for (int i=0 ; i<501 ; i++){
            adj[i].clear();
            visited[i] = false;
            finished[i] = false;
        }
        int a, b;
        for (int i=0 ; i<m ; i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for (int i=1 ; i<=n ; i++){
            if (!visited[i]) {
                comp++;
                cycle = false;
                dfs(i, -1);
                // if (cycle) cout<<i;
                if (cycle) comp--;
            }
        }
        if (comp == 0) cout<<"No trees.\n";
        else if (comp == 1) cout<<"There is one tree.\n";
        else cout<<"A forest of "<<comp<<" trees.\n";
    }
}