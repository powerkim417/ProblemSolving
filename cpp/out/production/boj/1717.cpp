#include <iostream>

using namespace std;

int root[1000001];

int min(int a, int b){
    return (a>b)?b:a;
}

int find(int a){ // find를 하면서 루트까지의 root값을 전부 갱신해줌
    if (root[a]<0) return a;
    else {
        root[a] = find(root[a]);
        return root[a];
    }
}

// UNION FIND 기본 예제

// 1. find할 때 루트까지 가는 길의 모든 노드의 root값을 전부 갱신해줌
// 2. 집합의 루트 역할을 하는 노드의 root값을 -1로 시작해서, -(집합의 크기)로 활용
// 크기가 더 작은 집합의 노드들을 더 큰 집합에 병합시켜야 find의 연산수가 줄어듦

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin>>n>>m;
    for (int i=0 ; i<=n ; i++){
        root[i] = -1;
    }
    int op, a, b;
    for (int i=0 ; i<m ; i++){
        cin>>op>>a>>b;
        if (op==0){ // union
            int ra = find(a);
            int rb = find(b);
            if (ra==rb) continue; // 둘이 이미 같은 집합일 때는 union연산 필요 없음
            if (-root[ra] < -root[rb]) { // a의 집합의 수가 더 적음.. a를 b에 합치기 
                root[rb] += root[ra]; // 원소 수 합하기
                root[ra] = rb; // 이때는 height가 2겠지만 나중에 find하면 다시 height 1로 정리됨
            }
            else {
                root[ra] += root[rb];
                root[rb] = ra;
            }
        }
        else {
            if (find(a)==find(b)) cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}