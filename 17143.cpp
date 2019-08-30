#include <iostream>

using namespace std;

struct shark {
    int speed;
    int dir;
    int size;
};

int main(void){
    int R,C,M;
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
                oldmap[i][man] = {0,0,0};
                break;
            }
        }
        // 3. sharks move
        for (int i=0 ; i<R ; i++){
            for (int j=0 ; j<C ; j++){
                int newi = i, newj = j;
                if (oldmap[i][j].size != 0) { // if shark in the cell
                    for (int temp=0 ; temp<oldmap[i][j].speed ; temp++){
                        switch (oldmap[i][j].dir){
                            case 1: // up
                                if (newi==0){
                                    oldmap[i][j].dir = 2;
                                    newi++;
                                } else newi--;
                                break;
                            case 2: // down
                                if (newi==R-1){
                                    oldmap[i][j].dir = 1;
                                    newi--;
                                } else newi++;
                                break;
                            case 3: // right
                                if (newj==C-1){
                                    oldmap[i][j].dir = 4;
                                    newj--;
                                } else newj++;
                                break;
                            case 4: // left
                                if (newj==0){
                                    oldmap[i][j].dir = 3;
                                    newj++;
                                } else newj--;
                                break;
                        }
                        // if (i==0 && j==4) cout<<oldmap[i][j].dir<<" "<<newj<<endl;
                    } // individual shark move finish
                    if (newmap[newi][newj].size < oldmap[i][j].size) {
                        // if new shark is bigger, overwrites
                        // or blank
                        newmap[newi][newj] = oldmap[i][j];
                    } 
                    else { // else(older is bigger), no record on new map
                        // cout<<"size "<<oldmap[i][j].size<<" eliminated"<<endl;
                    }
                }
            }
        }
        // cout<<"time "<<(man+1)<<endl;
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