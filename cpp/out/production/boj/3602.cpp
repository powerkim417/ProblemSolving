#include <iostream>
#include <cmath>

using namespace std;

/*
1: 1 0
2: 2 2
3: 5 4
4: 8 8
5: 13 12
6: 18 18
*/

int main(void){
    int b,w;
    cin>>b>>w;
    // 하나만 0인 경우는 답이 1로, 뒤 로직에서 처리되어야 함
    if (b==0 && w==0) {
        cout<<"Impossible";
        return 0;
    }
    int len; // 정사각형 길이
    // 사실상 쓰이게 될 타일 수를 분기하고, 이를 sqrt하고 버림하면
    // 만들 수 있는 가장 큰 정사각형이 나옴
    if (b==w){
        len = sqrt(b+w);
    }
    else if (b<w){ // b, b+1
        len = sqrt(2*b+1);
    }
    else { // w, w+1
        len = sqrt(2*w+1);
    }
    cout<<len;
    return 0;
}