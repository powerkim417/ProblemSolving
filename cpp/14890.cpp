#include <iostream>

using namespace std;

int N, L;

bool inRange(int i, int j){
    if (i>=0 && i<N && j>=0 && j<N) return true;
    else return false;
}

int main(void){
    cin>>N>>L;
    int map[N][N];
    for (int i=0 ; i<N ; i++){
        for (int j=0 ; j<N ; j++){
            cin>>map[i][j];
        }
    }
    int ans = 2*N;

    // 경사로는 높이가 1이고 길이가 L

    bool slope; // 아랫경사로 되는지 진행중
    int flat; // 평지 연속
    bool able;

    // cout<<"--Horizontal--\n";
    for (int i=0 ; i<N ; i++){ // 가로 경로
        slope = false;
        flat = 1;
        able = true;
        // cout<<"line "<<i<<"\n";
        for (int j=1 ; j<N ; j++){
            if (slope && (flat == L)){
                flat = 0;
                slope = false;
            }
            if (!slope){ // 아랫경사 판단중이 아닌 경우
                if (map[i][j]-map[i][j-1] == 0) {
                    flat++;
                }
                else if (map[i][j]-map[i][j-1] == -1) { // -_
                    slope = true;
                    flat = 1;
                }
                else if (map[i][j]-map[i][j-1] == 1) { // _-
                    if (flat >= L){
                        flat = 1;
                    }
                    else { // 넉넉한 공간 없이 올라가야 함
                        able = false;
                        // cout<<j<<"incline error\n";
                        break;
                    }
                }
                else { // 칸 차이가 2 이상
                    // cout<<j<<"gap error\n";
                    able = false;
                    break;
                }
            }
            else { // 아랫 경사로 진행중.. -_ 바로 이후
                if (map[i][j]-map[i][j-1]== 0) {
                    flat++;
                }
                else { // 경사로가 다 깔려야 되는데 그 전에 다른 경우 발생
                    // cout<<j<<"decline error\n";
                    able = false;
                    break;
                }
            }
        }
        if (slope && flat<L) {
            // cout<<"not enough place error\n";
            able = false;
        }
        if (!able){
            ans--;
        }
        else {
            // cout<<i<<"\n";
        }
    }

    // cout<<"--Vertical--\n";
    for (int j=0 ; j<N ; j++){ // 세로 경로
        slope = false;
        flat = 1;
        able = true;
        // cout<<"line "<<j<<"\n";
        for (int i=1 ; i<N ; i++){
            if (slope && (flat == L)){
                flat = 0;
                slope = false;
            }
            if (!slope){ // 아랫경사 판단중이 아닌 경우
                if (map[i][j]-map[i-1][j] == 0) {
                    flat++;
                }
                else if (map[i][j]-map[i-1][j] == -1) { // -_
                    slope = true;
                    flat = 1;
                }
                else if (map[i][j]-map[i-1][j] == 1) { // _-
                    if (flat >= L){
                        flat = 1;
                    }
                    else { // 넉넉한 공간 없이 올라가야 함
                        able = false;
                        // cout<<i<<"incline error\n";
                        break;
                    }
                }
                else { // 칸 차이가 2 이상
                    // cout<<i<<"gap error\n";
                    able = false;
                    break;
                }
            }
            else { // 아랫 경사로 진행중.. -_ 바로 이후
                if (map[i][j]-map[i-1][j]== 0) {
                    flat++;
                }
                else { // 경사로가 다 깔려야 되는데 그 전에 다른 경우 발생
                    // cout<<i<<"decline error\n";
                    able = false;
                    break;
                }
            }
        }
        if (slope && flat<L) {
            // cout<<"not enough place error\n";
            able = false;
        }
        if (!able){
            ans--;
        }
        else {
            // cout<<j<<"\n";
        }
    }
    cout<<ans;
    return 0;
}