#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    // n = a+b+c (a<=b<=c)
    // a랑 b를 정하면 c는 정해짐
    long long cnt = 0;
    for (int a=1 ; a<=n-2 ; a++){
        for (int b=a ; b<=n-2 ; b++){
            // a<=b 이므로 b<=c만 확인하면 됨
            int c = n-a-b;
            if (b>c) break; // 이 이후 b가 커질수록 c는 작아지므로 뒤도 전부 만족 못할테니 break
            // 이제 삼각형 되는지..
            if (a+b>c) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}