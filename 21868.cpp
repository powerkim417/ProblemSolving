#include <iostream>

using namespace std;

int abs(int n) {return (n>0)?n:-n;}

int main(void){
    int numer, denom, coef, C, x0;
    cin>>numer>>denom>>coef>>C>>x0;
    
    int L = coef*x0 + C;
    cout<<L<<"\n";

    // 0 < |coef*x + C - L| < e
    // 0 < |coef*x - coef*x0| < e
    // 0 < |x-x0| < e / |coef| = d
    // d = numer/(denom*|coef|)
    // 분모<=10000 이고 계수<=10000 이므로 d의 분모는 10^8 이하
    // 그러므로 0 0을 출력하는 경우는 coef이 0인 경우
    if (coef==0) cout<<"0 0";
    else cout<<numer<<" "<<denom*abs(coef);
    return 0;
}