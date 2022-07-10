#include <iostream>

using namespace std;

// 수영장 넓이가 31250이므로
// 반띵되는 삼각형의 넓이는 15625여야 함
int main(void){
    double ix, iy;
    double ox, oy;
    cin>>ix>>iy;
    if (ix == 0){ // |
        if (iy <= 125.5){ // 빗변에 내려야 함
            // (250-iy)*ox = 31250
            // ox + oy = 250
            ox = 31250 / (250 - iy);
            oy = 250 - ox;
        }
        else { // 밑변에 내려야 함
            // iy*ox = 31250
            ox = 31250 / iy;
            oy = 0; 
        }
    }
    else if (iy == 0){ // ㅡ
        if (ix <= 125.5){ // 빗변에 내려야 함
            // (250-ix)*oy = 31250
            // ox + oy = 250
            oy = 31250 / (250 - ix);
            ox = 250 - oy;
        }
        else { // 높이에 내려야 함
            // ix*oy = 31250
            ox = 0;
            oy = 31250 / ix;
        }
    }
    else { // 빗변
        if (ix <= 125.5){ // 밑변에 내려야 함
            // (250-ox)*iy = 31250
            ox = 250 - (31250 / iy); 
            oy = 0;
        }
        else { // 높이에 내려야 함
            // (250-oy)*ix = 31250
            ox = 0;
            oy = 250 - (31250 / ix); 
        }
    }
    cout<<fixed;
    cout.precision(2);
    cout<<ox<<" "<<oy;
    return 0;
}