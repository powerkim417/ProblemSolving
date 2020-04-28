#include <iostream>

using namespace std;

int root[100001];

int find(int a){
    if (root[a]==a) return a;
    root[a] = find(root[a]);
    return root[a];
}

void merge(int a){
    // a의 차선책을 a-1의 차선책으로 넘기는 연산
    int ra = find(a);
    int rb = find(a-1);
    // if (ra==rb) return; // 여기서는 이럴 일이 없음
    root[ra] = rb;
}

// 1. 어느 게이트부터 넣으려고 하는지에 대한 아이디어
// 2. union-find 형태임을 한번에 확인하기 힘든 응용 문제

int main(void){
    int G, P;
    cin>>G>>P;
    for (int i=1 ; i<=G ; i++){
        root[i] = i;
    }
    int cnt = 0;
    int gi;
    for (int i=0 ; i<P ; i++){
        cin>>gi; // i번째 비행기는 1~gi번 게이트 사이에 도킹
        // 모든 비행기는 gi번째 게이트부터 도킹 시도.
        /* Ex) 1번 비행기는 1,2번 게이트, 2번 비행기는 1번 게이트가 가능할 때
        둘다 들어갈 수 있는 케이스임에도 불구하고
        1번이 1번 게이트를 먹어버리면 2번이 도킹을 할 수가 없다.
        즉, 각 비행기는 들어갈 수 있는 가장 큰 숫자의 게이트에 들어가야
        뒤 비행기중 자신보다 최대게이트가 큰 비행기는 어차피 상관 없고
        뒤 비행기중 자신보다 최대게이트가 작은 비행기에게 최대한 가능성을 남겨줄 수 있다. */
        int empty_gate = find(gi);
        /* 1~G 까지의 게이트(노드)가 있을 때,
        이 노드가 다른 곳에 연결되어 있으면, 즉 루트가 다른 노드이면
        루트는 이 노드에 대한 "차선책"이라고 생각.
        즉, 4에 접근했는데 루트가 2면
        4, 3 다 먹혀서 2로 가라는 뜻!
        이러한 차선책은 접근한 노드의 -1과 union하면서 생기는데,
        이 차선책이 0이라는 것은 이번 iteration에서 더이상 빈 게이트가 없다는 뜻.
        */
        if (empty_gate==0){
            break;
        }
        else {
            // gi번째에 넣으려고 했을 때의 차선책이 empty_gate라면(이미 find(gi)=empty_gate임)
            // empty_gate를 empty_gate-1에 union한다.
            cnt++;
            merge(empty_gate);
        }
    }
    cout<<cnt;
    return 0;
}