#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int minx = 10001, maxx = -10001, miny = 10001, maxy = -10001;
    int x, y;
    for (int i=0 ; i<n ; i++){
        cin>>x>>y;
        if (x<minx) minx = x;
        if (x>maxx) maxx = x;
        if (y<miny) miny = y;
        if (y>maxy) maxy = y;
    }
    cout<<(maxx-minx)*(maxy-miny);
    return 0;
}