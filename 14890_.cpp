#include <iostream>

using namespace std;

int main(void){
    int N,L;
    cin>>N>>L;
    int map[N][N], slope[N][N];
    for (int i=0 ; i<N ; i++){
        for (int j=0 ; j<N ; j++){
            cin>>map[i][j];
            slope[i][j] = 0;
        }
    }
    int ans = 2*N;
    for (int i=0 ; i<N ; i++){ // 가로 경로
        for (int j=0 ; j<=N-L ; j++){
        }
    }
    for (int j=0 ; j<N ; j++){ // 세로 경로
        for (int i=0 ; i<N-1 ; i++){
            
        }
    }
}