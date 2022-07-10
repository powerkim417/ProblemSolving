#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int a,b;
    int small = 0; // 1번 소가 더 왼쪽 결과('1'<2, '2'<3, '3'<1)를 냈을 때: b-a=1, -2 -> (b-a+3)%3=1
    int big = 0; // 1>3, 3>2, 2>1: b-a=-1, 2 -> (b-a+3)%3=2
    while (n--){
        cin>>a>>b;
        if ((b-a+3)%3 == 1) small++;
        else if ((b-a+3)%3 == 2) big++;
    }
    if (big>small) cout<<big;
    else cout<<small;
    return 0;
}