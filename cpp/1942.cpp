#include <iostream>

using namespace std;

int main(void){
    int h1, m1, s1, h2, m2, s2;
    char c;
    for (int t=0 ; t<3 ; t++){
        cin>>h1>>c>>m1>>c>>s1>>h2>>c>>m2>>c>>s2;
        int cnt = 0;
        while (1){
            if ((h1*10000+m1*100+s1)%3==0) cnt++;
            if (h1==h2 && m1==m2 && s1==s2) break; // 시분초 변환하기 전에 비교해야 함
            s1++;
            if (s1==60){
                s1 = 0;
                m1++;
            }
            if (m1==60){
                m1 = 0;
                h1++;
            }
            if (h1==24){
                h1 = 0;
            }
        }
        cout<<cnt<<"\n";
    }
}