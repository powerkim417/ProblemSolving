#include <iostream>
#include <vector>

using namespace std;

int r, c;
char map[100][100];
int visited[100][100]; // -1 빈공간, 0 공중 클러스터, 1 바닥 클러스터
int n, h;
bool fromLeft = true;
vector<pair<int, int>> floatCluster;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isRange(int i, int j){
    return (i>=0 && i<r && j>=0 && j<c);
}

void shoot(bool fromLeft){
    for (int j=0 ; j<c ; j++){
        int target = (fromLeft ? j : c-1-j);
        if (map[h][target]=='x'){
            map[h][target] = '.';
            break;
        }
    }
    // cout<<"after shoot "<<h<<"\n";
    // for (int i=0 ; i<r ; i++){
    //     for (int j=0 ; j<c ; j++){
    //         cout<<map[i][j];
    //     }
    //     cout<<"\n";
    // }
    // cout<<"--------\n";
    return;
}

void dfs(int i, int j){
    visited[i][j] = 1;
    for (int d=0 ; d<4 ; d++){
        int ni = i + dr[d];
        int nj = j + dc[d];
        if (isRange(ni, nj) && map[ni][nj]=='x' && visited[ni][nj]==0) dfs(ni, nj);
    }
}

// 땅에 붙어있는 클러스터들을 제외하면 딱 하나의 클러스터만이 남음이 보장됨
void drop(){
    for (int i=0 ; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            if (map[i][j]=='x') visited[i][j] = 0;
            else visited[i][j] = -1; // 빈 공간은 조건에 들어가지 않을 것이므로 공중 클러스터를 구분하기 편하게 미리 true 처리
        }
    }
    // 땅에 있는 클러스터 제외
    for (int j=0 ; j<c ; j++){
        if (visited[r-1][j]==0) {
            if (map[r-1][j]=='x') dfs(r-1, j);
        }
    }
    // cout<<"remaining cluster\n";
    // for (int i=0 ; i<r ; i++){
    //     for (int j=0 ; j<c ; j++){
    //         if (visited[i][j]==0) cout<<"x";
    //         else cout<<".";
    //     }
    //     cout<<"\n";
    // }
    // cout<<"--------\n";

    // 공중 클러스터는 visited[i][j]=0; 바닥 미네랄은 visit[i][j]=1;
    int drop_len = r; // 각 열마다 이 값을 갱신해서 가장 최소로 나오는 값만큼 공중 클러스터를 떨어뜨릴 수 있음
    int temp;
    floatCluster.clear();
    for (int i=0 ; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            if (visited[i][j]==0) floatCluster.push_back({i, j});
        }
    }
    for (int j=0 ; j<c ; j++){
        int float_bottom = -1; //열에서 공중 클러스터의 가장 아래 좌표
        int floor_top = r; // !!!!!!!!!!! float_bottom 아래부터 봤을 때 바닥 미네랄의 가장 위 좌표
        for (int i=r-1 ; i>=0 ; i--){
            if (visited[i][j]==0) {
                float_bottom = i;
                break;
            }
        }
        if (float_bottom == -1) continue;
        for (int i=float_bottom+1 ; i<r ; i++){
            if (visited[i][j]==1) {
                floor_top = i;
                break;
            }
        }
        int temp = floor_top - float_bottom - 1;
        // cout<<"j: "<<j<<", floor_top: "<<floor_top<<", float_bottom: "<<float_bottom<<"\n";
        if (drop_len > temp) drop_len = temp;
    }
    // 기존 공중 클러스터 삭제
    for (auto f: floatCluster){
        map[f.first][f.second] = '.';
    }

    // 새 공중 클러스터 삽입
    for (auto f: floatCluster){
        map[f.first+drop_len][f.second] = 'x';
    }

    // cout<<"after drop\n";
    // for (int i=0 ; i<r ; i++){
    //     for (int j=0 ; j<c ; j++){
    //         cout<<map[i][j];
    //     }
    //     cout<<"\n";
    // }
    // cout<<"--------\n";
    return;
}

int main(void){
    cin>>r>>c;
    for (int i=0 ; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            cin>>map[i][j];
        }
    }
    cin>>n;
    while (n--){
        cin>>h;
        h = r-h;
        shoot(fromLeft);
        fromLeft = !fromLeft;
        drop();
    }
    for (int i=0 ; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }
    return 0;
}