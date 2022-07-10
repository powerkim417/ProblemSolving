#include <iostream>

using namespace std;

int map[128][128];

void cut(int r, int c, int n, int& white, int& blue){
    for (int i=r ; i<r+n ; i++){
        for (int j=c ; j<c+n ; j++){
            if (map[i][j]!=map[r][c]){
                cut(r, c, n/2, white, blue);
                cut(r, c+n/2, n/2, white, blue);
                cut(r+n/2, c, n/2, white, blue);
                cut(r+n/2, c+n/2, n/2, white, blue);
                return;
            }
        }
    }
    if (map[r][c]) blue++;
    else white++;
    return;
}

int main(void){
    int n; cin>>n;
    int white = 0, blue = 0;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>map[i][j];
        }
    }
    cut(0, 0, n, white, blue);
    cout<<white<<"\n"<<blue;
    return 0;
}