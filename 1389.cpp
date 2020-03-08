#include <iostream>
#include <vector>
#define INF 99*98/2 // 99명과 각각 1 + 2 + .. + 98

using namespace std;

int n;
int dist[101][101] = {};

// 플로이드 와샬

int main(void){
    int m;
    cin>>n>>m;
    int a, b;
    for (int i=1 ; i<=n ; i++){
        for (int j=1 ; j<=n ; j++){
            dist[i][j] = INF;
        }
    }
    for (int i=0 ; i<m ; i++){
        cin>>a>>b;
        dist[a][b] = 1;
        dist[b][a] = 1;
    }
    for (int k=1 ; k<=n ; k++){
        for (int i=1 ; i<=n ; i++){
            for (int j=1 ; j<=n ; j++){
                if (dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    // for (int i=1 ; i<=n ; i++){
    //     for (int j=1 ; j<=n ; j++){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    int answer = 0;
    int min = INF;
    for (int i=1 ; i<=n ; i++){
        int temp = 0;
        for (int j=1 ; j<=n ; j++){
            temp += dist[i][j];
        }
        // cout<<temp<<"\n";
        if (temp < min){
            answer = i;
            min = temp;
        }
    }
    cout<<answer;
}