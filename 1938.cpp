#include <iostream>
#include <queue>

using namespace std;

int n;
char map[50][50];
bool visited[50][50][2]; // i, j, vert

struct state {
    int i;
    int j;
    bool vert; // 세로면 true 1 가로면 false 0
};

bool isRange(int i, int j){
    if (i>=0 && i<n && j>=0 && j<n) return true;
    else return false;
}

queue<state> q;

// 도착점 정보. 인풋 다 받으면 계산되어 있음
int er, ec;
bool ev;

int bfs(int i, int j, bool v){
    q.push({i, j, v});
    visited[i][j][v];
    int cnt = 0;
    bool found = false;
    while (!q.empty()){
        int q_size = q.size();
        // cout<<"<Move "<<cnt<<">\n";
        for (int s=0 ; s<q_size ; s++){
            state cur = q.front();
            // cout<<"("<<cur.i<<", "<<cur.j<<"), "<<((cur.vert)?"|\n":"-\n");
            if ((er == cur.i) && (ec == cur.j) && (ev == cur.vert)){
                found = true;
                break;
            }
            q.pop();
            int ni, nj;
            // Up
            ni = cur.i-1;
            nj = cur.j;
            if (cur.vert){ // |
                if (isRange(ni-1, nj)
                && map[ni-1][nj] != '1'
                && !visited[ni][nj][cur.vert]){
                    visited[ni][nj][cur.vert] = true;
                    q.push({ni, nj, cur.vert});
                }
            }
            else { // ㅡ
                if (isRange(ni, nj)
                && map[ni][nj-1] != '1' && map[ni][nj] != '1' && map[ni][nj+1] != '1'
                && !visited[ni][nj][cur.vert]){
                    visited[ni][nj][cur.vert] = true;
                    q.push({ni, nj, cur.vert});
                }
            }
            // Down
            ni = cur.i+1;
            nj = cur.j;
            if (cur.vert){ // |
                if (isRange(ni+1, nj)
                && map[ni+1][nj] != '1'
                && !visited[ni][nj][cur.vert]){
                    visited[ni][nj][cur.vert] = true;
                    q.push({ni, nj, cur.vert});
                }
            }
            else { // ㅡ
                if (isRange(ni, nj)
                && map[ni][nj-1] != '1' && map[ni][nj] != '1' && map[ni][nj+1] != '1'
                && !visited[ni][nj][cur.vert]){
                    visited[ni][nj][cur.vert] = true;
                    q.push({ni, nj, cur.vert});
                }
            }
            // Left
            ni = cur.i;
            nj = cur.j-1;
            if (!cur.vert){ // ㅡ
                if (isRange(ni, nj-1)
                && map[ni][nj-1] != '1'
                && !visited[ni][nj][cur.vert]){
                    visited[ni][nj][cur.vert] = true;
                    q.push({ni, nj, cur.vert});
                }
            }
            else { // |
                if (isRange(ni, nj)
                && map[ni-1][nj] != '1' && map[ni][nj] != '1' && map[ni+1][nj] != '1'
                && !visited[ni][nj][cur.vert]){
                    visited[ni][nj][cur.vert] = true;
                    q.push({ni, nj, cur.vert});
                }
            }
            // Right
            ni = cur.i;
            nj = cur.j+1;
            if (!cur.vert){ // ㅡ
                if (isRange(ni, nj+1)
                && map[ni][nj+1] != '1'
                && !visited[ni][nj][cur.vert]){
                    visited[ni][nj][cur.vert] = true;
                    q.push({ni, nj, cur.vert});
                }
            }
            else { // |
                if (isRange(ni, nj)
                && map[ni-1][nj] != '1' && map[ni][nj] != '1' && map[ni+1][nj] != '1'
                && !visited[ni][nj][cur.vert]){
                    visited[ni][nj][cur.vert] = true;
                    q.push({ni, nj, cur.vert});
                }
            }
            // Turn
            if (!isRange(cur.i-1, cur.j-1) || map[cur.i-1][cur.j-1] == '1') continue;
            if (!isRange(cur.i-1, cur.j) || map[cur.i-1][cur.j] == '1') continue;
            if (!isRange(cur.i-1, cur.j+1) || map[cur.i-1][cur.j+1] == '1') continue;
            if (!isRange(cur.i, cur.j-1) || map[cur.i][cur.j-1] == '1') continue;
            if (!isRange(cur.i, cur.j+1) || map[cur.i][cur.j+1] == '1') continue;
            if (!isRange(cur.i+1, cur.j-1) || map[cur.i+1][cur.j-1] == '1') continue;
            if (!isRange(cur.i+1, cur.j) || map[cur.i+1][cur.j] == '1') continue;
            if (!isRange(cur.i+1, cur.j+1) || map[cur.i+1][cur.j+1] == '1') continue;
            // 회전반경이 범위 벗어나거나 벽이 있는 경우는 배제
            if (!visited[cur.i][cur.j][!cur.vert]) {
                visited[cur.i][cur.j][!cur.vert] = true;
                q.push({cur.i, cur.j, !cur.vert});
            }
        }
        if (found) break;
        cnt++;
    }
    if (found) return cnt;
    else return 0; // 도달할 수 없는 경우 0 출력
}

int main(void){
    cin>>n;
    int br1, bc1, br3, bc3;
    int er1, ec1, er3, ec3;
    bool flagb = false, flage = false;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>map[i][j];
            if (map[i][j] == 'B'){ // B 정보
                if (!flagb){
                    br1 = i;
                    bc1 = j;
                    flagb = true;
                }
                else {
                    br3 = i;
                    bc3 = j;
                }
            }
            if (map[i][j] == 'E'){ // E 정보
                if (!flage){
                    er1 = i;
                    ec1 = j;
                    flage = true;
                }
                else {
                    er3 = i;
                    ec3 = j;
                }
            }
        }
    }
    int br = (br1 + br3) / 2;
    int bc = (bc1 + bc3) / 2;
    bool bv = (br1 == br3) ? 0 : 1;
    // cout<<"B("<<br<<", "<<bc<<"), "<<((bv)?"|\n":"\n");
    er = (er1 + er3) / 2;
    ec = (ec1 + ec3) / 2;
    ev = (er1 == er3) ? 0 : 1; 
    // cout<<"E("<<er<<", "<<ec<<"), "<<((ev)?"|\n":"-\n");
    // cout<<"--------------------\n";
    cout<<bfs(br, bc, bv);
}