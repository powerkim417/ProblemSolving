#include <iostream>

using namespace std;

int map[10][10];
bool paper[10][10]; // map에 색종이를 붙이면 1->0 하고, 다시 뗄때 0->1로 해주면 되므로 이 배열은 필요없음
int paper_remain[6] = {-1, 5, 5, 5, 5, 5};
int ans = 26;

void update(int r, int c, int n, bool flag){
    // (r, c)에 n크기 색종이를 부착true/탈착false
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            // paper[r+i][c+j] = flag;
            map[r+i][c+j] = (flag)?0:1;
        }
    }
    (flag) ? paper_remain[n]-- : paper_remain[n]++;
}

bool isRange(int r, int c){
    return (r>=0 && r<10 && c>=0 && c<10);
}

bool able(int r, int c, int n){
    // (r, c)에 n크기 색종이 부착이 가능한지..
    // 해당 크기 스티커가 있어야 하고,
    // 모든 구간이 범위 내여야 하고,
    // 모든 구간이 1이어야 하고,
    // 이미 스티커가 붙어있지 않아야 함 (자료구조 변경으로 인해 필요X)
    if (paper_remain[n]==0) return false;

    if (!isRange(r+n-1, c+n-1)) return false;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (map[r+i][c+j]==0) return false;
            // if (paper[r+i][c+j]) return false;
        }
    }
    return true;
}

void dfs(int r, int c, int cnt){
    // cout<<r<<" "<<c<<" "<<cnt<<"\n";
    if (c==10) { // 열을 초과했을 때 다음 행으로 단순히 넘겨주는 작업
        dfs(r+1, 0, cnt);
        return;
    } 
    if (r==10){ // 모두 순회한 경우
        if (cnt < ans) ans = cnt;
        // for (int i=1 ; i<=5 ; i++){
        //     cout<<paper_remain[i]<<" ";
        // }
        // cout<<"\n";
        return;
    }

    if (cnt > ans) return; // 다 돌기전에 최소값 넘은 경우

    if (map[r][c]==1){ // 1이라면
        for (int n=1 ; n<=5 ; n++){
            // cout<<"able("<<r<<", "<<c<<", "<<n<<")="<<(bool)able(r,c,n)<<"\n";
            if (able(r, c, n)){
                update(r, c, n, true);
                dfs(r, c+1, cnt+1); // n>=2의 크기를 붙였을 경우 (r, c+1)는 스티커가 붙어있어 able = false가 되므로 겹칠 걱정 x
                update(r, c, n, false);
            }
        }
    }
    else dfs(r, c+1, cnt);
}

int main(void){
    for (int i=0 ; i<10 ; i++){
        for (int j=0 ; j<10 ; j++){
             cin>>map[i][j];
             paper[i][j] = false;
        }
    }
    dfs(0, 0, 0);
    if (ans==26) cout<<"-1";
    else cout<<ans;
    return 0;
}