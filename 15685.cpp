#include <iostream>
#include <vector>

using namespace std;

// 우 상 좌 하
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

bool used[101][101] = {};

bool containSquare(int x, int y){
    if (used[x][y] && used[x+1][y] && used[x][y+1] && used[x+1][y+1]) return true;
    else return false;
}

int x, y, d, g;
vector<pair<int, int>> curve;
vector<pair<int, int>> temp;
pair<int, int> lp; // last point (x, y)

// 90도 시계방향 회전이지만, 실제 그림에서는 y축이 아래로 증가하므로 반시계라고 생각해야 함
// 90도 회전: (x'-lp.x) = -(y-lp.y), (y'-lp.y) = (x-lp.x)
// x'=-y+lp.x+lp.y, y'=x-lp.x+lp.y
pair<int, int> rotate(pair<int, int> p){
    return {-p.second+lp.first+lp.second, p.first-lp.first+lp.second};
}

void dragonCurve(int g){
    // cout<<"------------\n";
    // cout<<"<"<<x<<" "<<y<<" "<<d<<" "<<g<<">\n";
    // cout<<"Generation 0\n";
    curve.push_back({x, y});
    // cout<<x<<" "<<y<<"\n";
    lp = {x+dx[d], y+dy[d]};
    curve.push_back(lp);
    // cout<<lp.first<<" "<<lp.second<<"\n";
    if (g==0) return;
    // 1세대 이상인 경우
    for (int i=1 ; i<=g ; i++){
        // cout<<"Generation "<<i<<"\n";
        temp = curve;
        int v_size = temp.size();
        lp = temp[v_size-1];
        for (int j=v_size-2 ; j>=0 ; j--){ // 마지막은 회전기준점이고, 그 이전 점부터 회전변환된 점을 넣어야 이번 세대 맨 마지막 점이 다음 세대 회전기준점이 된다. 
            curve.push_back(rotate(temp[j]));
            // cout<<rotate(temp[j]).first<<" "<<rotate(temp[j]).second<<"\n";
        }
    }
}

int main(void){
    int n;
    cin>>n;
    for (int i=0 ; i<n ; i++){
        cin>>x>>y>>d>>g;
        curve.clear();
        dragonCurve(g);
        int v_size = curve.size();
        for (int j=0 ; j<v_size ; j++){
            used[curve[j].first][curve[j].second] = true;
        }
    }
    int cnt=0;
    for (int i=0 ; i<=99 ; i++){
        for (int j=0 ; j<=99 ; j++){
            if (containSquare(i, j)) cnt++;
        }
    }
    cout<<cnt;
}