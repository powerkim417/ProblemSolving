#include <iostream>

using namespace std;

int n, m, h;
typedef pair<int, int> P;

bool used[30][9] = {}; // i(0~29)번째 순서에서 j(0~8),j+1 세로선이 교차
bool flag = false;
int answer = 4;

bool calc(){ // O(nh)
    for (int i=0 ; i<n ; i++){ // 각 세로선의 결과 확인
        int result = i;
        for (int j=0 ; j<h ; j++){
            if (result != n-1 && used[j][result]) result++;
            else if (result != 0 && used[j][result-1]) result--;
        }
        if (result != i) return false;
    }
    return true;
}

// 가로선이 연속하거나 접하면 안됨: used 배열에서 자신 좌우에 true가 있으면 본인은 true가 될 수 없음
// 이 좌표에 가로선을 놓는게 가능한지 판별
bool able(int i, int j){
    if ((j==0 || !used[i][j-1]) && (j==h-1 || !used[i][j+1])) return true;
    else return false;
}

/* 백트래킹 짤 때 주의사항!!!!!!!!!!!!!
dfs 첫 부분에 횟수 초과 검증을 넣지 말 것.
3번까지만 돌아야 하는 dfs에서 시작 시 4번 돌았으면 break를 하는 경우는
3번째 방문으로 마지막 노드를 했을 때, 마지막 노드에서 더 방문을 하지 못하므로 4번 돌지 못하여 해당 경우를 검증할 수 없다.
따라서, 방문 - 검증 - 백트래킹 원상복귀 순서로 해야 한다.
*/

void dfs(int i, int j, int cnt){ // 가로선 (i,j)를 넣으려 함. 현재 cnt개의 가로선 들어있음
    // cnt번째 가로선 (i,j) 방문.
    used[i][j] = true;
    // cout<<"dfs("<<i<<","<<j<<","<<cnt<<")\n";
    // for (int i=0 ; i<h ; i++){
    //     for (int j=0 ; j<n-1 ; j++){
    //         cout<<used[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    if (calc()){
        // cout<<"YES\n";
        flag = true;
        if (cnt < answer) answer = cnt;
        used[i][j] = false; // 백트래킹 원상복귀 필수!!
        return;
    }
    if (cnt==3) { // 가로선이 3개 그려졌으면 더 재귀하지 않음
        used[i][j] = false; // 백트래킹 원상복귀 필수!!
        return;
    }
    // 다음 가로선 결정
    for (int ni=0 ; ni<h ; ni++){
        for (int nj=0 ; nj<n-1 ; nj++){
            if (ni<i) continue;
            if (ni==i && nj<=j) continue;
            // 좌표상 현재 가로선(i, j) 이후의 가로선만 따짐
            if (!used[ni][nj] && able(ni, nj)) dfs(ni, nj, cnt+1); 
        }
    }
    used[i][j] = false;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>h;
    int a, b;
    for (int i=0 ; i<m ; i++){
        cin>>a>>b;
        used[a-1][b-1] = true;
    }
    if (calc()){ // 더 놓을 필요가 없는 경우
        cout<<"0";
        return 0;
    }
    // 선을 추가해야 하는 경우
    // 선이 없는 좌표 중 놓는게 가능한 좌표에 한해 백트래킹 DFS 수행
    // 3개 초과 놓는 경우 불가능(-1)으로 간주하므로 깊이가 얕은 재귀가 되어 해도 된다!
    for (int i=0 ; i<h ; i++){
        for (int j=0 ; j<n-1 ; j++){
            if (!used[i][j] && able(i, j)) dfs(i, j, 1); 
        }
    }
    if (!flag) cout<<"-1";
    else cout<<answer;
    return 0;
}