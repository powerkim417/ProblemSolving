#include <iostream>

using namespace std;

int a, b, cnt;

void euclid(int a, int b){
    // 돌 게임 업그레이드..
    cnt++;
}

int main(void){
    while (1){
        cin>>a>>b;
        if (a=0 && b==0) return 0;
        if (b>a){
            int temp = b;
            b = a;
            a = temp;
        } // 이제 무조건 a>=b
        cnt = 0;
        euclid(a, b);
        if (cnt%2==1) cout<<"A wins\n";
        else cout<<"B wins\n";
    }
}