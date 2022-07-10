#include <iostream>

using namespace std;

int n, l, r;
int A[50][50];
int team[50][50];
int ally_pop[2500]; // 각 연합의 인구수 합(최대 2500*100 = 250000)
int ally_cnt[2500]; // 각 연합의 나라수 합(최대 2500)
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool changed;

bool isRange(int i, int j){
    return (i>=0 && i<n && j>=0 && j<n);
}

int abs(int x){
    return (x>0)?x:-x;
}

void dfs(int i, int j, int c){
    team[i][j] = c;
    ally_pop[c] += A[i][j];
    ally_cnt[c]++;
    // cout<<"team["<<i<<"]["<<j<<"] = "<<c<<"\n";
    for (int d=0 ; d<4 ; d++){
        int ni = i + dr[d];
        int nj = j + dc[d];
        int diff = abs(A[i][j] - A[ni][nj]);
        if (isRange(ni, nj) && team[ni][nj]==-1 && l<=diff && diff<=r){ // 국경선이 열리는 경우
            // cout<<"("<<i<<", "<<j<<")-("<<ni<<", "<<nj<<") diff: "<<diff<<"\n";
            dfs(ni, nj, c);
            changed = true; // 국경선이 열렸는데 인구 변화가 일어나지 않는 경우는 없다.. ex) L>=1 인데, 40 39에서 열려도 39 39와 같이 변화가 일어남
        }
    }
}

// 처음에는 국경을 bool open[n-1][n-1][bool 가로세로] 이런식으로 하려 했는데, 너무 복잡!
// 조건으로 그때그때 방문하는 DFS 아이디어가 핵심!!!!!

int main(void){
    cin>>n>>l>>r;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>A[i][j];
        }
    }
    int answer = 0;
    while (1){
        changed = false;

        // ally, ally_pop 초기화
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                team[i][j] = -1; // -1이 미방문, 0부터 숫자가 컴포넌트 번호
                ally_pop[i*n+j] = 0; // 가능한 모든 연합 번호의 인구수 초기화
                ally_cnt[i*n+j] = 0; // 가능한 모든 연합 번호의 나라수 초기화
            }
        }

        // 연합별로 구분하기 위한 DFS, 연합별 인구수 합 계산
        int comp = 0;
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                if (team[i][j]==-1) {
                    dfs(i, j, comp++);
                }
            }
        }
        // for (int i=0 ; i<n ; i++){
        //     for (int j=0 ; j<n ; j++){
        //         cout<<team[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        if (!changed) break;
        // 각 연합에 새로운 인구 수 할당
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                int a = team[i][j]; // 연합 번호
                A[i][j] = ally_pop[a] / ally_cnt[a];
            }
        }
        // for (int i=0 ; i<n ; i++){
        //     for (int j=0 ; j<n ; j++){
        //         cout<<A[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        answer++;
    }
    cout<<answer;
    return 0;
}