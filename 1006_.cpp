#include <iostream>

using namespace std;
int n,w;
int adj_r[3] = {0, 1, 0}; // 왼쪽, 위/아래, 오른쪽
int adj_c[3] = {-1, 0, 1};

typedef pair<bool, bool> flag;
typedef pair<int, flag> state;
state dp[10001][4]; // [i번째 라인까지][0: 둘다 사용 안함, 1: 위가 먹힘, 2: 아래가 먹힘, 3: 둘다 먹힘]
// 이때까지 나온 2구역 덩어리의 갯수

// 덩어리를 최대한 많이 만들어야 함

state max_all(int idx){ // idx 번째 dp값들 중 최대와 그 flag값 반환
    state temp = dp[idx][0];
    for (int i=1 ; i<=3 ; i++){
        if (dp[idx][i].first < temp.first){
            temp = dp[idx][1];
        }
        else if (dp[idx][i].first == temp.first){
            
        }
    }
}

state max_up(int idx){ // idx 번째까지 왔을 때 위값을 사용했거나 안했거나 중 최대
    
}

state max_down(int idx){ // idx 번째까지 왔을 때 아래값을 사용했거나 안했거나 중 최대
    
}

int main(void){
    int T;
    cin>>T;
    for (int t=0 ; t<T ; t++){
        cin>>n>>w;
        int army[2][n];
        for (int i=0 ; i<2 ; i++){
            for (int j=0 ; j<n ; j++){
                cin>>army[i][j];
            }
        }
        // 전체 갯수에서 인접한 곳이 두개로 덮인 곳의 갯수를 뺀다.
        dp[0][0] = {0, {false, false}};
        dp[0][1] = {0, {false, false}};
        dp[0][2] = {0, {false, false}};
        dp[0][3] = (army[0][0] + army[1][0] <= w) ? (state){1, {true, true}} : (state){0, {false, false}};

        for (int i=1 ; i<=n ; i++){
            dp[i][0] = max_all(i-1);
            dp[i][1] = (army[0][i%n] + army[0][i-1] <= w) ? max(dp[i-1][0], dp[i-1][2]) + 1 : (state){0, {false, false}}; // 위에껄 포함하는게 가능하면 기존에서 + 1, 아니면 0(불가능한 경우)
            dp[i][2] = (army[1][i%n] + army[1][i-1] <= w) ? max(dp[i-1][0], dp[i-1][1]) + 1 : (state){0, {false, false}};
            state a = (army[0][i%n] + army[1][i%n] <= w) ? max(dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i-1][3]) + 1 : (state){0, {false, false}}; // i번째끼리 묶이는 경우
            state b = ((army[0][i%n] + army[0][i-1] <= w) && (army[1][i%n] + army[1][i-1] <=w)) ? dp[i-1][0] + 2 : (state){0, {false, false}}; // 둘다 각각 i-1번째랑 묶이는 경우
            dp[i][3] = (a.first ) ? a : b;
        }
        for (int i=0 ; i<=n ; i++){
            for (int j=0 ; j<4 ; j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        int sum = max(dp[n][0], dp[n][1], dp[n][2], dp[n][3]);
        cout<<(2*n-sum)<<"\n";
    }

}