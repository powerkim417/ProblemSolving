#include <iostream>

using namespace std;
int n,w;
int adj_r[3] = {0, 1, 0}; // 왼쪽, 위/아래, 오른쪽
int adj_c[3] = {-1, 0, 1};

int main(void){
    int T;
    for (int t=0 ; t<T ; t++){
        cin>>n>>w;
        int army[2][n];
        for (int i=0 ; i<2 ; i++){
            for (int j=0 ; j<n ; j++){
                cin>>army[i][j];
            }
        }
    }
}