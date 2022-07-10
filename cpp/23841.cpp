#include <iostream>

using namespace std;

char map[50][50];

int main(void){
    int n, m;
    cin>>n>>m;
    cin.ignore();
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
            if (j>=m/2){
                if (map[i][j] != '.'){
                    map[i][m-1-j] = map[i][j];
                }
                else {
                    map[i][j] = map[i][m-1-j];
                }
            }
        }
    }
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cout<<map[i][j];
        }
        cout<<"\n";
    }
    return 0;
}