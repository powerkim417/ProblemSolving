#include <iostream>

using namespace std;

struct shark {
    int speed;
    int dir;
    int size;
};

int mov_r[5] = {0,-1,1,0,0};
int mov_c[5] = {0,0,0,1,-1};

int R,C,M;

bool inRange(int x, int y){
    if (x>=0 && x<R && y>=0 && y<C) return true;
    else return false;
}

int main(void){
    cin>>R>>C>>M;
    int sum = 0;
    // int speed[R][C], dir[R][C], size[R][C];
    shark oldmap[R][C], newmap[R][C];
    for (int i=0 ; i<R ; i++){
        for (int j=0 ; j<C ; j++){
            // speed[i][j] = 0;
            // dir[i][j] = 0;
            // size[i][j] = 0;
            oldmap[i][j] = {0,0,0};
            newmap[i][j] = {0,0,0};
        }
    }
    int r,c,s,d,z;
    while (M-->0){
        cin>>r>>c>>s>>d>>z; // coordinate: (r-1, c-1)
        // speed[r-1][c-1] = s;
        // dir[r-1][c-1] = d;
        // size[r-1][c-1] = z;
        oldmap[r-1][c-1] = {s,d,z};
    }
    for (int man=0 ; man<C ; man++){ // 1. man moves
        // 2. man catches shark
        for (int i=0 ; i<R ; i++){
            if (oldmap[i][man].size != 0) { // encounters shark
                sum += oldmap[i][man].size;
                // cout<<oldmap[i][man].size<<endl;
                oldmap[i][man] = {0,0,0};
                break;
            }
        }
        // 3. sharks move
        for (int i=0 ; i<R ; i++){
            for (int j=0 ; j<C ; j++){
                if (oldmap[i][j].size != 0) { // if shark in the cell
                    int D = oldmap[i][j].dir;
                    int newi = i+mov_r[D]*oldmap[i][j].speed;
                    int newj = j+mov_c[D]*oldmap[i][j].speed;
                    /* 새 방향과 좌표를 부여하는 시간 절약 코드!!
                    대칭의 성질을 이용하여 조금씩 숫자를 접어가면서
                    새 좌표와 방향을 적절히 부여함. */
                    while (!inRange(newi, newj)){ // if out of range
                        if (newi>=R){ // down over
                            newi = 2*(R-1)-newi;
                            oldmap[i][j].dir = 3 - oldmap[i][j].dir; // 1<->2
                        }
                        else if (newi<0){ // up over
                            newi = -newi;
                            oldmap[i][j].dir = 3 - oldmap[i][j].dir; // 1<->2
                        }
                        else if (newj>=C){ // right over
                            newj = 2*(C-1)-newj;
                            oldmap[i][j].dir = 7 - oldmap[i][j].dir; // 3<->4
                        }
                        else if (newj<0){ // left over
                            newj = -newj;
                            oldmap[i][j].dir = 7 - oldmap[i][j].dir; // 3<->4
                        }
                    }
                    
                    /* 아래 코드는 한칸씩 이동하면서
                    그때그때 방향과 좌표를 체크하는 방식이므로 O(speed).
                    이미 O(RC) 안에 있으므로 시간이 매우 오래 걸리게 되어
                    시간초과가 발생하였던 코드입니다. */
                    // int newi = i;
                    // int newj = j;
                    // for (int temp=0 ; temp<oldmap[i][j].speed ; temp++){
                    //     switch (oldmap[i][j].dir){
                    //         case 1: // up
                    //             if (newi==0){
                    //                 oldmap[i][j].dir = 2;
                    //                 newi++;
                    //             } else newi--;
                    //             break;
                    //         case 2: // down
                    //             if (newi==R-1){
                    //                 oldmap[i][j].dir = 1;
                    //                 newi--;
                    //             } else newi++;
                    //             break;
                    //         case 3: // right
                    //             if (newj==C-1){
                    //                 oldmap[i][j].dir = 4;
                    //                 newj--;
                    //             } else newj++;
                    //             break;
                    //         case 4: // left
                    //             if (newj==0){
                    //                 oldmap[i][j].dir = 3;
                    //                 newj++;
                    //             } else newj--;
                    //             break;
                    //     }
                    //     // if (i==0 && j==4) cout<<oldmap[i][j].dir<<" "<<newj<<endl;
                    // }
                    // individual shark move finish
                    // 옮기려고 하는 위치에 이미 있는 상어의 크기 < 이동한 상어의 크기
                    if (newmap[newi][newj].size < oldmap[i][j].size) {
                        // if new shark is bigger, overwrites
                        // or blank
                        newmap[newi][newj] = oldmap[i][j];
                    } 
                    else { // else(older is bigger), no record on new map
                        // cout<<newmap[newi][newj].size<<" "<<oldmap[i][j].size<<endl;
                        // cout<<"size "<<oldmap[i][j].size<<" eliminated at time "<<(man+1)<<endl;
                    }
                }
            }
        }
        // cout<<"======time "<<(man+1)<<endl;
        for (int i=0 ; i<R ; i++){
            for (int j=0 ; j<C ; j++){
                oldmap[i][j] = newmap[i][j];
                newmap[i][j] = {0,0,0};
                // cout<<oldmap[i][j].size<<" ";
            }
            // cout<<endl;
        }


    }
    cout<<sum;
}