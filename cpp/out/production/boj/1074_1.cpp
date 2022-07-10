#include <iostream>

using namespace std;

int jump(int n, int r, int c){
    if (n==0) return 0;
    return 4*jump(n-1, r/2, c/2) + 2*(r%2) + c%2;
}

// 좌표 이용 재귀
// 좌표값이 두배가 되면 실제값은 4배가 됨
int main(void){
    int n, r, c;
    cin>>n>>r>>c;
    cout<<jump(n, r, c);
    return 0;
}