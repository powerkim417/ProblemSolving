#include <iostream>

using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void sort(int& a, int& b, int& c){
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
}

int main(void){
    int a, b, c;
    int right=0, acute=0, obtuse=0;
    while (cin>>a>>b>>c){
        // 삼, 직, 예, 둔
        sort(a,b,c);
        if (a+b<=c) break;
        if (a*a+b*b>c*c) acute++;
        else if (a*a+b*b==c*c) right++;
        else obtuse++;
    }
    cout<<right+acute+obtuse<<" "<<right<<" "<<acute<<" "<<obtuse;
    return 0;
}