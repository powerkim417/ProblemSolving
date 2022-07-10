#include <iostream>

using namespace std;

int r,c;
char map[20][20];

bool used[26];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int answer = 1; // 사이즈가 1*1일 때는 비교문이 없으므로 1로 초기화

bool inRange(int i, int j){
    if (i>=0 && i<r && j>=0 && j<c) return true;
    else return false;
}

/*
백트래킹 문제를 해결하기 위해!!!!!!!!!!!!
변수 저장 상황을 과거로 돌려야 함
격자라고 헷갈리지 말고, 모든 경우를 이진트리라고 생각하면 편함
특정 노드에서 볼일을 다 마쳤으면 해당 노드의 visited를 false로 두고, 그 노드에 대한 dfs 함수가 끝나면 된다.
*/

void dfs(int i, int j, int len){
    if (len > answer) answer = len; // 아래 다음칸 갈 때 dfs 호출 전후에 부르면 값이 꼬이므로 새로운 dfs를 부를 때 갱신할 것
    // cout<<"dfs("<<i<<", "<<j<<", "<<len<<") called\n";
    used[map[i][j]-'A'] = true;
    for (int d=0 ; d<4 ; d++){
        int ni = i + dr[d];
        int nj = j + dc[d];
        if (inRange(ni, nj) && !used[map[ni][nj]-'A']){
            dfs(ni, nj, len+1);
        }
    }
    // 노드 (i, j)에 대한 탐색이 끝났으므로 뒤로 간다.
    used[map[i][j]-'A'] = false;
}

int main(void){
    cin>>r>>c;
    for (int i=0 ; i<26 ; i++) used[i] = false;
    for (int i=0 ; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            cin>>map[i][j];
        }
    }
    dfs(0, 0, 1);
    cout<<answer;
}