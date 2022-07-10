#include <iostream>

using namespace std;

int main(void){
    int h1, m1, s1, h2, m2, s2;
    char c;
    cin>>h1>>c>>m1>>c>>s1>>h2>>c>>m2>>c>>s2;
    int answer = (h2-h1)*3600 + (m2-m1)*60 + (s2-s1);
    if (answer<0) answer += 24*3600;
    cout<<answer;
    return 0;
}