#include <iostream>

using namespace std;

int n;

/*
1: 1*1

2: 7*5(2-2-4-4-6-4), (4,2) 시작. 길이 6까지 하되, (0, 4) 넘어가면 break;
3: 11*9(2-2-4-4-6-6-8-8-10-8), (6,4) 시작. 길이 10까지 하되, (0, 8) 넘어가면 break;
4: 15*13

n: (4n-1)*(4n-3), (2n, n) 시작

100: 399*397
*/
bool map[399][397] = {};
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    if (n==1) {
        cout<<"*";
        return 0;
    }
    int r=2*n, c=2*n-2;
    int len = 2; 
    int dir = 0;
    map[r][c] = true;
    while (len <= 4*n-2){
        for (int i=0 ; i<len ; i++){
            r += dr[dir];
            c += dc[dir];
            if (c>=4*n-3) break; // 맵의 우상단을 넘어갈 경우 끝
            map[r][c] = true;
        }
        dir = (dir+1)%4;
        if (dir%2 == 0) len += 2;
    }
    for (int i=0 ; i<4*n-1 ; i++){
        for (int j=0 ; j<4*n-3 ; j++){
            if (i==1) cout<<((map[i][j])?"*":""); // 두번째 줄 공백 없음..
            else cout<<((map[i][j])?"*":" ");
        }
        cout<<"\n";
    }
    return 0;
}