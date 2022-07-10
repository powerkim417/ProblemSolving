#include <iostream>
#include <vector>

using namespace std;

bool visited[4][4] = {};

// 16비트, i*M + j번째 칸이 가로(0)로 이어져 있는지, 세로(1)로 이어져 있는지 기록

bool dir(int bit, int k){
    return bit & (1<<k);
}

// 비트마스킹
/*
우선, 비트마스킹이 모든 케이스를 담을 수 있다는 것을 증명해야 하는데
우선 [a(0) b(0)][c(0) d(0)]과 같이 나뉘는 경우는 [a(0) b(0) c(0) d(0)]과 구분이 되지 않음!
그러나 10a + b + 10c + d 는 항상 1000a + 100b + 10c + d 보다 작으므로 (990a + 99b >= 0)
전자와 같이 길게 이을 수 있는데 나뉘는 케이스는 고려하지 않아도 됨
*/
int main(void){
    int n, m;
    cin>>n>>m;
    int map[4][4];
    char c;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>c;
            map[i][j] = c-'0';
        }
    }
    int answer = -1;
    for (int bit=0 ; bit<(1<<16) ; bit++){
        int temp = 0, cur;
        // 가로
        for (int i=0 ; i<n ; i++){
            cur = 0;
            for (int j=0 ; j<m ; j++){
                int k = i*m+j;
                if (dir(bit, k)==0){
                    cur *= 10;
                    cur += map[i][j];
                }
                else {
                    temp += cur;
                    cur = 0;
                }
            }
            temp += cur;
        }
        // 세로
        for (int j=0 ; j<m ; j++){
            cur = 0;
            for (int i=0 ; i<n ; i++){
                int k = i*m+j;
                if (dir(bit, k)==1){
                    cur *= 10;
                    cur += map[i][j];
                }
                else {
                    temp += cur;
                    cur = 0;
                }
            }
            temp += cur;
        }
        if (answer < temp) answer = temp;
    }
    cout<<answer;
    return 0;
}