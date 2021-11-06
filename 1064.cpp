#include <iostream>
#include <cmath>

using namespace std;

// 나올 수 있는 평행사변형은 총 3개로,
// ABC의 세 변이 a,b,c일 때 가능한 둘레는
// 2(a+b), 2(b+c), 2(c+a)

// 평행사변형 안나오는 경우: 일직선

double max(double i, double j, double k){
    double temp = (i>j)?i:j;
    return (temp>k)?temp:k;
}

double min(double i, double j, double k){
    double temp = (i<j)?i:j;
    return (temp<k)?temp:k;
}

int main(void){
    int xa, ya, xb, yb, xc, yc;
    cin>>xa>>ya>>xb>>yb>>xc>>yc;
    if ((yb-yc)*(xa-xb) == (ya-yb)*(xb-xc)) {
        cout<<"-1";
        return 0;
    }
    double c = sqrt((xa-xb)*(xa-xb) + (ya-yb)*(ya-yb));
    double a = sqrt((xb-xc)*(xb-xc) + (yb-yc)*(yb-yc));
    double b = sqrt((xc-xa)*(xc-xa) + (yc-ya)*(yc-ya));
    double longest = max(2*(a+b), 2*(b+c), 2*(c+a));
    double shortest = min(2*(a+b), 2*(b+c), 2*(c+a));
    cout<<fixed;
    cout.precision(9);
    // cout<<a<<" "<<b<<" "<<c<<"\n";
    cout<<longest-shortest;
    return 0;
}