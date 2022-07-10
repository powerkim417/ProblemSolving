#include <iostream>
#include <queue>

using namespace std;

bool visited[100000];

int B(int x){ // 50000 이상부터는 불가능
    if (x==0) return 0;
    x *= 2;
    int temp = x;
    int sub = 1;
    while (temp>=10){
        temp /= 10;
        sub *= 10;
    }
    x -= sub;
    return x;
}   

int main(void){
    int N, T, G;
    cin>>N>>T>>G;
    queue<int> q;
    q.push(N);
    visited[N] = true;
    int answer = 0;
    while (!q.empty()){
        if (answer > T) {
            cout<<"ANG";
            return 0;
        }
        int q_size = q.size();
        // cout<<"----\n";
        for (int s=0 ; s<q_size ; s++){
            int cur = q.front();
            q.pop();
            // cout<<cur<<"\n";
            if (cur == G){
                cout<<answer;
                return 0;
            }
            /* 이미 불가능함이 보이는 노드(+1만 가능할때..)의 경우
            시간을 줄이려 시도해보았으나 visited 문제로 잘 안됨.
            어차피 시간초과가 나지 않는 복잡도(V+E = 100000 + 2) 이므로
            전체를 다 돌린다. */
            if (cur != 99999 && !visited[cur+1]){
                visited[cur+1] = true;
                q.push(cur+1);
            }
            if (cur < 50000 && !visited[B(cur)]){
                visited[B(cur)] = true;
                q.push(B(cur));
            }
        }
        answer++;
    }
    // 결론을 짓지 못하고 나왔다는건 위의 불가능 노드만 돌다가 끝났다는 뜻이므로 불가능.
    cout<<"ANG";
}