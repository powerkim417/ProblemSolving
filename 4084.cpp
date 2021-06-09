#include <iostream>

using namespace std;

int abs(int n){
    return (n>0)?n:(-n);
}
// 힌트: 만약 네 정수가 2^n보다 작다면, 3*n번 이내에 수렴한다.
// 네 정수가 2^31보다 작으므로 93번 이내에 수렴하니까 그냥 시뮬 돌려도 됨 

int main(void){
    int a,b,c,d;
    while (cin>>a>>b>>c>>d){
        if (a==0 && b==0 && c==0 && d==0) break;
        int cnt = 0, temp;
        while (a!=b || b!=c || c!=d){
            cnt++;
            temp = a;
            a = abs(a-b);
            b = abs(b-c);
            c = abs(c-d);
            d = abs(d-temp);
        }
        cout<<cnt<<"\n";
    }
    return 0;
}