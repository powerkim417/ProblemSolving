#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[100001];
int parent[100001];

void dfs(int cur){
    for (int next: adj[cur]){
        if (parent[next]==-1) {
            // cout<<next<<"'s parent is "<<cur<<endl;
            parent[next] = cur;
            dfs(next);
        }
    }
}

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int a, b;
    for (int i=0 ; i<n-1 ; i++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    parent[1] = 0;
    for (int i=2 ; i<=n ; i++){
        parent[i] = -1;
    }
    dfs(1);
    for (int i=2 ; i<=n ; i++){
        cout<<parent[i]<<"\n";
    }
}