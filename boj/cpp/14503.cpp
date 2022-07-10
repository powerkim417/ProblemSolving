#include <iostream>

using namespace std;

int mr[4] = {-1, 0, 1, 0};
int mc[4] = {0, 1, 0, -1};

int left(int d){
    return (d+3)%4; // d-1 doesn't work
}

int back(int d){
    return (d+2)%4;
}

int main(void){
    int n,m;
    cin>>n>>m;
    int r,c,d;
    cin>>r>>c>>d;
    int map[n][m];
    bool cleaned[n][m];
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
            cleaned[i][j] = false;
        }
    }
    // (r, c): 청소기 좌표
    // d: 바라보는 방향(0북 1동 2남 3서)
    // map: 0빈칸 1벽
    int rot_cnt = 0;
    bool stop = false;
    while (1){
        // 1
        cleaned[r][c] = true;
        while (1){
            // 2a 왼쪽에 청소하지 않았고, 공간 존재
            if (!cleaned[r+mr[left(d)]][c+mc[left(d)]]
            && map[r+mr[left(d)]][c+mc[left(d)]] == 0
            && (r+mr[left(d)]) >= 0 && (r+mr[left(d)]) < n
            && (c+mc[left(d)]) >= 0 && (c+mc[left(d)]) < m){
                d = left(d);
                rot_cnt++;
                r = r + mr[d];
                c = c + mc[d];
                rot_cnt = 0;
                break; // goto 1
            }
            // 2cd 네 방향 모두 청소되어있거나 벽
            else if (rot_cnt >= 4){
                // 2c 후진 가능
                if (map[r+mr[back(d)]][c+mc[back(d)]] == 0
                && (r+mr[back(d)]) >= 0 && (r+mr[back(d)]) < n
                && (c+mc[back(d)]) >= 0 && (c+mc[back(d)]) < m){
                    r = r + mr[back(d)];
                    c = c + mc[back(d)];
                    rot_cnt = 0;
                    continue; // goto 2
                }
                else {
                    stop = true;
                    break;
                }
            }

            // 2b 왼쪽에 청소 X일 경우
            else {
                d = left(d);
                rot_cnt++;
                continue; // goto 2
            }
        }
        if (stop) break;
    }
    int answer = 0;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            if (cleaned[i][j]) answer++;
        }
    }
    cout<<answer;
}