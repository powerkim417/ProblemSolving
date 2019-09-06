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
    for (int i=0 ; i<N ; i++){ // 가로 경로
        for (int j=1 ; j<N ; j++){
            if (map[i][j]-map[i][j-1] == 0) continue;
            else if (map[i][j]-map[i][j-1] == 1) { // /

            }
        }
    }
    for (int j=0 ; j<N ; j++){ // 세로 경로
        for (int i=1 ; i<N ; i++){
            
        }
    }
}