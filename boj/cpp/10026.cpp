#include <iostream>

using namespace std;

int n;
char map[100][100];
bool visited[100][100];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool inRange(int i, int j){
    if (i>=0 && i<n && j>=0 && j<n) return true;
    else return false;
}

void dfs(int i, int j){
    visited[i][j] = true;
    int ni, nj;
    for (int d=0 ; d<4 ; d++){
        ni = i + dr[d];
        nj = j + dc[d];
        if (inRange(ni, nj) && !visited[ni][nj] && map[ni][nj] == map[i][j]){
            /* 0들 중에서 1이 드문드문 있는곳에서의 컴포넌트를 구하는 구조와 달리
            이번엔 맵의 모든 요소이 다 컴포넌트이므로 같은 컴포넌트를 구분하려면
            다음 노드가 현재 노드와 같은 값일 때로 확인하면 된다 */
            dfs(ni, nj);
        }
    }
}

int main(void){
    cin>>n;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            visited[i][j] = false;
            cin>>map[i][j];
        }
    }
    int comp = 0;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            // cout<<map[i][j];
            if (!visited[i][j]){
                comp++;
                dfs(i, j);
            }
        }
        // cout<<endl;
    }
    cout<<comp<<" ";
    // cout<<endl;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            visited[i][j] = false;
            if (map[i][j] == 'G') map[i][j] = 'R';
        }
    }
    comp = 0;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            // cout<<map[i][j];
            if (!visited[i][j]){
                comp++;
                dfs(i, j);
            }
        }
        // cout<<endl;
    }
    cout<<comp;
}