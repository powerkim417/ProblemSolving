#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int x,y;
vector<int> color[5001];

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for (int i=0 ; i<n ; i++){
        cin>>x>>y;
        color[y].push_back(x);
    }
    for (int i=1 ; i<=n ; i++){ // 색깔의 범위가 1~N 이다
        sort(color[i].begin(), color[i].end());
    }
    // 답이 int도 맞음
    // 점들의 위치가 모두 다르므로 5000개의 색깔이 모두 있어도
    // 최대로 거리를 뽑으려면 100000 + 99998 + .. + 90002 = 475,005,000. 즉 int 범위
    int answer = 0;
    for (int i=1 ; i<=n ; i++){
        int len = color[i].size();
        if (len==0) continue;
        for (int j=0 ; j<len ; j++){
            if (j==0) answer += color[i][1]-color[i][0];
            else if (j==len-1) answer += color[i][len-1]-color[i][len-2];
            else {
                answer += ((color[i][j+1]-color[i][j] > color[i][j]-color[i][j-1]) ? color[i][j]-color[i][j-1] : color[i][j+1]-color[i][j]);
            }
        }
    }
    cout<<answer;
    return 0;
}