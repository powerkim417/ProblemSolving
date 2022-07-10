#include <iostream>
#include <queue>

using namespace std;

struct state {
    pair<int, int> red;
    pair<int, int> blue;
};
int n, m;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
char map[10][10];
bool visited[100][100] = {}; // idx(red), idx(blue)
queue<state> q;
pair<int, int> hole;

int idx(pair<int, int> loc){
    return (loc.first*m + loc.second);
}

// 구슬탈출 2(13460)과 비교했을 때 가장 차이가 큰 풀이 부분
// 우선 두 구슬에 대해서 각각 예상 도착 지점을 구하고, 그 위치가 겹치는 경우 초기 위치에 따라 조정
state move(state cur, int d){ // 벽 및 구멍 등 물리적 변수에 맞게 단순히 이동한 결과만을 반환
    state ret = cur;
    // cout<<"DIRECTION: "<<d<<"\n";
    while (map[ret.red.first+dr[d]][ret.red.second+dc[d]]!='#'){
        ret.red.first += dr[d];
        ret.red.second += dc[d];
        // cout<<"RED CHANGE TO ("<<ret.red.first<<", "<<ret.red.second<<")\n";
        if (ret.red == hole) break; // 구멍에 빠진 경우 구멍 위치를 반환
    }   
    while (map[ret.blue.first+dr[d]][ret.blue.second+dc[d]]!='#'){
        ret.blue.first += dr[d];
        ret.blue.second += dc[d];
        if (ret.blue == hole) break; // 구멍에 빠진 경우 구멍 위치를 반환
    }
    // cout<<"temp state -> R("<<ret.red.first<<", "<<ret.red.second<<"), B("<<ret.blue.first<<" ,"<<ret.blue.second<<")\n";
    if (ret.red != ret.blue) return ret; // 둘이 다른 위치로 끄탄면 조정할 필요 없음
    else {
        if (ret.red == hole) return ret; // 둘이 같은 위치여도 그게 구멍에 빠진거라면 조정할 필요 없음
        // 조정이 필요한 경우
        // 왼쪽이나 위(-,d%2==0)로 갈 때는 원래 더 오른쪽/아래에 있던 애가 양보해야 함
        // 오른쪽이나 아래(+, d%2==1)로 갈 때는 원래 더 왼쪽에 있던 애가 양보해야 함
        switch (d){
            case 0: // 위
            if (cur.red.first<cur.blue.first) ret.blue.first += 1;
            else ret.red.first += 1;
            break;
            case 1: // 아래
            if (cur.red.first<cur.blue.first) ret.red.first -= 1;
            else ret.blue.first -= 1;
            break;
            case 2: // 왼쪽
            if (cur.red.second<cur.blue.second) ret.blue.second += 1;
            else ret.red.second += 1;
            break;
            case 3: // 오른쪽
            if (cur.red.second<cur.blue.second) ret.red.second -= 1;
            else ret.blue.second -= 1;
            break;
        }
        // cout<<"changed state -> R("<<ret.red.first<<", "<<ret.red.second<<"), B("<<ret.blue.first<<" ,"<<ret.blue.second<<")\n";
        return ret;
    }
}

bool bfs(state start){
    int time = 0; // push할 때의 시각
    q.push(start);
    // cout<<"R("<<start.red.first<<", "<<start.red.second<<"), B("<<start.blue.first<<" ,"<<start.blue.second<<")\n";
    visited[idx(start.red)][idx(start.blue)] = true;
    time++;
    while (!q.empty()){
        // cout<<"---Time "<<time<<"---\n";
        int q_size = q.size();
        while (q_size--){
            state cur = q.front();
            // cout<<"R("<<cur.red.first<<", "<<cur.red.second<<"), B("<<cur.blue.first<<" ,"<<cur.blue.second<<")\n";
            q.pop();
            for (int d=0 ; d<4 ; d++){
                state next = move(cur, d);
                if (visited[idx(next.red)][idx(next.blue)]) continue;
                visited[idx(next.red)][idx(next.blue)] = true;
                if (next.red == hole){ // 빨간공이 들어갔을 때
                    if (next.blue != hole) { // 파란공은 안들어갔으면 성공
                        // cout<<"FINISH!\n";
                        return true; 
                    }
                    // 파란공도 들어갔으면 실패이므로 가지 끝
                }
                /* 파란공도 들어가서 실패인 경우는 가지가 이어지지 않는 경우인데,
                이 경우 visit처리를 해줘도 되고 안해줘도 되나?
                기존 코드들에서는 () && () && () 형식으로 모든 조건을 만족해야만 visit했으므로
                위처럼 실패인 가지는 visit처리하지 않고, 다시 방문하고, 다시 실패하는 식으로 구현하여
                실제로 큰 차이는 없다.
                시간을 줄이려면 next에 값이 들어왔을 때 바로 방문해도 되지만,
                나중에 visit 배열을 사용하려 할 때 visit 배열의 의미에 실패한 state가 들어가도 되느냐 마느냐에 대한 관점 차이가 있을 수 있을듯
                여기서는 실패한 state도 확인했다는 의미로 방문처리 해보겠음
                */
                else { // 빨간공이 안들어가졌다
                    if (next.blue != hole){ // 파란공도 안들어가졌으면 이 state는 더 이어질 여지가 있음
                        q.push(next);
                        // cout<<"R("<<next.red.first<<", "<<next.red.second<<"), B("<<next.blue.first<<" ,"<<next.blue.second<<")\n";
                        // visited[idx(next.red)][idx(next.blue)] = true;
                    }
                }
            }
        }
        time++;
        if (time>10) return false;
    }
    return false;
}

int main(void){
    cin>>n>>m;
    state start;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
            if (map[i][j]=='R') start.red = {i, j};
            if (map[i][j]=='B') start.blue = {i, j};
            if (map[i][j]=='O') hole = {i, j};
        }
    }
    cout<<(int)bfs(start);
}