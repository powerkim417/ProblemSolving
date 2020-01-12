#include <iostream>

using namespace std;

int abs(int x){
    if (x<0) return -x;
    else return x;
}

int main(void){
    int br, bc, dr, dc, jr, jc;
    cin>>br>>bc>>dr>>dc>>jr>>jc;
    int brd = abs(br-jr), bcd = abs(bc-jc);
    int b;
    if (brd > bcd){
        b = bcd + (brd-bcd); // = brd
    }
    else {
        b = brd + (bcd-brd); // = bcd
    }
    int d = abs(dr-jr) + abs(dc-jc);
    if (b<d) cout<<"bessie";
    else if (b>d) cout<<"daisy";
    else cout<<"tie";
}