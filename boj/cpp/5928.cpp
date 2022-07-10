#include <iostream>

using namespace std;

int main(void){
    int d, h, m;
    cin>>d>>h>>m;
    int ret = 0;
    ret += (d-11)*24*60;
    ret += (h-11)*60;
    ret += (m-11);
    if (ret<0) ret = -1;
    cout<<ret;
    return 0;
}