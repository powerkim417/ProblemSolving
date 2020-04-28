#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, c_cnt;
int map[50][50];
vector<pair<int, int>> house, chicken;
vector<int> choose;
int answer = (49+49)*2*50 + 1; // INF

/* 아이디어 중요!! 
입력받은 치킨집 갯수 중 최대 M개를 선택인데,
M개를 골랐을 때의 최소거리는 항상 M-1, M-2, ..개를 골랐을 때의 최소거리보다 항상 작으므로
사실상 M개를 선택했을 때의 거리를 구하면 된다.
pf idea) M-1개의 치킨집을 골랐고 최단거리로 연결되어있다고 가정했을 때, 어느 위치에 치킨집 하나를 추가해 M개를 만들어도
최소 하나의 집의 치킨 거리가 줄어들거나, 치킨 거리가 그대로일 것이며, 치킨 거리가 늘어날 일은 없으므로!
*/

int abs(int x){
    return (x>0)?x:-x;
}

int dist(pair<int, int> h, pair<int, int> c){
    return abs(h.first-c.first)+abs(h.second-c.second);
}

int main(void){
    cin>>n>>m;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>map[i][j];
            if (map[i][j]==1) house.push_back({i, j});
            if (map[i][j]==2) chicken.push_back({i, j});
        }
    }
    c_cnt = chicken.size();
    // cnt개 중 m개를 골라 경우를 모두 계산! (cnt는 최대 13이므로 계산의 최대 경우는 13C6 = 1716)
    for (int i=0 ; i<c_cnt ; i++){
        if (i<c_cnt-m) choose.push_back(0); // 버리는 치킨집 cnt-m개
        else choose.push_back(1); // 놔두는 치킨집 m개
    }
    int temp, mindist;
    do {
        temp = 0;
        for (auto h: house){
            mindist = (49+49)+1;
            for (int i=0 ; i<c_cnt ; i++){
                if (choose[i]==0) continue;
                if (dist(h, chicken[i])<mindist) mindist = dist(h, chicken[i]);
            }
            temp += mindist;
        }
        if (temp<answer) answer = temp;
    } while (next_permutation(choose.begin(), choose.end()));
    cout<<answer;
    return 0;
}