#include <iostream>

using namespace std;

int abs(int x){
    if (x<0) return -x;
    else return x;
}

int numlen(int x){
    int ret = 1;
    while (x>=10){
        x /= 10;
        ret++;
    }
    return ret;
}

int main(void){
    int r1,c1,r2,c2;
    // 전부 -5000 이상 5000 이하
    cin>>r1>>c1>>r2>>c2;
    // (0,0) 시작 기준
    int curr = 0, curc = 0;
    // 우 상 좌좌 하하
    int dir = 0;
    int movr[4] = {0, -1, 0, 1};
    int movc[4] = {1, 0 , -1, 0};
    int len = 1;
    int map[r2-r1+1][c2-c1+1];
    for (int i=1 ; i<=10001*10001 ; ){
        for (int j=0 ; j<dir/2 + 1 ; j++){ // 해당 방향 반복 횟수
            if (curr >= r1 && curr <= r2
            && curc >= c1 && curc <= c2){
                map[curr-r1][curc-c1] = i;
                if (numlen(map[curr-r1][curc-c1]) > len)
                    len = numlen(map[curr-r1][curc-c1]);
            }
            i++;
            curr += movr[dir%4];
            curc += movc[dir%4];
        }
        dir = (dir+1);
    }
    for (int i=0 ; i<r2-r1+1 ; i++){
        for (int j=0 ; j<c2-c1+1 ; j++){
            int thislen = numlen(map[i][j]);
            for (int k=0 ; k<len-thislen ; k++){
                cout<<" ";
            }
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
}