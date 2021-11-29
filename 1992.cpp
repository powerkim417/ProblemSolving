#include <iostream>

using namespace std;

char map[64][64];

void print(int r, int c, int n){
    for (int i=r ; i<r+n ; i++){
        for (int j=c ; j<c+n ; j++){
            if (map[i][j]!=map[r][c]){
                cout<<"(";
                print(r, c, n/2);
                print(r, c+n/2, n/2);
                print(r+n/2, c, n/2);
                print(r+n/2, c+n/2, n/2);
                cout<<")";
                return;
            }
        }
    }
    cout<<map[r][c];
    return;
}

int main(void){
    int n;
    cin>>n;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>map[i][j];
        }
    }
    print(0, 0, n);
    return 0;
}