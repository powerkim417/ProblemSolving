#include <iostream>
#include <queue>

using namespace std;

char map[50][50];
int n, m;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
queue<pair<int, int>> land;
queue<pair<int, int>> q;
bool visited[50][50] = {};

bool isRange(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m);
}

int bfs(int si, int sj){
    q = queue<pair<int, int>>();
    visited[si][sj] = true;
    q.push({si, sj});
    int time = 0;
    while (!q.empty()){
        int q_size = q.size();
        for (int qs=0 ; qs<q_size ; qs++){
            pair<int, int> cur = q.front();
            q.pop();
            for (int d=0 ; d<4 ; d++){
                int ni = cur.first+dr[d];
                int nj = cur.second+dc[d];
                if (!isRange(ni, nj) || map[ni][nj]=='W' || visited[ni][nj]) continue;
                visited[ni][nj] = true;
                q.push({ni, nj});
            }
        }
        time++;
    }
    return time-1;
}

int main(void){
    cin>>n>>m;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
            if (map[i][j]=='L') land.push({i, j});
        }
    }
    int answer = 0; // 최단거리의 최대값, 즉 한 점에 대해 bfs한 마지막 거리가 가장 큰 경우
    while (!land.empty()){ // 모든 land 점에 대해 BFS 시도
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                visited[i][j] = false;
            }
        }
        int temp = bfs(land.front().first, land.front().second);
        if (temp>answer) answer = temp;
        land.pop();
    }
    cout<<answer;
    return 0;
}