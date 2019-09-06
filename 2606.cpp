#include <iostream>
#include <vector>

using namespace std;

bool visited[101];
vector<int> adj[101];
int cnt;

void dfs(int cur){
    visited[cur] = true;
    for (int next: adj[cur]){
        if (!visited[next]){
            cnt++;
            dfs(next);
        }
    }
}

int main(void){
    int N,T;
    cin>>N>>T;
    int a,b;
    for (int t=0 ; t<T ; t++){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cnt = 0;
    dfs(1);
    cout<<cnt;
}