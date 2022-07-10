#include <iostream>
#include <vector>

using namespace std;

// white와 red를 합했고, 좌표를 하나하나 옮기지 않고 링크드 리스트로 구현

int n, k;
int map[12][12];
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};

bool isRange(int i, int j){
    return (i>=0 && i<n && j>=0 && j<n);
}

int bottom[12][12]; // 비어있으면 -1로 초기화, 있으면 바닥에 있는 말의 번호 저장

struct piece {
    int d;
    int up; // 자신 위 말의 번호. 없을 경우 자신?
    int down; // 자신 아래 말의 번호. 없을 경우 자신?
};

vector<piece> v;

int top(int n){ // n번째 말의 가장 위에 있는 말 번호 반환
    if (v[n].up == n) return n;
    else return top(v[n].up);
}

int bot(int n){ // n번째 말의 가장 아래에 있는 말 번호 반환
    if (v[n].down == n) return n;
    else return bot(v[n].down);
}

pair<int, int> loc(int num){ // num번째 말의 좌표 반환
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (bottom[i][j] == bot(num)) {
                return {i, j};
            }
        }
    }
    return {-1, -1};
}

int main(void){
    cin>>n>>k;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>map[i][j];
            bottom[i][j] = -1;
        }
    }
    int tempr, tempc, tempd;
    for (int i=0 ; i<k ; i++){
        cin>>tempr>>tempc>>tempd;
        bottom[tempr-1][tempc-1] = i; // 첫 입력때 k개의 말 모두 bottom이 된다.
        v.push_back({tempd-1, i, i});
    }

    // for (int i=0 ; i<n ; i++){
    //     for (int j=0 ; j<n ; j++){
    //         cout<<bottom[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }

    int time = 1;
    int nr, nc;
    while (1){
        // cout<<"---Time "<<time<<"---\n";
        if (time>1000) {
            cout<<"-1";
            return 0;
        }
        bool blue = false;
        // 들어서 -> 뒤집고(red) -> 붙인다
        for (int i=0 ; i<k ; i++){
            // cout<<"<Piece "<<i<<">\n";
            pair<int, int> cur = loc(i);
            nr = cur.first + dr[v[i].d];
            nc = cur.second + dc[v[i].d];
            // cout<<"current loc: ("<<cur.first<<", "<<cur.second<<")\n";
            // cout<<"new loc: ("<<nr<<", "<<nc<<")\n";
            // {nr, nc}: 다음에 이동하는 위치가 아님! 다음에 이동'하려는' 위치! 이렇게 두고 이 위치가 파랑인지 봐야 하는 것
            if (isRange(nr, nc) && map[nr][nc]!=2){ // 흰색 또는 빨간색
                // cout<<"White or Red\n";

                // 이동하려는 말의 바닥 여부
                if (v[i].down == i){ // 이동하려는 말이 바닥 말인 경우
                    bottom[cur.first][cur.second] = -1; // 기존 위치는 비게 됨
                    // cout<<"Prev location empty\n";
                }
                else { // 이동하려는 말이 바닥 말이 아닌 경우
                    // cout<<v[i].down;
                    v[v[i].down].up = v[i].down; // 이동하려는 말 바로 아래가 원래 위치의 가장 위 말이 된다
                    // cout<<"Prev location's top updated\n";
                }

                int _top=top(i), _cur=i, _temp;
                // 색깔(흰, 빨)에 따른 이동되는 말들 순서 조정
                if (map[nr][nc]==1){ // 빨간색이고, 이동 말이 2개 이상인 경우 현재 위치에서 위치 뒤집기..
                    // cout<<"Red\n";
                    // 현재 말부터 가장 위 말까지 순서로 위아래 변경
                    while (1){
                        // cout<<_cur;
                        _temp = v[_cur].up;
                        v[_cur].up = v[_cur].down;
                        v[_cur].down = _temp;
                        if (_cur == _top) break;
                        _cur = v[_cur].down; // 다음 말로 이동
                    }

                    // for (int i=0 ; i<n ; i++){
                    //     for (int j=0 ; j<n ; j++){
                    //         cout<<bottom[i][j]<<" ";
                    //     }
                    //     cout<<"\n";
                    // }

                    // i: 움직이는 스택중 제일 아래였고, 현재는 제일 위
                    // _cur: 움직이는 스택 중 가장 위였고, 현재는 제일 아래
                    if (bottom[cur.first][cur.second] != -1){ // 이동하려는 말이 기존 위치에서 바닥 말이 아니었던 경우
                        v[i].up = i;
                    }
                }

                // 이동하려는 위치의 비어있음 여부
                if (bottom[nr][nc] == -1){ //새 위치가 비어있었던 경우
                    // cout<<"new location was empty\n";
                    v[_cur].down = _cur;
                    bottom[nr][nc] = _cur;
                }
                else { // 새 위치에 이미 말이 있는 경우
                    // cout<<"new location was not empty\n";
                    v[_cur].down = top(bottom[nr][nc]); // 이동하는 말의 아래 말 = 새 위치의 가장 위 말
                    v[top(bottom[nr][nc])].up = _cur; // 새 위치의 가장 위 말의 위 말 = 이동하는 말
                }

                // for (int i=0 ; i<n ; i++){
                //     for (int j=0 ; j<n ; j++){
                //         if (bottom[i][j]==-1) cout<<"* ";
                //         else cout<<bottom[i][j]<<" ";
                //     }
                //     cout<<"\n";
                // }
                
                // for (int i=0 ; i<k ; i++){
                //     cout<<"Number "<<i<<": up "<<v[i].up<<", down "<<v[i].down<<"\n";
                // }

                // (nr, nc) 말 4개 이상인지 체크
                int cnt = 1;
                int check_cur = bottom[nr][nc];
                while (1){
                    // cout<<check_cur;
                    if (check_cur == top(check_cur)) {
                        // cout<<"new location's stack: "<<cnt<<"\n";
                        break;
                    }
                    else {
                        check_cur = v[check_cur].up;
                        cnt++;
                        if (cnt>=4){
                            cout<<time;
                            return 0;
                        }
                    }
                }
                blue = false;
            }
            else { // 파란색 또는 벗어났을 때
                // cout<<"Blue\n";
                if (blue) { // 이 조건을 두번 들어오면 가만히 있고 다음 말로 넘어감
                    blue = false;
                    continue;
                }
                blue = true;
                // 0<->1 , 2<->3 이 되어야 한다.
                if (v[i].d%2==0) v[i].d++;
                else v[i].d--;
                // 방향을 바꾼 뒤, 같은 i에 대해서 다시 포문을 돌도록 한다.
                i--;
            }
        }
        time++;
    }
}