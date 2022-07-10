#include <iostream>
#include <map>
#include <queue>

using namespace std;

char cube[3][3][6] = {}; // 위 아래 앞 뒤 왼 오른
map<char, int> mp = {{'U', 0}, {'D', 1}, {'F', 2}, {'B', 3}, {'L', 4}, {'R', 5}};

void init(){
    for (int i=0 ; i<3 ; i++){
        for (int j=0 ; j<3 ; j++){
            cube[i][j][0] = 'w';
            cube[i][j][1] = 'y';

            cube[i][j][2] = 'r';
            cube[i][j][3] = 'o';

            cube[i][j][4] = 'g';
            cube[i][j][5] = 'b';
        }
    }
}

void rotate(int face, char cw){
    queue<char> q;
    for (int i=0 ; i<=2 ; i++){
        for (int j=0 ; j<=2 ; j++){
            q.push(cube[i][j][face]);
        }
    }
    if (cw=='+'){
        for (int j=2 ; j>=0 ; j--){
            for (int i=0 ; i<=2 ; i++){
                cube[i][j][face] = q.front();
                q.pop();
            }
        }
    }
    else {
        for (int j=0 ; j<=2 ; j++){
            for (int i=2 ; i>=0 ; i--){
                cube[i][j][face] = q.front();
                q.pop();
            }
        }
    }
}

void up_cw(){
    queue<char> q;
    for (int j=2 ; j>=0 ; j--) {q.push(cube[0][j][2]);} // 321
    for (int j=2 ; j>=0 ; j--) {q.push(cube[0][j][4]);} // 321
    for (int j=2 ; j>=0 ; j--) {q.push(cube[0][j][3]);} // 321
    for (int j=2 ; j>=0 ; j--) {q.push(cube[0][j][5]);} // 321

    for (int j=2 ; j>=0 ; j--) {cube[0][j][4] = q.front(); q.pop();}
    for (int j=2 ; j>=0 ; j--) {cube[0][j][3] = q.front(); q.pop();}
    for (int j=2 ; j>=0 ; j--) {cube[0][j][5] = q.front(); q.pop();}
    for (int j=2 ; j>=0 ; j--) {cube[0][j][2] = q.front(); q.pop();}
}

void down_cw(){
    queue<char> q;
    for (int j=0 ; j<=2 ; j++) {q.push(cube[2][j][2]);}
    for (int j=0 ; j<=2 ; j++) {q.push(cube[2][j][5]);}
    for (int j=0 ; j<=2 ; j++) {q.push(cube[2][j][3]);}
    for (int j=0 ; j<=2 ; j++) {q.push(cube[2][j][4]);}

    for (int j=0 ; j<=2 ; j++) {cube[2][j][5] = q.front(); q.pop();}
    for (int j=0 ; j<=2 ; j++) {cube[2][j][3] = q.front(); q.pop();}
    for (int j=0 ; j<=2 ; j++) {cube[2][j][4] = q.front(); q.pop();}
    for (int j=0 ; j<=2 ; j++) {cube[2][j][2] = q.front(); q.pop();}
}

void front_cw(){
    queue<char> q;
    for (int j=0 ; j<=2 ; j++) {q.push(cube[2][j][0]);}
    for (int i=0 ; i<=2 ; i++) {q.push(cube[i][0][5]);}
    for (int j=2 ; j>=0 ; j--) {q.push(cube[0][j][1]);}
    for (int i=2 ; i>=0 ; i--) {q.push(cube[i][2][4]);}

    for (int i=0 ; i<=2 ; i++) {cube[i][0][5] = q.front(); q.pop();}
    for (int j=2 ; j>=0 ; j--) {cube[0][j][1] = q.front(); q.pop();}
    for (int i=2 ; i>=0 ; i--) {cube[i][2][4] = q.front(); q.pop();}
    for (int j=0 ; j<=2 ; j++) {cube[2][j][0] = q.front(); q.pop();}
}

void back_cw(){
    queue<char> q;
    for (int j=2 ; j>=0 ; j--) {q.push(cube[0][j][0]);} // 321
    for (int i=0 ; i<=2 ; i++) {q.push(cube[i][0][4]);} // 147
    for (int j=0 ; j<=2 ; j++) {q.push(cube[2][j][1]);} // 789
    for (int i=2 ; i>=0 ; i--) {q.push(cube[i][2][5]);} // 963

    for (int i=0 ; i<=2 ; i++) {cube[i][0][4] = q.front(); q.pop();}
    for (int j=0 ; j<=2 ; j++) {cube[2][j][1] = q.front(); q.pop();}
    for (int i=2 ; i>=0 ; i--) {cube[i][2][5] = q.front(); q.pop();}
    for (int j=2 ; j>=0 ; j--) {cube[0][j][0] = q.front(); q.pop();}
}

void left_cw(){
    queue<char> q;
    for (int i=0 ; i<=2 ; i++) {q.push(cube[i][0][0]);} // 147
    for (int i=0 ; i<=2 ; i++) {q.push(cube[i][0][2]);} // 147
    for (int i=0 ; i<=2 ; i++) {q.push(cube[i][0][1]);} // 147
    for (int i=2 ; i>=0 ; i--) {q.push(cube[i][2][3]);} // 963

    for (int i=0 ; i<=2 ; i++) {cube[i][0][2] = q.front(); q.pop();}
    for (int i=0 ; i<=2 ; i++) {cube[i][0][1] = q.front(); q.pop();}
    for (int i=2 ; i>=0 ; i--) {cube[i][2][3] = q.front(); q.pop();}
    for (int i=0 ; i<=2 ; i++) {cube[i][0][0] = q.front(); q.pop();}
}

void right_cw(){
    queue<char> q;
    for (int i=2 ; i>=0 ; i--) {q.push(cube[i][2][0]);} // 963
    for (int i=0 ; i<=2 ; i++) {q.push(cube[i][0][3]);} // 147
    for (int i=2 ; i>=0 ; i--) {q.push(cube[i][2][1]);} // 963
    for (int i=2 ; i>=0 ; i--) {q.push(cube[i][2][2]);} // 963

    for (int i=0 ; i<=2 ; i++) {cube[i][0][3] = q.front(); q.pop();}
    for (int i=2 ; i>=0 ; i--) {cube[i][2][1] = q.front(); q.pop();}
    for (int i=2 ; i>=0 ; i--) {cube[i][2][2] = q.front(); q.pop();}
    for (int i=2 ; i>=0 ; i--) {cube[i][2][0] = q.front(); q.pop();}
}

void side_move(int face, int cwRotateCnt){
    // !!!!!!!!!!!! 반시계는 시계방향을 3번 돌리기
    while (cwRotateCnt--){
        switch (face){
            case 0: up_cw(); break;
            case 1: down_cw(); break;
            case 2: front_cw(); break;
            case 3: back_cw(); break;
            case 4: left_cw(); break;
            case 5: right_cw(); break;
        }
    }
}

void move(string cmd){
    int face = mp[cmd[0]];
    int cwRotateCnt = ((cmd[1]=='+') ? 1 : 3);

    rotate(face, cmd[1]);
    side_move(face, cwRotateCnt);
}

void print(int face){
    for (int i=0 ; i<3 ; i++){
        for (int j=0 ; j<3 ; j++){
            cout<<cube[i][j][face];
        }
        cout<<"\n";
    }
}

int main(void){
    int t;
    cin>>t;
    int n;
    string cmd;
    while (t--){
        init();
        cin>>n;
        while (n--){
            cin>>cmd;
            move(cmd);
        }
        print(0);
    }
}