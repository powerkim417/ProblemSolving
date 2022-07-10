#include <iostream>

using namespace std;

int n;
bool map[3072][6143]; // 24*47 .. 3072
// 별찍기가 이미 넘어간 줄에 대해 다시 돌아가기 힘드니까
// 따로 맵을 그려서 거기에 표시하고 나중에 한꺼번에 출력!

int abs(int x){
    if (x<0) return -x;
    else return x;
}

void star(int loc, int size, int height){ // loc: x축 위치    if (size == 3){
    if (size == 3){    
        map[height][loc] = true;

        map[height+1][loc-1] = true;
        map[height+1][loc+1] = true;

        map[height+2][loc-2] = true;
        map[height+2][loc-1] = true;
        map[height+2][loc] = true;
        map[height+2][loc+1] = true;
        map[height+2][loc+2] = true;
    }
    else {
        star(loc, size/2, height);
        star(loc-size/2, size/2, height+size/2);
        star(loc+size/2, size/2, height+size/2);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin>>n;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<2*n-1 ; j++){
            map[i][j] = false;
        }
    }
    star(n-1, n, 0);
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<2*n-1 ; j++){
            if (map[i][j]) cout<<"*";
            else cout<<" ";
        }
        cout<<"\n";
    }
}