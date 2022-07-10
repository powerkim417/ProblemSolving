#include <iostream>

using namespace std;

int main(void){
    bool map[100][100];
    for (int i=0 ; i<100 ; i++){
        for (int j=0 ; j<100 ; j++){
            map[i][j] = false;
        }
    }
    for (int t=0 ; t<4 ; t++){
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        for (int i=x1 ; i<x2 ; i++){
            for (int j=y1 ; j<y2 ; j++){
                map[i][j] = true;
            }
        }
    }
    int cnt = 0;
    for (int i=0 ; i<100 ; i++){
        for (int j=0 ; j<100 ; j++){
            if (map[i][j]) cnt++;
        }
    }
    cout<<cnt;
}