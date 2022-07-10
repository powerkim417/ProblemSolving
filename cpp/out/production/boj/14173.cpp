#include <iostream>

using namespace std;

int main(void){
    // 두 직사각형을 모두 커버하는 최소 크기의 정사각형 구하기.
    // x값들 중 최대-최소 와 y값들 중 최대-최소 가 나오는데,
    // 정사각형을 구해야 하므로 두 길이 중 큰 값을 제곱
    int xmax = -1, ymax = -1, xmin = 10, ymin = 10, temp;
    for (int i=0 ; i<4 ; i++){
        cin>>temp;
        if (temp>xmax) xmax = temp;
        if (temp<xmin) xmin = temp;
        cin>>temp;
        if (temp>ymax) ymax = temp;
        if (temp<ymin) ymin = temp;
    }
    if (xmax-xmin > ymax-ymin){  
        cout<<((xmax-xmin)*(xmax-xmin));
    }
    else {   
        cout<<((ymax-ymin)*(ymax-ymin));
    }
}