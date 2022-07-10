#include <iostream>

using namespace std;

int main(void){
    int y1, m1, d1, y2, m2, d2;
    cin>>y1>>m1>>d1>>y2>>m2>>d2;
    int age1 = y2-y1;
    if (m1 > m2){
        age1--;
    }
    else if (m1 == m2 && d1 > d2){
        age1--;
    }
    cout<<age1<<"\n"<<(y2-y1+1)<<"\n"<<(y2-y1);
}