#include <iostream>

using namespace std;

int main(void){
    int h,w;
    cin>>h>>w;
    if (h>w){
        int temp = h;
        h = w;
        w = temp;
    }
    // h <= w
    // 긴 애의 1/3 또는 작은 애의 1/2
    double answer;
    if (w>=3*h) answer = h;
    else if (w>=1.5*h) answer = w/3.0;
    else answer = h/2.0;
    cout<<answer;
    return 0;
}