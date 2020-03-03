#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

// BFS(바이러스 확산), DFS백트래킹(벽 위치 선정)을 모두 활용

using namespace std;

int n, m;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int map[8][8];
bool new_wall[8][8] = {};
bool visited[8][8] = {};
vector<pair<int, int>> space;
vector<pair<int, int>> virus;
queue<pair<int, int>> q;
int space_size;
int virus_size;
int answer = 0;

bool isRange(int i, int j){
    if (i>=0 && i<n && j>=0 && j<m) return true;
    else return false;
}

int bfs(){ // 벽이 놓이고, 이 상태에서 바이러스를 퍼뜨리는 bfs
    // 매 bfs 실행마다 q는 비워진 상태일 것임
    memset(visited, false, 8*8*sizeof(bool)); // n*m*sizeof(bool) 로 해주면 안됨... 원하는 부분이 초기화가 안된다 (00~07, 10~17, .. 중 앞 n*m개가 되어버림)
    // for (int i=0 ; i<n ; i++){
    //     for (int j=0 ; j<m ; j++){
    //         visited[i][j] = false;
    //     }
    // }
    for (int i=0 ; i<virus_size ; i++){
        q.push({virus[i].first, virus[i].second});
        visited[virus[i].first][virus[i].second] = true;
    }
    while (!q.empty()){
        pair<int, int> cur = q.front();
        // cout<<cur.first<<" "<<cur.second<<"\n";
        q.pop();
        int ni, nj;
        for (int d=0 ; d<4 ; d++){
            ni = cur.first + dr[d];
            nj = cur.second + dc[d];
            if (isRange(ni, nj) && !visited[ni][nj] && map[ni][nj]==0 && !new_wall[ni][nj]){
                // if (new_wall[0][3] && new_wall[1][3] && new_wall[2][4])
                visited[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }
    int ret = n*m-3; // 전체에서 벽 3개 빠진 값
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            if (visited[i][j] || map[i][j]==1) { // (바이러스가) 방문했거나 벽인 경우
                ret--; 
            }
            // if (new_wall[i][j]) cout<<"3";
            // else if (visited[i][j]) cout<<"2";
            // else if (map[i][j]==1) cout<<"1";
            // else cout<<"0";
        }
        // cout<<"\n";
    }
    // cout<<"------\n";
    return ret;
}

void dfs(int cur, int cnt){ // 빈공간의 갯수중 3개를 고르는 백트래킹 dfs
    // cout<<cur<<" "<<cnt<<"\n";
    new_wall[space[cur].first][space[cur].second] = true;
    if (cnt==3){
        int temp = bfs();
        if (temp > answer) {
            answer = temp;
            // for (int i=0 ; i<n ; i++){
            //     for (int j=0 ; j<m ; j++){
            //         cout<<new_wall[i][j];
            //     }
            //     cout<<"\n";
            // }
            // cout<<answer<<"\n";
        }
    }
    else {
        for (int i=cur+1 ; i<space_size ; i++){
            dfs(i, cnt+1);
        }
    }
    new_wall[space[cur].first][space[cur].second] = false;
    return;
}

int main(void){
    cin>>n>>m;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
            if (map[i][j]==0) space.push_back({i, j});
            if (map[i][j]==2) virus.push_back({i, j});
        }
    }
    space_size = space.size();
    virus_size = virus.size();
    for (int i=0 ; i<space_size-2 ; i++){ // 마지막은 (vs-3, vs-2, vs-1) 이므로
        dfs(i, 1);
    }
    cout<<answer;
    return 0;
}

