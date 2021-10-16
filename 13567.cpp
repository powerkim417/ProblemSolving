#include <iostream>

using namespace std;

int m, n;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, -1, 0, 1};

int robot_r = 0;
int robot_c = 0;
int robot_d = 0;

bool isRange(int i, int j){
    return (i>=0 && i<=m && j>=0 && j<=m);
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>m>>n;
    string cmd;
    int d;
    for (int i=0 ; i<n ; i++){
        cin>>cmd>>d;
        if (cmd=="TURN"){
            if (d==0) robot_d = (robot_d+3)%4;
            else robot_d = (robot_d+1)%4;
        }
        else {
            int nr = robot_r+d*dr[robot_d];
            int nc = robot_c+d*dc[robot_d];
            if (!isRange(nr, nc)){
                cout<<"-1";
                return 0;
            }
            else {
                robot_r = nr;
                robot_c = nc;
            }
        }
    }
    cout<<robot_r<<" "<<robot_c;
    return 0;
}