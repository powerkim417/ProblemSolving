#include <iostream>
#include <cmath>

using namespace std;

int main(void){
    int n;
    // 1<=b<=a<=500, a^2 = b^2 + n.
    // n = a^2 - b^2 = (a+b)(a-b).   a+b>a-b
    cin>>n;
    int cnt = 0;
    for (int i=1 ; i<sqrt(n) ; i++){ // i = a-b 이고, i<sqrt(n)까지만 봐도 됨
        if (n%i != 0) continue;
        // i=a-b, n/i=a+b
        if ((i+n/i)%2 != 0) continue; // a,b가 정수가 안되는 경우
        cnt++;
    }
    cout<<cnt;
}