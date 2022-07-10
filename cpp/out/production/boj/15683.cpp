#include <iostream>
#include <vector>

using namespace std;

int n, m;
int map[8][8];

/*
1. 매 경우 새로 cctv 경로를 찍는 brute force
CCTV 최대 8대
각 종류별 연산 수는 직사각형 내부에 점을 찍고, 그 점에서 상하좌우 길이가 몇번 포함되는지 보면 된다.
1: 네 경우 모두 합하면 m+n=16
2: 두 경우 모두 합하면 m+n=16
3: 네 경우 모두 합하면 2m+2n=32
4: 네 경우 모두 합하면 3m+3n=48
5: 한 경우 m+n=16
즉 최악의 경우 4번 카메라가 8대 있을 때
48^8 = ???? 안됨

2. DFS 백트래킹으로 접근?
모든 경우의 수를 나타낸 그래프가 있고, CCTV의 방향 가짓수가 노드 선택지가 되는 식
이 경우 연산 수를 어떻게 계산하지
일단 8제곱 형태는 아님!
*/

struct cctv {
    int r;
    int c;
    int num;
};

struct point {
    int r;
    int c;
};

vector<cctv> v;

bool visited[8][8] = {};
int cctv_num;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
// 상 우 하 좌
int answer;

bool isRange(int i, int j){
    return (i>=0 && i<n && j>=0 && j<m);
}

// 사각지대: 전체 영역에서 보는 영역, cctv, 벽 위치 제외
int count(){
    int ret = n*m;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            if (visited[i][j] || map[i][j]>0) ret--;
        }
    }
    return ret;
}

/*
이 문제는 answer가 제일 큰 값(n*m)에서 시작해서 조금씩 깎이다가 최소 여부를 판정을 하므로
현재 값이 answer보다 높다고 해도 가지치기를 할 수 없다. 
*/
void dfs(int idx){
    vector<point> temp;
    if (idx==cctv_num){ // 다 돌았을 경우
        // for (int i=0 ; i<n ; i++){
        //     for (int j=0 ; j<m ; j++){
        //         cout<<visited[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<count()<<"\n";
        if (count() < answer) answer = count();
        return;
    }
    cctv cur = v[idx];
    int curr, curc;
    switch (cur.num){
        case 1: // 0 1 2 3
        for (int i=0 ; i<4 ; i++){
            // cout<<"---CCTV "<<idx<<": "<<cur.num<<"---\n";
            // cout<<i<<"\n";
            curr = cur.r;
            curc = cur.c;
            while (isRange(curr, curc) && map[curr][curc]!=6){
                if (!visited[curr][curc]) temp.push_back({curr, curc});
                visited[curr][curc] = true;
                curr += dr[i];
                curc += dc[i];
            }
            dfs(idx+1);
            for (auto t: temp){ // true 마킹한 좌표를 저장했다가 dfs 끝나고 백트래킹으로 돌아오면 원상복귀
                visited[t.r][t.c] = false;
            }
            temp.clear();
        }
        break;
        case 2: // 02 13
        for (int i=0 ; i<2 ; i++){
            // cout<<"---CCTV "<<idx<<": "<<cur.num<<"---\n";
            // cout<<i<<" "<<i+2<<"\n";
            curr = cur.r;
            curc = cur.c;
            while (isRange(curr, curc) && map[curr][curc]!=6){
                // cout<<curr<<" "<<curc<<"\n";
                if (!visited[curr][curc]) temp.push_back({curr, curc});
                visited[curr][curc] = true;
                curr += dr[i];
                curc += dc[i];
            }
            curr = cur.r;
            curc = cur.c;
            while (isRange(curr, curc) && map[curr][curc]!=6){
                // cout<<curr<<" "<<curc<<"\n";
                if (!visited[curr][curc]) temp.push_back({curr, curc});
                visited[curr][curc] = true;
                curr += dr[i+2];
                curc += dc[i+2];
            }
            dfs(idx+1);
            for (auto t: temp){ // true 마킹한 좌표를 저장했다가 dfs 끝나고 백트래킹으로 돌아오면 원상복귀
                visited[t.r][t.c] = false;
            }
            temp.clear();
        }
        break;
        case 3: // 01 12 23 30
        for (int i=0 ; i<4 ; i++){
            curr = cur.r;
            curc = cur.c;
            while (isRange(curr, curc) && map[curr][curc]!=6){
                if (!visited[curr][curc]) temp.push_back({curr, curc});
                visited[curr][curc] = true;
                curr += dr[i];
                curc += dc[i];
            }
            curr = cur.r;
            curc = cur.c;
            while (isRange(curr, curc) && map[curr][curc]!=6){
                if (!visited[curr][curc]) temp.push_back({curr, curc});
                visited[curr][curc] = true;
                curr += dr[(i+1)%4];
                curc += dc[(i+1)%4];
            }
            dfs(idx+1);
            for (auto t: temp){ // true 마킹한 좌표를 저장했다가 dfs 끝나고 백트래킹으로 돌아오면 원상복귀
                visited[t.r][t.c] = false;
            }
            temp.clear();
        }
        break;
        case 4: // 012 123 230 301
        for (int i=0 ; i<4 ; i++){
            // cout<<"---CCTV "<<idx<<": "<<cur.num<<"---\n";
            // cout<<i<<" "<<(i+1)%4<<" "<<(i+2)%4<<"\n";
            curr = cur.r;
            curc = cur.c;
            while (isRange(curr, curc) && map[curr][curc]!=6){
                // cout<<curr<<" "<<curc<<"\n";
                if (!visited[curr][curc]) temp.push_back({curr, curc});
                visited[curr][curc] = true;
                curr += dr[i];
                curc += dc[i];
            }
            curr = cur.r;
            curc = cur.c;
            while (isRange(curr, curc) && map[curr][curc]!=6){
                // cout<<curr<<" "<<curc<<"\n";
                if (!visited[curr][curc]) temp.push_back({curr, curc});
                visited[curr][curc] = true;
                curr += dr[(i+1)%4];
                curc += dc[(i+1)%4];
            }
            curr = cur.r;
            curc = cur.c;
            while (isRange(curr, curc) && map[curr][curc]!=6){
                // cout<<curr<<" "<<curc<<"\n";
                if (!visited[curr][curc]) temp.push_back({curr, curc});
                visited[curr][curc] = true;
                curr += dr[(i+2)%4];
                curc += dc[(i+2)%4];
            }
            dfs(idx+1);
            for (auto t: temp){ // true 마킹한 좌표를 저장했다가 dfs 끝나고 백트래킹으로 돌아오면 원상복귀
                visited[t.r][t.c] = false;
            }
            temp.clear();
        }
        break;
        case 5: // 0123
        // 앞 4개와 구조가 다름!!
        for (int i=0 ; i<4 ; i++){
            curr = cur.r;
            curc = cur.c;
            while (isRange(curr, curc) && map[curr][curc]!=6){
                if (!visited[curr][curc]) temp.push_back({curr, curc});
                visited[curr][curc] = true;
                curr += dr[i];
                curc += dc[i];
            }
        }
        dfs(idx+1);
        for (auto t: temp){ // true 마킹한 좌표를 저장했다가 dfs 끝나고 백트래킹으로 돌아오면 원상복귀
            visited[t.r][t.c] = false;
        }
        temp.clear();
        break;
    }
}

int main(void){
    cin>>n>>m;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
            if (map[i][j]>0 && map[i][j]<6) v.push_back({i, j, map[i][j]});
        }
    }
    // CCTV가 최소 1개 있다고 가정
    cctv_num = v.size();
    answer = n*m;
    dfs(0);
    cout<<answer;
}