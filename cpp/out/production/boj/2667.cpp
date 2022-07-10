#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r[4] = {-1, 0, 1, 0};
int c[4] = {0, 1, 0, -1};
int n;
char map[25][25];
bool visited[25][25];
int house;

bool inRange(int i, int j){
    if (i>=0 && i<n && j>=0 && j<n) return true;
    else return false;
}

void dfs(int i, int j){
    house++;
    visited[i][j] = true;
    for (int m=0 ; m<4 ; m++){
        int newi = i+r[m];
        int newj = j+c[m];
        if (inRange(newi, newj) && map[newi][newj] == '1' && !visited[newi][newj]){
            dfs(newi, newj);
        }
    }
}

int main(void){
    cin>>n;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>map[i][j];
            visited[i][j] = false;
        }
    }
    int danji = 0;
    vector<int> houses;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if(map[i][j] == '1' && !visited[i][j]){
                house = 0;
                dfs(i, j);
                houses.push_back(house);
                house = 0;
                danji++;
            }
        }
    }
    cout<<danji<<"\n";
    int houses_size = houses.size();
    sort(houses.begin(), houses.end());
    for (int i=0 ; i<houses_size ; i++){
        cout<<houses[i]<<"\n";
    }
}