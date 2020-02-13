#include <iostream>
#include <queue>

using namespace std;

int m,n,h;
int map[100][100][100];
bool visited[100][100][100] = {};

int di[6] = {-1, 0, 1, 0, 0, 0};
int dj[6] = {0, 1, 0, -1, 0, 0};
int dk[6] = {0, 0, 0, 0, 1, -1};

struct tomato {
    int i;
    int j;
    int k;
};

queue<tomato> q;

bool isRange(int i, int j, int k){
    if (i>=0 && i<n && j>=0 && j<m && k>=0 && k<h) return true;
    else return false;
}

int time = -1; // 첫 토마토에 대한 탐색이 끝났을 때의 시간이 0이 되게 하려고

void bfs(){
    while (!q.empty()){
        int size = q.size();
        time++;
        // cout<<"time "<<time<<"\n";
        for (int s=0 ; s<size ; s++){
            tomato cur = q.front();
            // cout<<"cur: "<<cur.i<<" "<<cur.j<<" "<<cur.k<<"\n";
            q.pop();
            for (int d=0 ; d<6 ; d++){
                int ni = cur.i + di[d];
                int nj = cur.j + dj[d];
                int nk = cur.k + dk[d];
                if (isRange(ni, nj, nk) && map[ni][nj][nk] == 0) {// 1만 방문했을 것이므로 visited 필요 없음
                    map[ni][nj][nk] = 1;
                    q.push({ni, nj, nk});
                    // cout<<ni<<" "<<nj<<" "<<nk<<"\n";
                }
            }
        }
    }
}

int main(void){
    cin>>m>>n>>h;
    int zero_cnt = 0;
    for (int k=0 ; k<h ; k++){
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                cin>>map[i][j][k];
                if (map[i][j][k] == 1) {
                    // cout<<i<<" "<<j<<" "<<k<<"-------------\n";
                    q.push({i, j, k});
                }
                else if (map[i][j][k] == 0){
                    zero_cnt++;
                }
            }
        }
    }
    if (zero_cnt == 0){ // 익어야 할 토마토가 없을 때
        cout<<"0";
        return 0;
    }
    bfs();
    // for (int k=0 ; k<h ; k++){
    //     for (int i=0 ; i<n ; i++){
    //         for (int j=0 ; j<m ; j++){
    //             cout<<map[i][j][k];
    //         }
    //         cout<<endl;
    //     }
    //     cout<<endl;
    // }
    for (int k=0 ; k<h ; k++){
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                if (map[i][j][k] == 0) { // 시간 다 지나도 안익은 토마토가 있을 때
                    cout<<"-1";
                    return 0;
                }
            }
        }
    }
    cout<<time;
}