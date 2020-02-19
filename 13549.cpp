#include <iostream>
#include <queue>

using namespace std;

int n, k;
queue<int> q;
bool visited[100001] = {};

// 1초 뒤에 순간이동이 아닌 0초 뒤에 순간이동하는 위치를 bfs로 담는것이 포인트인 문제!!!

int bfs(){
    int time = 0;
    for (int i=n ; i<=100000 ; i*=2){ // 시작점 기준 2의 거듭제곱배 위치는 모두 0초만에 커버이므로 push
        // cout<<i<<"\n";
        q.push(i);
        if (i==k){
            return time;
        }
        visited[i] = true;
        if (i==0) break; // 0일 때는 무한루프..
        if (i>k) break; // k를 한번 넘었으면 그 이상의 값은 비효율적이므로 자름
    }
    while (!q.empty()){
        int q_size = q.size();
        // cout<<"-----------\n";
        while (q_size--){
            int cur = q.front();
            // cout<<"cur: "<<cur<<"\n";
            q.pop();
            if (cur-1>=0){
                if (!visited[cur-1]){ // 여기서 안해주면 또 0 무한루프..
                    for (int i=cur-1 ; i<=100000 ; i*=2){ // 다음 위치와, 다음 위치의 순간이동 위치들 모두 push
                        // cout<<i<<"\n";
                        if (i==k){
                            return time+1;
                        }
                        visited[i] = true;
                        q.push(i);
                        if (i==0) break; // 0일 때는 무한루프..
                        if (i>k) break; // k를 한번 넘었으면 그 이상의 값은 비효율적이므로 자름
                    }
                }
            }
            if (cur+1<=100000){
                if (!visited[cur+1]) {
                    for (int i=cur+1 ; i<=100000 ; i*=2){ // 다음 위치와, 다음 위치의 순간이동 위치들 모두 push
                        // cout<<i<<"\n";
                        if (i==k){
                            return time+1;
                        }
                        visited[i] = true;
                        q.push(i);
                        if (i==0) break; // 0일 때는 무한루프..
                        if (i>k) break; // k를 한번 넘었으면 그 이상의 값은 비효율적이므로 자름
                    }
                }
            }
        }
        time++;
    }
}

int main(void){
    cin>>n>>k;
    cout<<bfs();
}