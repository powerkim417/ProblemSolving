#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
int map[20][20];
typedef pair<int, int> P;
queue<P> q;
P baby_loc;
int baby_size = 2;
int eat = 0;
// 한 좌표에 대해 우선순위가 더 높은 좌표 순으로 정렬(상 좌 우 하)
int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};
int dist[20][20]; // 특정 시점에서 아기 상어와 좌표 간 거리. 갈 수 없는 경우 -1로 둔다. 

bool isRange(int i, int j){
    return (i>=0 && i<n && j>=0 && j<n);
}

// 우선순위가 존재하므로 탐색은 아니며, 규칙에 따라 하나하나 먹는게 정해져 있다
// 먹을 수 있는 물고기 중 가장 가까운 물고기, 왼쪽/위 순서대로 먹는다. 먹으면 순위는 다시 고름
// 자기보다 작은 몸집의 물고기를 다 먹는데 걸리는 시간이 답
int main(void) {
	cin>>n;
	for (int i=0 ; i<n ; i++){
		for (int j=0 ; j<n ; j++){
			cin>>map[i][j];
			if (map[i][j] == 9) {
                baby_loc = {i, j};
                map[i][j] = 0;
            }
		}
	}
    int time = 0;
    while (1){
        // <BFS>
        // 1. 방문 가능한 좌표를 BFS로 확인하면서 탐색
        // 2. 방문 중 물고기가 있는 좌표를 발견한 경우, 해당 시간이 BFS의 마지막 반복이 되며
        // 이 시간에 발견한 물고기들에 대해 가장 위-왼쪽에 있는 물고기 좌표를 계속 갱신.
        /* 
        dr,dc 세팅 해놨는데도 그냥 가장 먼저 발견한 물고기를 쓰면 안되는 이유
        10초에 물고기를 발견하고, 11초에 빈 공간 2곳을 큐에 넣고, 이 빈 공간에서 이동해서 12초에 두 물고기를 발견했을 경우
        더 왼쪽 위에 있는 물고기를 골라야 하지만 실제로는 더 위-왼쪽에 있던 11초 빈공간에서 도달한 물고기를 먼저 탐색한다... 이 물고기를 고르면 안됨
        */   
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                dist[i][j] = -1;
            }
        }
        q = queue<P>();
        q.push(baby_loc);
        dist[baby_loc.first][baby_loc.second] = 0;
        int temp = 1; // 거리
        bool found = false;
        while (!q.empty()){
            int qs = q.size();
            for (int s=0 ; s<qs ; s++){
                P cur = q.front();
                q.pop();
                int ni, nj;
                for (int d=0 ; d<4 ; d++){
                    ni = cur.first + dr[d];
                    nj = cur.second + dc[d];
                    if (isRange(ni, nj) && dist[ni][nj]==-1 && map[ni][nj]<=baby_size){
                        // cout<<"queue push "<<ni<<" "<<nj<<"\n";
                        q.push({ni, nj});
                        dist[ni][nj] = temp;
                        if (map[ni][nj] >= 1 && baby_size > map[ni][nj]){ // 자신보다 작은 물고기 발견.
                            // cout<<"fish found "<<ni<<" "<<nj<<"\n";
                            if (!found) { // 처음이면 일단 위치 확보
                                found = true;
                                baby_loc = {ni, nj};
                            }
                            else { // 해당 거리에서 처음 발견한 물고기가 아니면 위치 비교 후 갱신
                                if (ni*n + nj < baby_loc.first*n + baby_loc.second) baby_loc = {ni, nj};
                            }
                            break; // 해당 cur에 대한 next는 처음꺼만 보면 됨
                        }
                    }
                }
                // 같은 거리의 모든 cur에 대해서는 next를 다 봐야 하므로, 발견했더라도 break하지 않음
            }
            // 같은 시간에 대해 모두 탐색 완료.
            if (found) {    
                // 먹으러 간 거리만큼 시간 증가
                time += temp;
                // cout<<"<Time "<<time<<"> Baby shark moves to ("<<baby_loc.first<<", "<<baby_loc.second<<"), and eat size "<<map[baby_loc.first][baby_loc.second]<<".\n";
                // 물고기가 먹혔으므로 그곳의 map값은 0이 됨
                map[baby_loc.first][baby_loc.second] = 0;
                // 경험치(?) 증가, 이에 따른 크기 조정
                eat++;
                if (eat == baby_size){
                    baby_size++;
                    // cout<<"Baby shark's size is now "<<baby_size<<".\n";
                    eat = 0;
                }
                break; // BFS 종료
            }
            // 발견 못했으면 거리 1 증가
            temp++;
            // cout<<"temp: "<<temp<<"\n";
        }
        // BFS가 종료된 순간.
        if (!found){ // BFS를 다 돌았는데도 물고기를 못찾았으면 엄마 상어 호출
            break;
        }
        // 물고기를 발견한 경우.. 이미 상어도 이동했고 시간도 더해졌고 몸집도 변화되었으므로 더 처리해줄 것이 없다.
    }
    cout<<time;
	return 0;
}