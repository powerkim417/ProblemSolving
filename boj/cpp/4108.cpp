#include <iostream>

using namespace std;

int main(void){
    int r=-1,c=-1;
    while (r!=0 || c!=0){
        cin>>r>>c;
        char map[r][c];
        int cnt[r][c];
        for (int i=0 ; i<r ; i++){
            for (int j=0 ; j<c ; j++){
                cin>>map[i][j];
                cnt[i][j] = 0;
            }
        }
        for (int i=0 ; i<r ; i++){
            for (int j=0 ; j<c ; j++){
                if (map[i][j] == '*'){
                    for (int x=-1 ; x<=1 ; x++){
                        for (int y=-1 ; y<=1 ; y++){
                            if (x==0 && y==0) continue;
                            if (i+x>=0 && i+x<r
                            && j+y>=0 && j+y<c){
                                cnt[i+x][j+y]++;
                            }
                        }
                    }
                }
            }
        }
        for (int i=0 ; i<r ; i++){
            for (int j=0 ; j<c ; j++){
                if (map[i][j] == '*') cout<<"*";
                else cout<<cnt[i][j];
            }
            cout<<endl;
        }
    }
}