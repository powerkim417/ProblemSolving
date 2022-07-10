#include <iostream>
#include <vector>

using namespace std;

int buddy[401][4]; // i번째 학생의 선호 친구들
int map[20][20] = {};

int n;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

struct point {
    int i;
    int j;
};

bool isRange(int i, int j){
    return (i>=0 && i<n && j>=0 && j<n);
}

int adjCnt(int i, int j, int num){
    int ret = 0;
    for (int d=0 ; d<4 ; d++){
        int ni = i+dr[d];
        int nj = j+dc[d];
        if (!isRange(ni, nj)) continue;
        int adjNum = map[ni][nj];
        if (buddy[num][0]==adjNum || buddy[num][1]==adjNum || buddy[num][2]==adjNum || buddy[num][3]==adjNum) ret++;
    }
    return ret;
}

int adjBlankCnt(int i, int j){
    int ret = 0;
    for (int d=0 ; d<4 ; d++){
        int ni = i+dr[d];
        int nj = j+dc[d];
        if (!isRange(ni, nj)) continue;
        if (map[ni][nj]==0) ret++;
    }
    return ret;
}

int score(int cnt){
    if (cnt==0) return 0;
    int ret = 1;
    while (--cnt){
        ret *= 10;
    }
    return ret;
}

int main(void){
    cin>>n;
    int num;
    for (int k=0 ; k<n*n ; k++){
        cin>>num;
        for (int j=0 ; j<4 ; j++){
            cin>>buddy[num][j];
        }
        // 1
        vector<point> candidate;
        int maxAdjCnt = -1;
        for (int i=0 ; i<n ; i++){
            for (int j=0 ; j<n ; j++){
                if (map[i][j]!=0) continue;
                int tempAdjCnt = adjCnt(i, j, num);
                if (tempAdjCnt > maxAdjCnt) {
                    maxAdjCnt = tempAdjCnt;
                    candidate.clear();
                    candidate.push_back({i, j});
                }
                else if (tempAdjCnt == maxAdjCnt){
                    candidate.push_back({i, j});
                }
            }
        }
        if (candidate.size() == 1){
            // cout<<"1. "<<num<<"\n";
            map[candidate[0].i][candidate[0].j] = num;
            continue;
        }

        // 2
        int maxAdjBlankCnt = -1;
        for (auto c: candidate){
            if (map[c.i][c.j]!=0) continue;
            int tempAdjBlankCnt = adjBlankCnt(c.i, c.j);
            if (tempAdjBlankCnt > maxAdjBlankCnt) {
                maxAdjBlankCnt = tempAdjBlankCnt;
                candidate.clear();
                candidate.push_back({c.i, c.j});
            }
            else if (tempAdjBlankCnt == maxAdjBlankCnt){
                candidate.push_back({c.i, c.j});
            }
        }
        // + 3
        // cout<<"23. "<<num<<"\n";
        map[candidate[0].i][candidate[0].j] = num;
    }
    int answer = 0;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            // cout<<map[i][j]<<" ";
            answer += score(adjCnt(i, j, map[i][j]));
        }
        // cout<<"\n";
    }
    cout<<answer;
    return 0;
}