#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int src;
    int dst;
    int cost;

    // sort함수는 타입의 operator< 연산자로 비교
    bool operator<(const edge& that) const {
        return cost < that.cost;
    }
};

int root[10001];
vector<edge> edges;

int find(int x){
    if (x == root[x]) return x;
    return root[x] = find(root[x]);
}

// 새 edge가 사이클을 형성한다면 false를 반환하고,
// 아니라면 합치고 true 반환
// 사이클 여부 확인 + 아닐 시 merge 작업이 모두 수행되는 깔끔한 함수
bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if (a==b) return false;
    root[a] = b;
    return true;
}

// 임의의 두 정점 사이에 경로가 있다 => 연결 그래프 보장
// MST 기본 예제 - kruskal(크루스칼)
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V, E; cin>>V>>E;
    int a, b, c;
    for (int i=0 ; i<E ; i++){
        cin>>a>>b>>c;
        edges.push_back({a, b, c});
    }
    sort(edges.begin(), edges.end());
    for (int i=1 ; i<=V ; i++) root[i] = i;
    int answer = 0;

    for (edge e: edges){
        if (merge(e.src, e.dst)){
            answer += e.cost;
        }
    }
    cout<<answer;
    return 0;
}