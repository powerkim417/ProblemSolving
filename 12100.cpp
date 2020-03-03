#include <iostream>
#include <stack>
#include <cstdlib>

using namespace std;

int n;
int MAP[20][20];
int map[20][20];
int answer = 0;

int max(int map[20][20]){
    int ret = 0;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (ret < map[i][j]) ret = map[i][j];
        }
    }
    return ret;
}

void brute_force(int m[20][20], int cnt){ // m은 cnt번 이동한 결과물
    if (cnt==5){
        // cout<<"---------\n";
        // for (int i=0 ; i<n ; i++){
        //     for (int j=0 ; j<n ; j++){
        //         cout<<m[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        if (answer < max(m)) {
            // cout<<"---------\n";
            // for (int i=0 ; i<n ; i++){
            //     for (int j=0 ; j<n ; j++){
            //         cout<<m[i][j]<<" ";
            //     }
            //     cout<<"\n";
            // }
            answer = max(m);
        }
        return;
    }
    int map[20][20];
    for (int d=0 ; d<4 ; d++){
        // 각각 0도 90도 180도 270도 회전된 판이 map에 들어가는 느낌
        // 90도: (i, j) -> (j, n-1-i)
        // 180도: (i, j) -> (n-1-i, n-1-j)
        // 270도: (i, j) -> (n-1-j, i)
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                switch (d){
                    case 0:
                    map[i][j] = m[i][j];
                    break;
                    case 1:
                    map[i][j] = m[j][n-1-i];
                    break;
                    case 2:
                    map[i][j] = m[n-1-i][n-1-j];
                    break;
                    case 3:
                    map[i][j] = m[n-1-j][i];
                    break;
                }
            }
        }
        // 이동 작업
        // 이동 시 각 n개의 스택에 숫자들이 눌려 들어가는거라고 생각하고,
        // 각 다른 방향은 회전된 판으로 고려해서 각각 4가지 판에 대해 일관적으로 위로 올리는 작업만 실시했다고 생각.
        stack<int> s[20];
        // cout<<"--------\n";
        // for (int i=0 ; i<n ; i++){
        //     for (int j=0 ; j<n ; j++){
        //         cout<<map[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        bool flag; // 블럭 합체가 일어난 경우 true. 다음에 바로 합체되지 않게 하려고
        for (int j=0 ; j<n ; j++){
            flag = false;
            for (int i=0 ; i<n ; i++){
                // if (i==1 && j==2) cout<<flag;
                // if (i==2 && j==2) cout<<flag;
                if (map[i][j]==0) {
                    continue;
                }
                if (s[j].empty() || s[j].top() != map[i][j]){ // 그냥 쌓는 경우
                    s[j].push(map[i][j]);
                    flag = false;
                }
                else { // 가장 위랑 현재 블럭이랑 같은 경우
                    if (flag) { // 대상이 이미 합체된 블럭이면 그냥 푸시
                        s[j].push(map[i][j]); 
                        flag = false;
                    }
                    else { // 대상이 합체된 블럭이 아니라면 합체!
                        s[j].pop();
                        s[j].push(2*map[i][j]);
                        flag = true;
                    }
                }
            }
        }
        for (int j=0 ; j<n ; j++){
            int zero = n - s[j].size();
            while (zero--) s[j].push(0);
        }
        for (int i=n-1 ; i>=0 ; i--){
            for (int j=0 ; j<n ; j++){
                map[i][j] = s[j].top();
                s[j].pop();
            }
        }
        // cout<<"--------\n";
        // for (int i=0 ; i<n ; i++){
        //     for (int j=0 ; j<n ; j++){
        //         cout<<map[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // exit(0);
        brute_force(map, cnt+1);
    }
    // exit(0);
}

int main(void){
    cin>>n;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>MAP[i][j];
        }
    }
    brute_force(MAP, 0);
    cout<<answer;
    return 0;
}