#include <iostream>

using namespace std;

int n;
bool adj[100][100];
bool visited[100][100] = {}; // [i에서 시작한 DFS로][방문하는 점 j]. i->j가 아님
int start;

void dfs(int cur){
    for (int next=0 ; next<n ; next++){
        if (!visited[start][next] && adj[cur][next]){
            // visited[cur][next] = true;
            visited[start][next] = true;
            dfs(next);
        }
    }
}

int main(void){
    cin>>n;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>adj[i][j];
        }
    }
    for (int i=0 ; i<n ; i++){
        start = i;
        dfs(i);
    }
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cout<<visited[i][j]<<" ";
        }
        cout<<"\n";
    }
}