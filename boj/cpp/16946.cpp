#include <iostream>
#include <vector>

using namespace std;

int n,m;
char map[1000][1000];
bool visited[1000][1000] = {};
int ans[1000][1000];
int comp[1000][1000];
vector<int> cnt;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isRange(int r, int c){
    if (r>=0 && r<n && c>=0 && c<m) return true;
    else return false;
}

int comp_num = 0;
int temp = 0;

/*
<해법>
dfs를 한번 쭉 돌면서 컴포넌트마다 번호를 붙이고,
해당 컴포넌트의 값은 이어진 0의 갯수로 정한다. (1번 컴포넌트는 3, .. 이런 식) 
각 벽 기준으로 상하좌우의 컴포넌트들의 값의 합을 구하면 되며,
중복의 경우 한번만 계산하도록 설계!
*/

void dfs(int cur_r, int cur_c){
    visited[cur_r][cur_c] = true;
    temp++;
    comp[cur_r][cur_c] = comp_num;
    for (int i=0 ; i<4 ; i++){
        int new_r = cur_r + dr[i];
        int new_c = cur_c + dc[i];
        if (isRange(new_r, new_c) && !visited[new_r][new_c] && map[new_r][new_c] == '0'){
            dfs(new_r, new_c);
        }
    }
}

int main(void){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
            comp[i][j] = 0;
            if (map[i][j] == '0') ans[i][j] = 0;
            else ans[i][j] = 1;

        }
    }
    cnt.push_back(-1); // cnt[0] 은 쓰지 않으므로 의미없는 값으로 채움

    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            if (!visited[i][j] && map[i][j] == '0') { // 0에 대한 컴포넌트 계산
                comp_num++; // 컴포넌트 번호. 1부터 시작
                temp = 0;
                dfs(i, j);
                cnt.push_back(temp);
            }
        }
    }

    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            // cout<<"map["<<i<<"]["<<j<<"] ??\n";
            if (map[i][j] == '1'){ // 모든 벽에 대해
                // cout<<"map["<<i<<"]["<<j<<"] count\n";
                for (int x=0 ; x<4 ; x++){
                    int newi = i + dr[x];
                    int newj = j + dc[x];
                    if (!isRange(newi, newj) || map[newi][newj]=='1') continue; // 일종의 verify 과정
                    // cout<<"+ ("<<newi<<", "<<newj<<")\n";
                    ans[i][j] += cnt[comp[newi][newj]];
                    for (int y=x+1 ; y<4 ; y++){
                        int cmpi = i + dr[y];
                        int cmpj = j + dc[y];
                        if (!isRange(cmpi, cmpj) || map[cmpi][cmpj]=='1') continue; // 이거 안붙여서 내내 틀렸다... 새 좌표 역시 verify를 해야 함!
                        if (comp[cmpi][cmpj] == comp[newi][newj]) {// 뒤에 같은 컴포넌트가 있으면 그때 더한다 치고 지금은 안더함
                            ans[i][j] -= cnt[comp[newi][newj]];
                            // cout<<"- ("<<newi<<", "<<newj<<")\n";
                            break; // 해당 +에 대해서 더이상 빼지 않도록 한번만 빼고 break
                        }
                    } 
                }
            }
        }
    }

    // for (int i=0 ; i<n ; i++){
    //     for (int j=0 ; j<m ; j++){
    //         cout<<comp[i][j];
    //     }
    //     cout<<"\n";
    // }
    // for (int i=1 ; i<cnt.size() ; i++){
    //     cout<<cnt[i]<<" ";
    // }
    // cout<<"\n";

    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cout<<ans[i][j]%10;
        }
        cout<<"\n";
    }
}