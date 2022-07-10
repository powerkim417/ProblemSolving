#include <iostream>

using namespace std;

// i가 j보다 무겁다(a에서 b로 갈 수 있다?)
bool able[101][101];

// 플로이드 와샬
/*
모순인 예는 주어지지 않음.
양쪽 말고 한쪽 간선으로만 하고,
마지막에 !able[i][j] && !able[j][i] 와 같이 양쪽으로 둘다 못가는 경우에 cnt++ 하면 된다.
*/

int main(void){
    int n, m;
    cin>>n>>m;
    int a, b;
    for (int i=1 ; i<=n ; i++) able[i][i] = true;
    for (int i=0 ; i<m ; i++){
        cin>>a>>b;
        able[a][b] = true;
    }
    for (int k=1 ; k<=n ; k++){
        for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=n ; j++){
                if (able[i][k] && able[k][j]){
                    able[i][j] = true;
                }
            }
        }
    }
    for (int i=1 ; i<=n ; i++){
        int cnt = 0;
        for (int j=1 ; j<=n ; j++){
            if (!able[i][j] && !able[j][i]) cnt++;
        }
        cout<<cnt<<"\n";
    }
}