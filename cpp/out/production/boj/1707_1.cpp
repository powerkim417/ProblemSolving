#include <iostream>
#include <vector>

using namespace std;

int v, e;
vector<int> adj[20001];
int color[20001]; // 0: 미방문 / 1,-1: 색깔
bool fail;

void dfs(int cur, int clr){
    color[cur] = clr;
    for (int next: adj[cur]){
        if (color[next] == color[cur]){
            fail = true;
            return;
        }
        if (color[next]==0) dfs(next, -clr);
    }
}

int main(void){
    int k;
    cin>>k;
    for (int t=0 ; t<k ; t++){
        cin>>v>>e;
        int a, b;
        for (int i=1 ; i<=v ; i++) {
            adj[i].clear();
            color[i] = 0;
        }
        for (int i=0 ; i<e ; i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        fail = false;
        for (int i=1 ; i<=v ; i++){
            if (color[i]==0) dfs(i, 1);
            if (fail) break;
        }
        if (fail) cout<<"NO\n";
        else cout<<"YES\n";
    }
}