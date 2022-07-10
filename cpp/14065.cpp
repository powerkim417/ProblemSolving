#include <iostream>

using namespace std;

// 1갤런 = 3.785411784L
// 1마일 = 1609.344m = 1.609344km
// 연료 소비량을 갤런/마일 -> 100km/L 로 변환
// 100km/L = 100 * (마일/1.609344) / (갤런/3.785411784)
// = (378.5411784/1.609344) / (갤런/마일)
int main(void){
    double x;
    cin>>x;
    x = (378.5411784/1.609344)/x;
    // x = 100.00/((1.609344/3.785411784)*x);
    cout<<fixed;
    cout.precision(6);
    cout<<x;
    return 0;
}