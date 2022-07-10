#include <iostream>
#include <queue>

using namespace std;

int visited[300][300];

int dr[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dc[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

int l;

bool inRange(int i, int j){
    if (i>=0 && i<l && j>=0 && j<l) return true;
    return false;
}

int main(void){
    int T;
    cin>>T;
    for (int t=0 ; t<T ; t++){
        cin>>l;
        for (int i=0 ; i<l ; i++){
            for (int j=0 ; j<l ; j++){
                visited[i][j] = false;
            }
        }
        int sr, sc, er, ec;
        cin>>sr>>sc>>er>>ec;
        queue<pair<int, int>> q;
        q.push({sr, sc});
        visited[sr][sc] = true;
        int ni,nj;
        int cnt = 0;
        bool found = false;
        while (!q.empty()){
            int q_size = q.size();
            for (int i=0 ; i<q_size ; i++){    
                pair<int, int> cur = q.front();
                q.pop();
                if (cur.first == er && cur.second == ec){
                    found = true;
                    break;
                }
                for (int d=0 ; d<8 ;d++){
                    ni = cur.first + dr[d];
                    nj = cur.second + dc[d];
                    if (inRange(ni, nj) && !visited[ni][nj]){
                        visited[ni][nj] = true;
                        q.push({ni, nj});
                    }
                }
            }
            if (found) break;
            cnt++;
        }
        cout<<cnt<<"\n";
    }
}