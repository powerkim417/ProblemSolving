#include <iostream>
#include <cstdio>
using namespace std;
int main(void){
    int t;
    scanf("%d", &t);
    for (int i=0 ; i<t ; i++){
        printf("Case %d: ", i+1);
        int n;
        scanf("%d", &n);
        double maxX = -1000, maxY = -1000, minX = 1000, minY = 1000;
        for (int j=0 ; j<n ; j++){
            double x,y;
            scanf("%lf %lf", &x, &y);
            if (x>maxX) maxX = x;
            if (x<minX) minX = x;
            if (y>maxY) maxY = y;
            if (y<minY) minY = y;
        }
        double area = (maxX-minX)*(maxY-minY);
        double peri = ((maxX-minX)+(maxY-minY))*2.0;
        // cout<<"Area "<<area<<", Perimeter "<<peri<<endl;
        printf("Area %lf, Perimeter %lf\n", area, peri);
    }
}