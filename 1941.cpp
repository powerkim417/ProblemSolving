#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char map[5][5];
int answer = 0;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool princess[5][5];
bool visited[5][5];

bool isRange(int i, int j){
    return (i>=0 && i<5 && j>=0 && j<5);
}

void visit(int k, int& bit){
    bit |= (1<<k);
}

void unvisit(int k, int& bit){
    bit &= ~(1<<k);
}

bool check(int k, int& bit){
    return bit & (1<<k);
}

bool notLessThan4(int& bit){
    int cnt = 0;
    for (int i=0 ; i<25 ; i++){
        if (!check(i, bit)) continue;
        if (map[i/5][i%5]=='S') cnt++;
    }
    return (cnt>=4);
}

int group(int i, int j){
    int ret = 1;
    visited[i][j] = true;
    for (int d=0 ; d<4 ; d++){
        int ni = i+dr[d];
        int nj = j+dc[d];
        if (isRange(ni, nj) && princess[ni][nj] && !visited[ni][nj]) ret += group(ni, nj);
    }
    return ret;
}

void print(int& bit){
    for (int i=0 ; i<5 ; i++){
        for (int j=0 ; j<5 ; j++){
            if (check(i*5+j, bit)) cout<<"1 ";
            else cout<<"0 ";
        }
        cout<<"\n";
    }
    cout<<"--------\n";
}

bool connected(int& bit){
    for (int i=0 ; i<25 ; i++){
        visited[i/5][i%5] = false;
        princess[i/5][i%5] = check(i, bit);
    }
    for (int i=0 ; i<5 ; i++){
        for (int j=0 ; j<5 ; j++){
            if (princess[i][j]){
                int comp = group(i, j);
                if (comp==7) return true;
                else return false;
            }
        }
    }
}

// 2^24: int 범위
void dfs(int cur, int& bit, int cnt){
    visit(cur, bit);
    if (cnt==7){
        if (notLessThan4(bit) && connected(bit)) {
            // print(bit);
            answer++;
        }
        unvisit(cur, bit);
    }
    for (int next=cur+1 ; next<25 ; next++){ // 점점 뒷자리 학생을 방문하므로 방문여부 확인 필요 없음
        dfs(next, bit, cnt+1);
    }
    unvisit(cur, bit);
}

// 25C7(DFS) -> 이다솜파 4명 이상 -> 7명 서로 인접(제일 먼저 나오는 공주로 dfs 해서 나온 component의 값이 7인지 확인)
int main(void){
    for (int i=0 ; i<5 ; i++){
        for (int j=0 ; j<5 ; j++){
            cin>>map[i][j];
        }
    }
    int bit = 0;
    for (int i=0 ; i<=18 ; i++) dfs(i, bit, 1);

    cout<<answer;
    return 0;
}