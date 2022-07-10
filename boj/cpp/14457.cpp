#include <iostream>

using namespace std;

// 한번에 뒤집는 범위: (0,0)~(r,c) 범위. 즉 (0,0)은 고정
/* 전부 0으로 만들어야 함.
flip(r,c)는 최대 1번까지가 최단시간 이므로
(n,n)부터 (0,0)까지 브루트포스로 순회하는 것을 기본으로 하면
(r,c)의 차례가 왔을 때가 map[r][c]를 뒤집을 수 있는 마지막 기회다.
이 때 1이면 뒤집고, 0이면 그대로 두고 넘기면 된다.
그러면 (n,n)~(r,c)까지는 다 0인 상태로 유지되고, 그렇게 (0,0)까지 확인해보면 된다.
*/

int n;
bool map[10][10];
int remain = 0;

void flip(int r, int c){
    for (int i=0 ; i<=r ; i++){
        for (int j=0 ; j<=c ; j++){
            map[i][j] = !map[i][j];
            // 0이 된 경우 -1
            // 1이 된 경우 +1
            remain += (map[i][j])?1:-1;
        }
    }
}

int main(void){
    cin>>n;
    char temp;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>temp;
            if (temp=='0') map[i][j] = false;
            else{
                map[i][j] = true;
                remain++;
            }
        }
    }
    int cnt = 0;
    for (int i=n-1 ; i>=0 ; i--){
        for (int j=n-1 ; j>=0 ; j--){
            if (map[i][j]) {
                // cout<<"Flip at ("<<i<<", "<<j<<"), ";
                cnt++;
                flip(i, j);
                // cout<<"remain: "<<remain<<"\n";
                if (remain==0){
                    cout<<cnt;
                    return 0;
                }
            }
        }
    }
    // 한번도 map[i][j]이 true가 아니었으면 일로 온다. 이 때는 cnt=0;
    cout<<"0";
    return 0;
}