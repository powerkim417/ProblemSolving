#include <iostream>
#include <queue>

using namespace std;

int n, m;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

typedef pair<int, int> P;

int map[100][100]; // 치즈: 1, 치즈X: 0 인데 풀이상 편의를 위해
// 치즈: 1, 치즈 내부공간: 0, 외부: -1, 녹을 예정: -2
bool visited[100][100];

bool isRange(int r, int c){
    return (r>=0 && r<n && c>=0 && c<m);
}

// 2636번 문제는 한면만 닿으면 녹으나, 이 문제는 두면이 닿을 때 녹음
// 이번 문제는 녹는 부분을 결정하기 위해 치즈를 기준으로 삼음

// 치즈 내부의 빈 공간은 따로 처리해줘야 되는 것이 포인트!
// 문제를 대충 읽었을 때는 치즈를 BFS하는 것인줄 알았는데, 자세히 보니 외부 공기를 BFS하는 것이었음

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
        }
    }
    int time = 1;
    while (1){
        // 1. 외부와 내부 구분
        // 밖에서 닿을 수 있는 0들을 찾는 작업
        queue<P> out;
        out.push({0, 0}); // (0, 0)은 확실히 치즈가 아님
        map[0][0] = -1;
        // 오른쪽 아래만 가면 안됨! 끼어있던 왼쪽 위부분에 새 공간이 생길 수 있음
        // visit 처리도 map[i][j] == -1로 하면 안됨! 두번째 루프부터는 외부가 다 -1이므로 내부의 0에 접근하지 못하게 된다.
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                visited[i][j] = false;
            }
        }
        while (!out.empty()){
            P cur = out.front();
            out.pop();
            for (int d=0 ; d<4 ; d++){
                int nr = cur.first + dr[d];
                int nc = cur.second + dc[d];
                if (isRange(nr, nc) && !visited[nr][nc] && map[nr][nc] != 1){
                    out.push({nr, nc});
                    visited[nr][nc] = true;
                    map[nr][nc] = -1;
                }
            }
        }

        // 2. 외부(-1) 2칸 이상과 닿은 치즈는 -2(녹을 예정)로 바꿀 것
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                if (map[i][j] != 1) continue;
                int cnt = 0;
                for (int d=0 ; d<4 ; d++){
                    if (isRange(i+dr[d], j+dc[d]) && map[i+dr[d]][j+dc[d]]==-1) cnt++;
                    if (cnt == 2) break;
                }
                if (cnt == 2) map[i][j] = -2;
            }
        }

        // 3. 녹을 예정인 부분을 -1(외부)로 바꿀 것
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                if (map[i][j] == -2) map[i][j] = -1;
            }
        }

        
        // for (int i=0 ; i<n ; i++){
        //     for (int j=0 ; j<m ; j++){
        //         if (map[i][j]==-1) cout<<"- ";
        //         else cout<<map[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"-------------\n";

        // 4. 치즈가 다 사라졌으면 종료
        bool remain = false;
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                if (map[i][j] == 1) remain = true;
            }
        }
        if (!remain) break;

        time++;

        
    }
    cout<<time;
    return 0;
}