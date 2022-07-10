#include <iostream>

using namespace std;

void visit(int r, int c, int curi, int curj, int curn, long long& curnum){
    // 현재 범위 안에 없는 경우
    if (!(curi<=r && r<curi+curn && curj<=c && c<curj+curn)){
        curnum += curn*curn;
        return;
    }
    // 현재 범위 안에 있는 경우
    if (curn == 2){
        cout<<(curnum + (r-curi)*2 + (c-curj));
        return;
    }
    else {
        visit(r, c, curi, curj, curn/2, curnum);
        visit(r, c, curi, curj+curn/2, curn/2, curnum);
        visit(r, c, curi+curn/2, curj, curn/2, curnum);
        visit(r, c, curi+curn/2, curj+curn/2, curn/2, curnum);
    }
}

// 분할 정복
// map에 전부 저장하지 않고 풀어야 함
int main(void){
    int n, r, c;
    cin>>n>>r>>c;
    long long curnum = 0;
    visit(r, c, 0, 0, (1<<n), curnum);
    return 0;
}