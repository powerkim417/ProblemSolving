#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    // n-a-b=0, 즉 n=a+b(0<=a,b<=99)
    for (int a=0 ; a<=99 ; a++){
        if (n-a>=0 && n-a<=99){
            // 지금 발견한 a가 가장 작은 a이고,
            // a+b 부터 b+a 까지 전부다 해당될 것이다.
            // 따라서 답은 b-a+1 = (n-a)-a+1
            cout<<(n-2*a+1);
            return 0;
        }
    }
    // a를 못찾은 경우
    cout<<"0";
    return 0;
}