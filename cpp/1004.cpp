#include <iostream>
#include <cmath>

using namespace std;

int cx, cy;

double dist(int x, int y){
    return sqrt((x-cx)*(x-cx) + (y-cy)*(y-cy));    
}

bool inCircle(double d, int r){
    if (d<r) return true;
    else return false;
}

int main(void){
    int T;
    cin>>T;
    int x1,y1,x2,y2;
    int n;
    int r;
    int cnt;
    for (int t=0 ; t<T ; t++){
    	cnt = 0;
        int temp;
        cin>>x1>>y1>>x2>>y2;
        cin>>n;
        for (int i=0 ; i<n ; i++){
            cin>>cx>>cy>>r;
            temp = 0;
            if (inCircle(dist(x1, y1), r)) {
            	temp++;
            }
            if (inCircle(dist(x2, y2), r)) {
            	temp++;
            }
            if (temp == 1) cnt++;
        }
        cout<<cnt<<"\n";
    }
}