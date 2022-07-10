#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<unsigned int> q;

// !!!!!!!!!!!
// 일반적으로 board[i][j]로 고정하면 4개 방향에 대해 for문의 구성이 달라져 코드를 4번씩 써야 하는데,
// 포문을 고정하고 board의 인덱스를 방향마다 다르게 변형하여 이렇게 그때그때 현 위치를 받도록 하면 코드 간결화 가능!! 
unsigned int& cur(int i, int j, char cmd, vector<vector<unsigned int>>& board){
    switch (cmd){
        case 'U':
        return board[j][i];
        case 'D':
        return board[7-j][i];
        case 'L':
        return board[i][j];
        case 'R':
        return board[i][7-j];
    }
}

void move(vector<vector<unsigned int>>& board, char cmd){
    for (int i=0 ; i<8 ; i++){
        for (int j=0 ; j<8 ; j++){
            if (cur(i, j, cmd, board)!=0) q.push(cur(i, j, cmd, board));
        }
        for (int j=0 ; j<8 ; j++){
            if (q.empty()) {
                cur(i, j, cmd, board) = 0;
                continue;
            }
            cur(i, j, cmd, board) = q.front(); q.pop();
            if (cur(i, j, cmd, board) == q.front()){
                cur(i, j, cmd, board) *= 2;
                q.pop();
            }
        }
    }
}

// 2^31까지 들어가야 하므로 unsigned int
int main(void){
    vector<vector<unsigned int>> board(8, vector<unsigned int>(8));
    for (int i=0 ; i<8 ; i++){
        for (int j=0 ; j<8 ; j++){
            cin>>board[i][j];
        }
    }
    char cmd; cin>>cmd;
    move(board, cmd);
    for (int i=0 ; i<8 ; i++){
        for (int j=0 ; j<8 ; j++){
            cout<<board[i][j]<< " ";
        }
        cout<<"\n";
    }
    return 0;
}