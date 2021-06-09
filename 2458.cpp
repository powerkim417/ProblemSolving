#include <iostream>

using namespace std;

/*
그래프로 그렸을 때
A에서 B로 가거나(A<B)
B에서 A로 가는 것(A>B)이 안될 경우
A와 B 사이의 대소관계를 모르는 것
플로이드 와샬 bool형으로 그래프 분석
*/

bool able[501][501] = {}; // i에서 j로 가는 것(i<j)

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    int a, b;
    for (int i=0 ; i<m ; i++){
        cin>>a>>b;
        able[a][b] = true;
    }
    for (int k=1 ; k<=n ; k++){
        for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=n ; j++){
                if (able[i][k] && able[k][j]) able[i][j] = true;
            }
        }
    }
    // for (int i=1 ; i<=n ; i++){
    //     for (int j=1 ; j<=n ; j++){
    //         cout<<able[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    int answer = 0;
    // 모든 j에 대해 able[i][j] 또는 able[j][i]일 경우에 answer++
    // (문제 조건 상 둘다 true이진 않을 것)
    bool flag;
    for (int i=1 ; i<=n ; i++){
        flag = true;
        for (int j=1 ; j<=n ; j++){
            if (i==j) continue;
            if (!able[i][j] && !able[j][i]) {
                flag = false;
                break;
            }
        }
        if (flag) answer++;
    }
    cout<<answer;
    return 0;
}