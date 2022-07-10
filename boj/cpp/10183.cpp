#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct point {
    int r;
    int c;
};

string usemap[15];

int main(void){
    string map[15];
    string usemap[15];
    for (int i=0 ; i<15 ; i++){
        getline(cin, map[i]);
    }
    int n;
    cin>>n;
    getchar();
    string cmd[n];
    // front가 끝, back가 머리
    // (새로운 위치가 back으로 들어오고
    // 없어지는 위치는 front로 나가기 때문)
    for (int t=0 ; t<n ; t++){
        getline(cin, cmd[t]);
    }
    for (int t=0 ; t<n ; t++){
        for (int num=0 ; num<20 ; num++){
            if (cmd[t][num] == 'O'){
                if (num==0) cmd[t][num] = 'R';
                else cmd[t][num] = cmd[t][num-1];
                /* O 커맨드에 대한 처리.
                UOOO 는 UUUU 와 같으므로
                O가 존재할 경우 앞의 커맨드로 치환하고,
                맨 앞 커맨드가 O일 경우 문제 조건에 따라
                R로 바꾼다. */
            }
        }
    }
    for (int t=0 ; t<n ; t++){
        // 각 테스트케이스
        int pellet = 0;
        // map 복사, snake 초기화
        queue<point> snake;
        for (int i=0 ; i<15 ; i++){
            usemap[i] = map[i];
        }
        for (int i=0 ; i<15 ; i++){
            for (int j=0 ; j<15 ; j++){
                if (usemap[i][j] == 'X'){
                    snake.push((point){i, j});
                    /* 가로 형태로 주어지고,
                    오른쪽부터 움직이므로
                    왼쪽부터 queue에 넣으면 됨 */
                    usemap[i][j] = ' ';
                }
            }
        }
        for (int num=0 ; num<20 ; num++){
            point cur = snake.back(); // 뱀 머리
            switch (cmd[t][num]){
                case 'U':
                    cur.r--;
                    break;
                case 'D':
                    cur.r++;
                    break;
                case 'L':
                    cur.c--;
                    break;
                case 'R':
                    cur.c++;
                    break;
            }
            // 지도 벗어나면 게임 끝(pellet = -1로 표시)
            if (cur.r<0 || cur.r>=15
            || cur.c<0 || cur.c>=15){
                pellet = -1;
                snake.pop(); // 이동하긴 한것이므로 이전 꼬리는 사라짐
                break;
            }
            snake.push(cur);
            if (usemap[cur.r][cur.c] == 'F'){
                pellet++;
                usemap[cur.r][cur.c] = ' ';
            }
            else {
                snake.pop();
            }
        }
        if (pellet == -1) cout<<"GAME OVER"<<endl;
        else cout<<pellet<<" pellets"<<endl;
        while (!snake.empty()){
            // map에 snake 위치 표시
            point cur = snake.front();
            usemap[cur.r][cur.c] = 'X';
            snake.pop();
        }
        for (int i=0 ; i<15 ; i++){
            for (int j=0 ; j<15 ; j++){
                cout<<usemap[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
    }
}