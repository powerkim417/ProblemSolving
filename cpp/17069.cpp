#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int map[32][32];
long long int hor[32][32];
long long int diag[32][32];
long long int down[32][32];
bool flag = true;
int first_wall = -1;


void dp(int i, int j){
    if (j==0) {
        hor[i][j] = 0;
        diag[i][j] = 0;
        down[i][j] = 0;
    }
    else if (i==0){
        if (first_wall == -1) {
            hor[i][j] = 1;
            diag[i][j] = 0;
            down[i][j] = 0;
        }
        else {
            if (j < first_wall) {
                hor[i][j] = 1;
                diag[i][j] = 0;
                down[i][j] = 0;
            }
            else {
                hor[i][j] = 0;
                diag[i][j] = 0;
                down[i][j] = 0;
            }
        }
    }
    else { // normal case
        if (map[i][j] == 1){
            hor[i][j] = 0;
            diag[i][j] = 0;
            down[i][j] = 0;
        }
        else {
            hor[i][j] = (1-map[i][j-1])*(hor[i][j-1] + diag[i][j-1]);
            diag[i][j] = (1-map[i-1][j-1])*(1-map[i-1][j])*(1-map[i][j-1])*(hor[i-1][j-1] + diag[i-1][j-1] + down[i-1][j-1]);
            down[i][j] = (1-map[i-1][j])*(diag[i-1][j] + down[i-1][j]);
        }
    }
}

int main(void){
    int N;
    cin>>N;
    for (int i=0 ; i<N ; i++){
        for (int j=0 ; j<N ; j++){
            cin>>map[i][j];
            if (flag && i==0 && map[i][j]) {
                first_wall = j;
                flag = false;
            }
        }
    }
    for (int i=0 ; i<N ; i++){
        for (int j=0 ; j<N ; j++){
            dp(i,j);
        }
    }
    
    cout<<(hor[N-1][N-1]+diag[N-1][N-1]+down[N-1][N-1]);

    // for (int i=0 ; i<N ; i++){
    //     for (int j=0 ; j<N ; j++){
    //         cout<<hor[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"---"<<endl;
    // for (int i=0 ; i<N ; i++){
    //     for (int j=0 ; j<N ; j++){
    //         cout<<diag[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"---"<<endl;
    // for (int i=0 ; i<N ; i++){
    //     for (int j=0 ; j<N ; j++){
    //         cout<<down[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
}