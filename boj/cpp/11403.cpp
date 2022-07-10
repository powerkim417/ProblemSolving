#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int map[100][100];

///////////////////////// floyd warshall
int dist[100][100];
const int INF = 100; // 99 + 1

void floyd_warshall(){
    for (int i=0 ; i<n ; i++){
        for (int j=0 ;j<n ; j++){
            if (map[i][j] == 0) dist[i][j] = INF;
            else dist[i][j] = 1;
        }
    }
    for (int k=0 ; k<n ; k++){
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                if (dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (dist[i][j] == INF) cout<<"0 ";
            else cout<<"1 ";
        }
        cout<<"\n";
    }
}

/////////////////////// DFS
vector<int> adj[100];
bool visited[100];

void dfs(int x){
    // visited[x] = true; // 기본적으로 i에서 i로 직통으로 가는건 없다고 가정..
    for (int next: adj[x]){
        if (!visited[next]){
            visited[next] = true; // 대신 여기에 visited 처리를 하면 본인점 미방문 처리 가능!
            dfs(next);
        }
    }
}

void dfs(){
    for (int i=0 ; i<n ; i++){
        adj[i].clear();
        for (int j=0 ; j<n ; j++){
            if (map[i][j] == 1) adj[i].push_back(j);
        }
    }

    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++)
            visited[j] = false; // 한 점에 대해 dfs마다 초기화
        dfs(i);
        for (int j=0 ; j<n ; j++){
            cout<<((visited[j])?"1 ":"0 ");
        }
        cout<<"\n";
    }
}

////////////////////// BFS

queue<int> q;
// vector<int> adj[100];
// bool visited[100];

void bfs(){
    for (int i=0 ; i<n ; i++){
        adj[i].clear();
        for (int j=0 ; j<n ; j++){
            if (map[i][j] == 1) adj[i].push_back(j);
        }
    }

    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++)
            visited[j] = false; // 한 점에 대해 bfs마다 초기화
        q.push(i);
        while (!q.empty()){
            int cur = q.front();
            q.pop();
            for (int next: adj[cur]){
                if (!visited[next]){
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        for (int j=0 ; j<n ; j++){
            cout<<((visited[j])?"1 ":"0 ");
        }
        cout<<"\n";
    }
}


int main(void){
    cin>>n;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>map[i][j];
        }
    }
    // floyd_warshall();
    // dfs();
    bfs();
    return 0;
}