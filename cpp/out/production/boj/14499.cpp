#include <cstdio>

using namespace std;

int main(void){
    int n,m,x,y,k;
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    int map[n][m], cmd;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            scanf("%d", &map[i][j]);
        }
    }
    int dice[6] = {0, 0, 0, 0, 0, 0};
    /* 1 
      302   0이 윗면, 5가 아랫면. 2는 오른쪽
       4
       5 */
    int temp;
    for (int i=0 ; i<k ; i++) {
        scanf("%d", &cmd);
        switch (cmd){
            case 1: // east
            if (y+1<m){
                y++;
                temp = dice[2];
                dice[2] = dice[0]; // right
                dice[0] = dice[3]; // up
                dice[3] = dice[5]; // left
                if (map[x][y] == 0) { // down
                    map[x][y] = temp; // dice -> map
                    dice[5] = temp;
                }
                else {
                    dice[5] = map[x][y]; // map -> dice
                    map[x][y] = 0;
                }
                printf("%d\n",dice[0]);
            }
            break;
            case 2: // west
            if (y-1>=0){
                y--;
                temp = dice[3];
                dice[3] = dice[0]; // left
                dice[0] = dice[2]; // up
                dice[2] = dice[5]; // right
                if (map[x][y] == 0) { // down
                    map[x][y] = temp; // dice -> map
                    dice[5] = temp;
                }
                else {
                    dice[5] = map[x][y]; // map -> dice
                    map[x][y] = 0;
                }
                printf("%d\n",dice[0]);
            }
            break;
            case 3: // north
            if (x-1>=0){
                x--;
                temp = dice[4];
                dice[4] = dice[0]; // back
                dice[0] = dice[1]; // up
                dice[1] = dice[5]; // front
                if (map[x][y] == 0) { // down
                    map[x][y] = temp; // dice -> map
                    dice[5] = temp;
                }
                else {
                    dice[5] = map[x][y]; // map -> dice
                    map[x][y] = 0;
                }
                printf("%d\n",dice[0]);
            }
            break;
            case 4: // south
            if (x+1<n){
                x++;
                temp = dice[1];
                dice[1] = dice[0]; // front
                dice[0] = dice[4]; // up
                dice[4] = dice[5]; // back
                if (map[x][y] == 0) { // down
                    map[x][y] = temp; // dice -> map
                    dice[5] = temp;
                }
                else {
                    dice[5] = map[x][y]; // map -> dice
                    map[x][y] = 0;
                }
                printf("%d\n",dice[0]);
            }
            break;
        }
    }
}