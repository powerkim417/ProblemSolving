#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k;
int arr[50][50], arrcopy[50][50];
int r[6], c[6], s[6];

void rotate(int r, int c, int s){
    queue<int> q;
    for (int i=1 ; i<=s ; i++){
        // 돌리는 방향은 시계지만 시계 반대방향으로 큐를 채워야 다시 넣기 쉬움
        // 좌상 - 좌하
        for (int j=r-i ; j<r+i ; j++){
            q.push(arrcopy[j][c-i]);
        }
        // 좌하 - 우하
        for (int j=c-i ; j<c+i ; j++){
            q.push(arrcopy[r+i][j]);
        }
        // 우하 - 우상
        for (int j=r+i ; j>r-i ; j--){
            q.push(arrcopy[j][c+i]);
        }
        // 우상 - 좌상
        for (int j=c+i ; j>c-i ; j--){
            q.push(arrcopy[r-i][j]);
        }
        q.push(q.front());
        q.pop();
        // 이러면 arr[r-i][c-1]에 들어가야 할 값이 front에 맞춰지고,
        // 반시계 방향으로 큐를 채우면 된다.
        
        // 좌상 - 좌하
        for (int j=r-i ; j<r+i ; j++){
            arrcopy[j][c-i] = q.front();
            q.pop();
        }
        // 좌하 - 우하
        for (int j=c-i ; j<c+i ; j++){
            arrcopy[r+i][j] = q.front();
            q.pop();
        }
        // 우하 - 우상
        for (int j=r+i ; j>r-i ; j--){
            arrcopy[j][c+i] = q.front();
            q.pop();
        }
        // 우상 - 좌상
        for (int j=c+i ; j>c-i ; j--){
            arrcopy[r-i][j] = q.front();
            q.pop();
        }
    }
    // for (int i=0 ; i<n ; i++){
    //     for (int j=0 ; j<m ; j++){
    //         cout<<arrcopy[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
}

int calc(){
    int ret = 50*100 + 1;
    for (int i=0 ; i<n ; i++){
        int temp = 0;
        for (int j=0 ; j<m ; j++){
            temp += arrcopy[i][j];
        }
        if (temp < ret) ret = temp;
    }
    return ret;
}

int main(void){
    cin>>n>>m>>k;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>arr[i][j];
        }
    }
    vector<int> choose;
    for (int i=0 ; i<k ; i++){
        choose.push_back(i);
        cin>>r[i]>>c[i]>>s[i];
        r[i]--;
        c[i]--;
    }
    int answer = 50*100 + 1;
    do {
        // for (int i=0 ; i<k ; i++) cout<<choose[i];
        // cout<<"\n";
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<m ; j++){
                arrcopy[i][j] = arr[i][j];
            }
        }
        for (int idx: choose){
            rotate(r[idx], c[idx], s[idx]);
        }
        int temp = calc();
        // cout<<temp<<"\n";
        if (answer > temp) answer = temp;
    } while (next_permutation(choose.begin(), choose.end()));
    cout<<answer;
    return 0;
}