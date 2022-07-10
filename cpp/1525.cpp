#include <iostream>
#include <queue>
#include <set>

using namespace std;

set<string> visited;
// 상 우 하 좌
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool isRange(int r, int c){
    return (r>=0 && r<3 && c>=0 && c<3);
}

struct state {
    string board;
    int time;
};

int blank(string board){
    int ret = -1;
    for (int i=0 ; i<9 ; i++){
        if (board[i] == '0'){
            ret = i;
            break;
        }
    }
    return ret;
}

string moved_board(string board, int bl, int nl){ // 공백 위치, 옮길숫자 위치 
    board[bl] = board[nl];
    board[nl] = '0';
    return board;
}

int bfs(string input){
    queue<state> q;
    q.push({input, 0});
    visited.insert(input);
    while (!q.empty()){
        state cur = q.front();
        // cout<<cur.board<<" "<<cur.time<<"\n";
        q.pop();
        if (cur.board == "123456780") return cur.time;

        int blank_loc = blank(cur.board);
        for (int d=0 ; d<4 ; d++){
            int nr = blank_loc/3 + dr[d];
            int nc = blank_loc%3 + dc[d];
            if (!isRange(nr, nc)) continue;
            int new_loc = nr*3 + nc;
            string next_board = moved_board(cur.board, blank_loc, new_loc);
            if (visited.find(next_board) == visited.end()){
                visited.insert(next_board);
                q.push({next_board, cur.time+1});
            }
        }
    }
    return -1;
}

/* BFS이지만 좀 특별한 트릭이 필요
3*3 보드판을 방문 처리할 트릭
1. 보드판이 아닌 123456780과 같은 숫자로 관리
2. set이나 map 이용해서 방문 처리
(메모리 제한 32MB라서 visited[100 000 000 0] 으로 하면 안됨)
(보드판의 경우의 수는 9! = 362880 이므로 저보다 더 효율적으로 저장해야 함)
*/
int main(void){
    string input = "";
    char temp;
    for (int i=0 ; i<9 ; i++){
        cin>>temp;
        input += temp;
    }
    cout<<bfs(input);
    return 0;
}