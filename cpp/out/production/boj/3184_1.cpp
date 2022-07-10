#include <iostream>
#include <queue>

using namespace std;

int r,c;
char map[250][250];
bool visited[250][250] = {};

queue<pair<int, int>> q;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int sheep = 0, wolf = 0;
int temp_s, temp_w;

bool inRange(int i, int j){
    if (i>=0 && i<r && j>=0 && j<c) return true;
    else return false;
}

// BFS
void BFS(int i, int j){
    q.push({i, j});
    visited[i][j] = true;
    while (!q.empty()){
        pair<int, int> cur = q.front();
        // cout<<cur.first<<" "<<cur.second<<"\n";
        if (map[cur.first][cur.second]=='o') temp_s++;
        if (map[cur.first][cur.second]=='v') temp_w++;
        q.pop();
        for (int d=0 ; d<4 ; d++){
            int ni = cur.first + dr[d];
            int nj = cur.second + dc[d];
            if (inRange(ni, nj) && !visited[ni][nj] && map[ni][nj]!='#'){
                visited[ni][nj] = true;
                q.push({ni, nj});
            }
        }
    }
    // cout<<"---------\n";
}

int main(void){
    cin>>r>>c;
    for (int i=0 ; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            cin>>map[i][j];
        }
    }
    for (int i=0 ; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            if (map[i][j] == '#' || visited[i][j]) continue;
            temp_s = 0, temp_w = 0;
            BFS(i, j);
            // cout<<i<<" "<<j<<"\n";
            if (temp_s>temp_w) {
                sheep += temp_s;
            }
            else wolf += temp_w;
        }
    }
    cout<<sheep<<" "<<wolf;
    return 0;
}