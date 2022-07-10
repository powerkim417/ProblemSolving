#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main() {
    
    double d, hd, vd;
    int hr, vr;
    while (1){
        // cin>>d>>hr>>vr;
        scanf("%lf %d %d", &d, &hr, &vr);
        if (d==0 && hr==0 && vr==0) break;
        hd = sqrt(337)/16 * hr/d;
        vd = sqrt(337)/9 * vr/d;
        // cout<<"Horizontal DPI: "<<round(hd*100)/100<<endl;
        // cout<<"Vertical DPI: "<<round(vd*100)/100<<endl;
        printf("Horizontal DPI: %.2lf\n", hd);
        printf("Vertical DPI: %.2lf\n", vd);
    }
    return 0;
}