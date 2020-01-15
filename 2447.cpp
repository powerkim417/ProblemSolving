#include <iostream>

using namespace std;

int n;
const int MAX = 6561;
bool map[MAX][MAX];

// 재귀 별찍기: 배열을 만들어서 중간중간 수정하고 최종에 한번에 출력

// (r,c): 실행의 중심점 좌표
void star(int r, int c, int size){
    // cout<<"("<<r<<", "<<c<<", "<<size<<")\n";
    if (size == 3){
        for (int i=-1 ; i<=1 ; i++){
            for (int j=-1 ; j<=1 ; j++){
                map[r+i][c+j] = true;
            }
        }
        map[r][c] = false;
    }
    else {
        star(r-size/3, c-size/3, size/3);
        star(r-size/3, c, size/3);
        star(r-size/3, c+size/3, size/3);

        star(r, c-size/3, size/3);
        star(r, c+size/3, size/3);

        star(r+size/3, c-size/3, size/3);
        star(r+size/3, c, size/3);
        star(r+size/3, c+size/3, size/3);
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin>>n;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            map[i][j] = false;
        }
    }
    
    star(n/2, n/2, n);

    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cout<<((map[i][j]) ? "*" : " ");
        }
        cout<<"\n";
    }
}