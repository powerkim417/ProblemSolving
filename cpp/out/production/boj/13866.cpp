#include <iostream>

using namespace std;

int main(void){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    // a<=b<=c<=d 이므로 두 팀의 레벨 차가 최소인 경우는 a+d, b+c인 경우
    if (a+d>b+c) cout<<(a+d-b-c);
    else cout<<(b+c-a-d);
}