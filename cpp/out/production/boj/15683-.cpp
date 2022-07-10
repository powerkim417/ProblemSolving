#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int N,M;
    cin>>N>>M;
    char map[N][M];
    for (int i=0 ; i<N ; i++){
        for (int j=0 ; j<M ; j++){
            cin>>map[i][j];
        }
    }
}