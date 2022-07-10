#include <iostream>
#include <queue>

using namespace std;

int m,n;
queue<int> q;
bool visited[100][100];
char map[100][100];
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

bool inRange(int i, int j){
    if (i>=0 && i<n && j>=0 && j<m) return true;
    else return false;
}

int main(void){
    cin>>m>>n;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
        }
    }
    return 0;
}