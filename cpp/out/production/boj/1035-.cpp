#include <iostream>

using namespace std;

char map[5][5];

/*
0...1
.....
.....
.....
2...3 의 경우
dist[4][4] 행렬을 만들 수 있다.
0 3 3

*/

int main(void){
    for (int i=0 ; i<5 ; i++){
        for (int j=0 ; j<5 ; j++){
            cin>>map[i][j];
        }
    }

}