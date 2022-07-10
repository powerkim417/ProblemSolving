#include <iostream>
#include <queue>

using namespace std;

char ops[4] = {'D', 'S', 'L', 'R'};

int convert(char c, int x){
    switch (c){
        case 'D':
            x = x*2;
            x %= 10000;
            return x;
        case 'S':
            if (x==0) return 9999;
            else return (x-1);
        case 'L':
            return ((x%1000)*10 + x/1000);
        case 'R':
            return (x/10 + (x%10)*1000);
    }
}

char cmd(int a, int b){
    for (int i=0 ; i<4 ; i++){
        if (convert(ops[i], a) == b) return ops[i];
    }
}

bool visited[10000];

int prev_num[10000];
/* 메모리 초과 해결 방법

가능한 BFS 경로를 모두 갖고 있으면 메모리 초과가 발생하므로
해당 노드의 이전 노드를 기록하는 배열을 만들어 자동으로
역으로 추적하면 경로를 구할 수 있게 구현!!!!!!! */

int main(void){
    int T;
    cin>>T;
    int a, b;
    for (int t=0 ; t<T ; t++){
        cin>>a>>b;
        for (int i=0 ; i<10000 ; i++) {
            visited[i] = false;
            prev_num[i] = -1;
        }
        queue<int> q;
        q.push(a);
        visited[a] = true;
        bool found = false;
        while (!q.empty() && !found){
            int cur = q.front();
            // cout<<"cur: "<<cur<<endl;
            q.pop();
            for (int i=0 ; i<4 ; i++){
                int next = convert(ops[i], cur);
                // cout<<"next: "<<next<<endl;
                if (!visited[next]){
                    visited[next] = true;
                    prev_num[next] = cur; /* 첫 방문때만 갱신.
                    만약 2번만에도 도달하고 1번만에도 도달하면
                    그 숫자는 1번만에 도달하는 것이므로
                    2번만에 도달하는 경우는 반영되면 안됨 */
                    // cout<<"prev to "<<next<<" is "<<cur<<endl;
                    q.push(next);
                    if (next == b){
                        found = true;
                        break;
                    }
                }
            }
        }
        string answer = "";
        int temp = b;
        while (temp != a) {
            answer = cmd(prev_num[temp], temp) + answer;
            temp = prev_num[temp];
        } 
        cout<<answer<<"\n";
    }
}