#include <iostream>

using namespace std;

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m,b;
    cin>>n>>m>>b;
    int h[500][500];
    int total_block = b;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>h[i][j];
            total_block += h[i][j];
        }
    }
    // 파는데 2초, 넣는데 1초

    // 가능한 높이는 0 ~ total_block/(m*n) 사이의 정수
    // 그리고 0,0 ~ n-1,m-1 순으로 채울 때 중간에 인벤토리가 빌 수도 있는데,
    // 가능한 높이 내에서만 시뮬레이션을 돌리므로
    // 깎을 곳을 먼저 파서 인벤토리를 채운 후 빈 곳을 채운다고 생각해도 됨

    /*
    제출 여러번 하면서 코멘트..
    이 코드가 잘못된 줄 알고 계속 고쳐서 냈는데
    근본적인 문제는 ans_time을 256가 아닌 64를 곱하는 바람에 INF의 역할을 못해줌
    이와 별개로 다른 코드들은 height=0~256 전체를 보는 대신
    각 경우가 블록이 부족하진 않은지에 대한 추가 로직이 들어가는데,
    내 코드는 "블록이 부족하지 않은 높이의 최대(total_block/(m*n))를 설정"해줌으로서 
    추가 로직이 들어가지 않아 더 잘 짠 코드인 셈

    */
    int ans_time = 500*500*256*2 + 1;
    int ans_height = -1;
    for (int height=0 ; height<=total_block/(m*n) ; height++){
        int cur_time = 0;
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                if (h[i][j]>height) cur_time += 2*(h[i][j]-height);
                else if (h[i][j]<height) cur_time += (height-h[i][j]);
            }
        }
        if (cur_time <= ans_time){ // 같은 최소시간의 경우 더 높은 땅높이 채택
            ans_time = cur_time;
            ans_height = height;
        }
    }
    cout<<ans_time<<" "<<ans_height;
    return 0;
}