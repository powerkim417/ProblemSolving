#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, d;
int map[15][15];
typedef pair<int, int> P;
vector<P> archer;
vector<int> choose;

int abs(int a){
    return (a>0)?a:-a;
}

int dist(P a, P b){
    return abs(a.first-b.first)+abs(a.second-b.second);
}

int defense(vector<pair<P, bool>> enemy){
    int ret = 0;
    while (!enemy.empty()){
        // 각 궁수별 타겟 설정
        for (int i=0 ; i<m ; i++){
            if (choose[i] == 0) continue;
            // archer[i] 이 궁수의 위치
            int min_dist = 14+14+1;
            int min_idx = -1;
            int min_left = m+1; // 가장 가까운 적의 열번호
            for (int j=0 ; j<enemy.size() ; j++){
                int cur_dist = dist(archer[i], enemy[j].first);
                if (cur_dist > d) continue; // 사정거리 너머 있다면 넘김
                if (min_dist > cur_dist) {
                    min_dist = cur_dist;
                    min_idx = j;
                    min_left = enemy[j].first.second;
                }
                else if (min_dist == cur_dist) {
                    if (min_left > enemy[j].first.second){
                        min_idx = j;
                        min_left = enemy[j].first.second;
                    }
                }
            }
            // 모든 적이 archer[i]의 사정거리 밖이라면 min_idx는 -1 일 것..
            if (min_idx != -1) enemy[min_idx].second = true;
        }
        // 타겟된 적은 제거하고, 살아남은 적은 이동
        for (auto it=enemy.begin() ; it!=enemy.end() ; ){
            if ((*it).second) {
                enemy.erase(it);
                ret++;
            }
            else { // 살아남은 적
                if ((*it).first.first==n-1) { // 성으로 이동하는 적
                    enemy.erase(it);
                }
                else {
                    (*it).first.first++;
                    it++;
                }
            }
        }
    }
    return ret;
}

int main(void){
    cin>>n>>m>>d;
    vector<pair<P, bool>> enemy;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<m ; j++){
            cin>>map[i][j];
            if (map[i][j]==1) enemy.push_back({{i, j}, false});
        }
    }
    for (int i=0 ; i<m ; i++){
        archer.push_back({n, i});
    }
    // m개 위치중 궁수 3명위치가 정해지는 경우의 수: mC3
    for (int i=0 ; i<m-3 ; i++) choose.push_back(0);
    for (int i=0 ; i<3 ; i++) choose.push_back(1);
    int ans = -1;
    do {
        int temp = defense(enemy);
        if (ans < temp) ans = temp;
    } while (next_permutation(choose.begin(), choose.end()));
    cout<<ans;
    return 0;
}