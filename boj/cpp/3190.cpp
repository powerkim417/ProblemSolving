#include <iostream>
#include <queue>

using namespace std;

int n, k, l;
queue<pair<int, int>> q_snake; // rear로 새 좌표가 들어오고, front로 기존 좌표가 지워짐
bool apple[100][100] = {};
bool snake[100][100] = {};
int dr[4] = {0, 1, 0, -1}; // 우 하 좌 상
int dc[4] = {1, 0, -1, 0};
pair<int, int> cur = {0,0}, del;
int d = 0; // 오른쪽 시작
int time = 0;

void move(){
    cur.first += dr[d];
    cur.second += dc[d];
}

bool isRange(pair<int, int> cur){
    int i = cur.first;
    int j = cur.second;
    return (i>=0 && i<n && j>=0 && j<n);
}

bool work(){
    // cout<<time<<": ("<<cur.first<<", "<<cur.second<<")\n";
    time++;
    move();
    if (!isRange(cur) || snake[cur.first][cur.second]){
        // 벗어났거나 현재 뱀의 몸통이 있는 위치로 이동한 경우
        return true;
    }
    q_snake.push(cur);
    snake[cur.first][cur.second] = true;
    if (!apple[cur.first][cur.second]) { // 이동한 위치에 사과가 없으면 기존 흔적 삭제
        del = q_snake.front();
        snake[del.first][del.second] = false;
        // cout<<"("<<del.first<<", "<<del.second<<") is now false\n";
        q_snake.pop();
    }
    apple[cur.first][cur.second] = false; // 이 자리의 사과는 먹었으니 없앤다.
    return false;
}

int main(void){
    cin>>n>>k;
    int a,b;
    for (int i=0 ; i<k ; i++){
        cin>>a>>b;
        apple[a-1][b-1] = true;
    }
    cin>>l;
    int x;
    char c;
    q_snake.push(cur);
    snake[cur.first][cur.second] = true;
    for (int i=0 ; i<l ; i++){
        cin>>x>>c;
        while (time<x){
            if (work()){
                cout<<time;
                return 0;
            }
        }
        if (c=='D') d = (d+1)%4;
        else d = (d+3)%4;
    }
    // 방향 전환 이후는 
    while (1){
        if (work()){
            cout<<time;
            return 0;
        }
    }
}