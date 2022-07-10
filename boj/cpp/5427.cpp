#include <iostream>
#include <queue>
#define INF 1000*1000 + 1
using namespace std;

int w,h;
int fire_time[1000][1000] = {};
bool visited[1000][1000] = {};
char map[1000][1000] = {};
int dr[4] = {-1, 0, 1 ,0};
int dc[4] = {0, 1, 0, -1};
queue<pair<int, int>> q_fire;
queue<pair<int, int>> q_man;

/*
불의 위치를 먼저 bfs로 돌리고, 사람의 위치를 bfs로 돌린다.
이때, 불의 위치를 고려해서 사람이 움직이므로
가능한 이동 경로만 살아남게 되며,
탈출하기 전에 q_man이 비게 되면 탈출 실패로 간주하면 된다.
*/

bool isRange(int i, int j){ // 범위를 벗어나서 탈출 성공인지 체크할 때도 사용
    if (i>=0 && i<h && j>=0 && j<w) return true; // 범위 안에 있는지를 체크
    else return false; // 사람이 탈출했는지 체크
}

// while (!q_fire.empty()) 와 while (!q_man.empty()) 가 같이 돌아갈 수 없으므로
// 불을 먼저 bfs하되, 방문 배열을 bool 대신 불이 번진 시각(int)으로 기록한 뒤, 다음에 man을 별도로 bfs하도록 짠다!!!!!!!!!
int bfs(){
    // 불 BFS
    int time = 0;
    int ni, nj;
    while (!q_fire.empty()){
        int qf_size = q_fire.size();
        while (qf_size--){
            pair<int, int> cur = q_fire.front();
            q_fire.pop();
            for (int d=0 ; d<4 ; d++){
                ni = cur.first + dr[d];
                nj = cur.second + dc[d];
                if (isRange(ni, nj) && fire_time[ni][nj]==INF && map[ni][nj]!='#'){
                    fire_time[ni][nj] = time+1;
                    q_fire.push({ni, nj});
                }
            }
        }
        time++;
    }

    // 사람 BFS
    time = 0;
    while (!q_man.empty()){
        int qm_size = q_man.size();
        while (qm_size--){
            pair<int, int> cur = q_man.front();
            // cout<<cur.first<<" "<<cur.second<<"\n";
            q_man.pop();
            for (int d=0 ; d<4 ; d++){
                ni = cur.first + dr[d];
                nj = cur.second + dc[d];
                if (!isRange(ni, nj)) return time+1; // 탈출 성공
                if (!visited[ni][nj] && map[ni][nj]!='#' && time+1<fire_time[ni][nj]){
                    visited[ni][nj] = true;
                    q_man.push({ni, nj});
                }
            }
        }
        time++;
    }
    return -1; // 사람이 탈출하지 못하고 q_man이 비어버린 경우 -1 반환
}

int main(void){
    int tc;
    cin>>tc;
    for (int t=0 ; t<tc ; t++){
        cin>>w>>h;
        queue<pair<int, int>> empty;
        swap(q_man, empty); // q_man이 이전 테케에서 비워지지 않은 채로 return되는 경우가 있으므로 새로 시작할 때 비워줘야 함. q_fire는 항상 빔
        for (int i=0 ; i<h ; i++){
            for (int j=0 ; j<w ; j++){
                cin>>map[i][j];
                fire_time[i][j] = INF;
                visited[i][j] = false;
                if (map[i][j]=='*') {
                    fire_time[i][j] = 0;
                    q_fire.push({i, j});
                }
                if (map[i][j]=='@') {
                    visited[i][j] = true;
                    q_man.push({i, j});
                }
            }
        }
        int answer = bfs();
        if (answer == -1) cout<<"IMPOSSIBLE\n";
        else cout<<answer<<"\n";

        // for (int i=0 ; i<h ; i++){
        //     for (int j=0 ; j<w ; j++){
        //         if (fire_time[i][j]!=INF) cout<<fire_time[i][j];
        //         else cout<<map[i][j];
        //     }
        //     cout<<"\n";
        // }

    }
    return 0;
}