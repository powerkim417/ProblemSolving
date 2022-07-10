#include <iostream>

using namespace std;

int main(void){
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    int n,c;
    cin>>n>>c;
    int X = n, Y = n;
    int x,y;
    for (int i=0 ; i<c ; i++){
        cin>>x>>y;
        if (x>=X || y>=Y) continue;
        // 가로 자른 면적: x*B
        // 세로 자른 면적: y*A
        if (x*Y >= y*X) X = x; // 가로로 자르기
        else Y = y; // 세로로 자르기
    }
    cout<<X*Y;
    return 0;
}