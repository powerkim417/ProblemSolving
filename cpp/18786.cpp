#include <iostream>
#include <vector>

using namespace std;

bool exist[20001][20001] = {}; // (x-10000, y-10000) 이 들어있는지 여부

int abs(int x){
    return (x>0)?x:(-x);
}

// 세 점을 택하되, 한 변은 x축평행, 한 변은 y축평행 이어야 함

int main(void){
    int n;
    cin>>n;
    int x, y;
    int answer = 0;
    vector<pair<int, int>> v;
    for (int i=0 ; i<n ; i++){
        cin>>x>>y;
        exist[x+10000][y+10000] = true;
        v.push_back({x, y});
    }
    for (int i=0 ; i<n ; i++){
        int temp;
        for (int j=0 ; j<n ; j++){
            if (i==j) continue;
            // 두 점은 (v[i].first, v[i].second), (v[j].first, v[j].second)
            // (vi f, vj s) 또는 (vj f, vi s)가 존재하는지 확인하고, 있다면 넓이 계산. 없으면 넘기고
            if (exist[v[i].first+10000][v[j].second+10000] || exist[v[j].first+10000][v[i].second+10000]){
                temp = abs(v[j].first-v[i].first)*abs(v[j].second-v[i].second);
                if (temp>answer) answer = temp;
            }
            else continue;
        }
    }
    cout<<answer;
    return 0;
}