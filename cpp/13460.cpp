#include <iostream>
#include <queue>

using namespace std;

int n,m;
char map[10][10];
bool visited[100][100]; // [red ball index][blue ball index]
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

struct point {
    int r;
    int c;
};

point red, blue, hole;

struct state {
    point R;
    point B;
};

int idx(point p){
    return (p.r*m + p.c);
}

bool inRange(point p){
    int i = p.r;
    int j = p.c;
    if (i>=0 && i<n && j>=0 && j<m) return true;
    else return false;
}

state move(state st, int d){ // d: 0상, 1우, 2하, 3좌
    point newR, newB; // 예상 위치
    bool redhole = false; // 빨간공이 들어간 이후에는 위치 무시
    while (1){ // 파랑이 구멍에 들어갔거나(빨강이 들어간 뒤는 파랑이 들어갈 수도 있으니 일단 더 돎), 둘다 위치가 안바뀌면 탈출
        if (!redhole) newR = {st.R.r + dr[d], st.R.c + dc[d]};
        newB = {st.B.r + dr[d], st.B.c + dc[d]};

        // 벽을 고려한 예상 위치(다시 원래 자리로)
        if (!inRange(newR) || map[newR.r][newR.c] == '#'){
            if (!redhole) newR = st.R;
        }
        if (!inRange(newB) || map[newB.r][newB.c] == '#'){
            newB = st.B;
        }
        // cout<<"R: "<<newR.r<<" "<<newR.c<<", B: "<<newB.r<<" "<<newB.c<<endl;
        
        // 구슬 겹치는지 확인. 겹친다면 이전으로 돌아고 끝
        if (newR.r == newB.r && newR.c == newB.c)
            if (!redhole) break;
        
        if (newR.r == st.R.r && newR.c == st.R.c && newB.r == st.B.r && newB.c == st.B.c){ // 바뀔 위치가 그대로인 경우(안움직인 경우)
            break;
        }

        // 바뀔 위치 확정!!!!
        st.R = newR;
        st.B = newB;

        // 구멍
        if (st.R.r == hole.r && st.R.c == hole.c)
            redhole = true; // 빨간 공이 들어간 이후에 파란 공이 들어갈 수도 있으므로 계속 돌아줘야 함
            
        if (st.B.r == hole.r && st.B.c == hole.c)
            break;
    }
    return st;
}

int main(void){
    cin>>n>>m;
    for (int i=0 ; i<n*m ; i++){
        for (int j=0 ; j<n*m ; j++){
            visited[i][j] = false;
        }
    }
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
            if (map[i][j] == 'R') {
                red = {i,j};
                map[i][j] = '.';
            }
            if (map[i][j] == 'B') {
                blue = {i,j};
                map[i][j] = '.';
            }
            if (map[i][j] == 'O') hole = {i,j};
        }
    }
    queue<state> q;
    q.push({red, blue});
    visited[idx(red)][idx(blue)] = true;
    int time = 0;
    int q_size = q.size();
    bool finish = false;

    // DEBUG CODE
    // state asdf = move(q.front(), 3);
    // cout<<asdf.R.r<<" "<<asdf.R.c<<endl;
    // cout<<asdf.B.r<<" "<<asdf.B.c<<endl;
    // return 0;

    while (!q.empty()){
        int q_size = q.size();
        for (int s=0 ; s<q_size ; s++){
            state cur = q.front();
            if (cur.R.r == hole.r && cur.R.c == hole.c){
                // 빨간공이 구멍에 들어간 경우
                finish = true;
                break;
            }
            q.pop();
            for (int i=0 ; i<4 ; i++){
                state next = move(cur, i);
                if (!visited[idx(next.R)][idx(next.B)]){
                    if (next.B.r == hole.r && next.B.c == hole.c){
                        // 파란공이 구멍에 들어간 경우는 무시
                        continue;
                    }
                    visited[idx(next.R)][idx(next.B)] = true;
                    q.push(next);
                }
            }
        }
        if (finish) break;
        time++;
        if (time > 10) break;
    }
    if (finish && time <= 10) cout<<time;
    else cout<<"-1";
}