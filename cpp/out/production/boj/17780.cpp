#include <iostream>
#include <vector>
using namespace std;

/*
자료구조를 너무 난잡하게 사용해서 코드가 아주 복잡하다.
17837(새로운 게임 2)는 좀 더 깔끔하게 풀어볼 것
*/

struct piece {
    int r;
    int c;
    int dir;
    int up; // 자신 위의 말의 번호. 위에 없을 경우 자기자신 그대로
    int down; // 자신 아래의 말의 번호. 아래에 없을 경우 자기자신 그대로
};

int n, k;
int map[12][12]; // 0흰색 1빨간색 2파란색
int top[12][12] = {};
int bottom[12][12] = {};
piece P[11];
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0}; // 0123 순서대로 우좌상하

bool isRange(int i, int j){
    if (i>=0 && i<n && j>=0 && j<n) return true;
    else return false;
}

int rev_dir(int dir){ // 0<->1, 2<->3
    if (dir%2==0) return dir+1;
    else return dir-1;
}

// int top(int num){
//     if (num == P[num].up) return num;
//     else return top(P[num].up);
// }
// int bottom(int num){
//     if (num == P[num].down) return num;
//     else return top(P[num].down);
// }

int cnt(int bottom){
    int num = 1;
    int cur = bottom;
    while (cur != P[cur].up){
        cur = P[cur].up;
        num++;
    }
    return num;
}

int main(void){
    cin>>n>>k;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>map[i][j];
        }
    }
    int r, c, d;
    for (int i=1 ; i<=k ; i++){
        cin>>r>>c>>d;
        r--;
        c--;
        d--;
        P[i] = {r, c, d, i, i}; // 처음에는 겹치는 위치 안줌
        top[r][c] = i;
        bottom[r][c] = i;
    }
    int time = 1;
    while (time<=1000){ // 1000번의 턴
        // cout<<"-----Turn "<<time<<"-----\n";
        for (int i=1 ; i<=k ; i++){
            if (bottom[P[i].r][P[i].c] != i) continue;
            // cout<<"Piece "<<i<<"'s move: ";
            int nr = P[i].r + dr[P[i].dir];
            int nc = P[i].c + dc[P[i].dir];
            // moving function
            if (!isRange(nr, nc) || map[nr][nc]==2){
                // cout<<"BLUE..";
                P[i].dir = rev_dir(P[i].dir);
                nr = P[i].r + dr[P[i].dir];
                nc = P[i].c + dc[P[i].dir];
                if (!isRange(nr, nc) || map[nr][nc]==2) { // 반대방향 이동하려고 해도 파란색이면 방향만 바꾸고 넘김
                    // cout<<"\n";
                    continue;
                }
            }
            if (map[nr][nc]==0){
                // cout<<"WHITE to ("<<nr<<", "<<nc<<")\n";
                // cout<<"---BEFORE---\n";
                // cout<<P[1].up<<P[1].down<<endl;
                // cout<<P[2].up<<P[2].down<<endl;
                // cout<<P[3].up<<P[3].down<<endl;
                top[P[i].r][P[i].c] = 0;
                bottom[P[i].r][P[i].c] = 0;
                // cout<<"bottom["<<P[i].r<<"]["<<P[i].c<<"] is now 0\n";
                int cur = i;
                if (top[nr][nc] == 0){
                    P[cur].down = cur;
                    bottom[nr][nc] = cur;
                }
                else {
                    P[top[nr][nc]].up = cur;
                    P[cur].down = top[nr][nc];
                }
                while (1){
                    P[cur].r = nr;
                    P[cur].c = nc;
                    if (cur == P[cur].up) break; // 제일 위 도달
                    cur = P[cur].up;
                }
                top[nr][nc] = cur;
            }
            else if (map[nr][nc]==1){
                // cout<<"RED to ("<<nr<<", "<<nc<<")\n";
                // cout<<"---BEFORE---\n";
                // cout<<P[1].up<<P[1].down<<endl;
                // cout<<P[2].up<<P[2].down<<endl;
                // cout<<P[3].up<<P[3].down<<endl;
                top[P[i].r][P[i].c] = 0;
                bottom[P[i].r][P[i].c] = 0;
                // cout<<"bottom["<<P[i].r<<"]["<<P[i].c<<"] is now 0\n";
                int cur = i;
                int temp;
                while (1){
                    P[cur].r = nr;
                    P[cur].c = nc;
                    temp = P[cur].down;
                    P[cur].down = P[cur].up;
                    P[cur].up = temp;
                    if (cur == P[cur].down) break; // 제일 위 도달
                    cur = P[cur].down;
                }
                // 현재 cur는 기존 위치 중 가장 위에 있던.. 이제 새 위치 제일 중간으로 가야 함
                // if (time==1) cout<<cur;
                if (top[nr][nc] == 0){
                    P[cur].down = cur;
                    bottom[nr][nc] = cur;
                }
                else {
                    P[cur].down = top[nr][nc];
                    P[top[nr][nc]].up = cur;
                }
                top[nr][nc] = i;
            }
            // cout<<"---AFTER---\n";
            // cout<<P[1].up<<P[1].down<<endl;
            // cout<<P[2].up<<P[2].down<<endl;
            // cout<<P[3].up<<P[3].down<<endl;
            // cout<<"-----------\n";
            if (cnt(bottom[P[i].r][P[i].c])>=4){
                cout<<time;
                return 0;
            }
        }
        time++;
    }
    cout<<"-1";
    return 0;
}