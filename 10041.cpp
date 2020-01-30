#include <iostream>

using namespace std;

int abs(int a){
    if (a>0) return a;
    else return -a;
}

int max(int a, int b){
    if (a>b) return a;
    else return b;
}

int main(void){
    int w,h,n;
    cin>>w>>h>>n;
    int answer = 0;
    int xp, yp, x, y;
    cin>>xp>>yp;
    for (int i=1 ; i<n ; i++){
        cin>>x>>y;
        if ((x-xp)*(y-yp) > 0){ // 북동쪽 길을 활용하는 경우
            // x,y중 작은 값만큼 대각선 이동, 그리고 큰-작은 값만큼 수직또는수평 이동
            // 즉 다시말해 큰 값만큼 이동하는 셈
            answer += max(abs(x-xp),abs(y-yp));
        }
        else {
            answer += abs(x-xp) + abs(y-yp);
        }
        xp = x;
        yp = y;
    }
    cout<<answer;
}