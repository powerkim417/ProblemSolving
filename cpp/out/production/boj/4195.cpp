#include <iostream>
#include <map>

using namespace std;

// 친구관계 최대 100000 이므로 친구는 최대 200000
int root[200000];

int find(int a){
    if (root[a]<0) return a;
    else {
        root[a] = find(root[a]);
        return root[a];
    }
}

// 루트노드의 root에 트리 크기를 저장하는 기법 활용

void merge(int a, int b){
    // cout<<"merge with "<<a<<" and "<<b<<"\n";
    int ra = find(a);
    int rb = find(b);
    if (ra==rb){
        // 두 노드의 루트가 같을 때는 merge 작업을 하면 안된다.
        cout<<-root[ra]<<"\n";
    }
    else {
        if (-root[ra] > -root[rb]){
            root[ra] += root[rb];
            root[rb] = ra;
            cout<<-root[ra]<<"\n";
        }
        else {
            root[rb] += root[ra];
            root[ra] = rb;
            cout<<-root[rb]<<"\n";
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    map<string, int> m;
    while (t--){
        int f;
        cin>>f;
        string a, b;
        m.clear();
        int id=0;
        for (int i=0 ; i<200000 ; i++){
            root[i] = -1;
        }
        for (int i=0 ; i<f ; i++){
            cin>>a>>b;
            if (!m.count(a)) m.insert({a, id++});
            if (!m.count(b)) m.insert({b, id++});
            merge(m[a], m[b]);
        }
    }
}