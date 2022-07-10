#include <iostream>

using namespace std;

int min(int a, int b, int c){
    int t = (a>b)?b:a;
    return (t>c)?c:t;
}

int main(void){
    int n, m;
    cin>>n>>m;
    int minsix = 1001, minone = 1001;
    int a,b;
    for (int i=0 ; i<m ; i++){
        cin>>a>>b;
        if (a<minsix) minsix = a;
        if (b<minone) minone = b;
    }
    cout<<min((n/6 * minsix + n%6 * minone), (n+5)/6 * minsix, n * minone); // 정량으로 사거나, 6개단위로 사거나, 1개단위로 사거나
    return 0;
}