#include <iostream>
#include <queue>

using namespace std;

int n, m, fuel;
int map[20][20];
int r, c;

struct Customer {
    int start;
    int end;
};

typedef pair<int, int> P;

Customer cust[400];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
// bool finished[400] = {};

bool isRange(int i, int j){
    return (i>=0 && i<n && j>=0 && j<n);
}

// {3,2} 와 같은 좌표를 302 로 표현해서 활용(n 최대 20이므로 세자리 침범 X)

int find(){ // m명의 승객들 중 가장 최소 시간이 걸리는 승객을 찾음
    int min_dist = 401;
    int min_cand = -1;
    
    // for (int i=0 ; i<n ; i++){
    //     for (int j=0 ; j<n ; j++){
    //         cout<<map[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    for (int i=0 ; i<m ; i++){
        // if (finished[i]) continue;
        bool visited[20][20] = {};
        queue<P> q; // <좌표 1차원화, 현위치로부터의 거리>
        visited[r][c] = true; // 택시 현위치
        // cout<<"Customer "<<i<<" calculating\n";
        q.push({100*r+c, 0});
        int dist = 0;
        bool found = false; // 현재 최단거리까지 닿지 못하면 false
        // 목적지까지 얼마나 걸리는가?
        while (!q.empty()){
            P cur = q.front();
            q.pop();
            // cout<<cur.first<<"\n";
            if (cur.second > min_dist){
                // cout<<"over min_dist\n";
                break;
            }
            if (map[cur.first/100][cur.first%100] == i){
                dist = cur.second;
                found = true;
                break;
            }
            
            for (int d=0 ; d<4 ; d++){
                int nr = cur.first/100 + dr[d];
                int nc = cur.first%100 + dc[d];
                if (isRange(nr, nc) && map[nr][nc]!=-1 && !visited[nr][nc]){
                    visited[nr][nc] = true;
                    q.push({100*nr+nc, cur.second+1});
                }
            }
        }
        if (!found) {
            // cout<<"over min_dist or not found\n";
            continue;
        }

        if (dist > fuel){ // 해당 승객까지의 거리가 기름 이상이면 패스
            continue;
        }
        else { // 기름으로 갈 수 있음. 최단거리 단축이거나 동일. 넘치는 경우는 없다
            if (dist < min_dist){ // 최단거리 단축
                min_dist = dist;
                min_cand = i;
            }
            else { // 최단거리 동일인 경우 좌표 비교
                if (cust[i].start < cust[min_cand].start) min_cand = i;
            }
        }
    }
    if (min_cand != -1){ // 움직일 승객을 찾은 경우
        r = cust[min_cand].start/100;
        c = cust[min_cand].start%100;
        map[r][c] = -2; // 승객 위치 지움
        fuel -= min_dist;
    }
    return min_cand;
}

bool move(int target){ // 현재 연료로 목적지까지 갈 수 있는지 확인
    bool visited[20][20] = {};
    queue<P> q; // <좌표 1차원화, 현위치로부터의 거리>
    visited[r][c] = true; // 택시 현위치
    q.push({100*r+c, 0});
    int dist;
    bool found = false; // 현재 최단거리까지 닿지 못하면 false
    // cout<<"move start\n";
    // 목적지까지 얼마나 걸리는가?
    while (!q.empty()){
        P cur = q.front();
        q.pop();
        // cout<<cur.first<<"\n";
        if (cur.second > fuel){ // 기름 부족
            return false;
        }
        if (cur.first == cust[target].end){ // 목적지에 도착
            r = cur.first/100;
            c = cur.first%100;
            fuel += cur.second; // -이동거리 +2*이동거리
            return true;
        }
            
        for (int d=0 ; d<4 ; d++){
            int nr = cur.first/100 + dr[d];
            int nc = cur.first%100 + dc[d];
            if (isRange(nr, nc) && map[nr][nc]!=-1 && !visited[nr][nc]){
                visited[nr][nc] = true;
                q.push({100*nr+nc, cur.second+1});
            }
        }
    }
    return false; // 없으면 런타임 에러
}

int solve(){
    for (int i=0 ; i<m ; i++){ // 승객 태우는 행위를 m회 반복
        int cur_cust = find(); // 승객 찾고, 승객에게 가는 것 까지 포함
        // cout<<"customer: "<<cur_cust<<"\n";
        if (cur_cust == -1) return -1;
        // finished[cur_cust] = true;
        // cout<<"come to pick up. remaining fuel: "<<fuel<<"\n";
        bool success = move(cur_cust); // 해당 승객에 대해 목적지까지 간다.
        if (!success) return -1;
        // cout<<"success! remaining fuel: "<<fuel<<"\n";
    }
    return fuel;
}

// map[i][j]==-1: 벽, -2: 빈공간, 0~m: 승객
int main(void){
    cin>>n>>m>>fuel;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>map[i][j];
            map[i][j] -= 2;
        }
    }
    cin>>r>>c;
    r--;
    c--;
    for (int i=0 ; i<m ; i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        a--;
        b--;
        c--;
        d--;
        cust[i] = {a*100+b, c*100+d};
        map[a][b] = i; // 각 탑승객 출발 위치만 본다. 도착위치는 우선순위계산시에만 사용됨..
    }
    cout<<solve();
    return 0;
}