#include <iostream>

using namespace std;

int main(void){
    int T;
    cin>>T;
    for (int t=0 ; t<T ; t++){
        int a,b,price=0;
        cin>>a>>b;
        if (a==0) price += 0;
        else if (a==1) price += 500;
        else if (a<=3) price += 300;
        else if (a<=6) price += 200;
        else if (a<=10) price += 50;
        else if (a<=15) price += 30;
        else if (a<=21) price += 10;
        if (b==0) price += 0;
        else if (b==1) price += 512;
        else if (b<=3) price += 256;
        else if (b<=7) price += 128;
        else if (b<=15) price += 64;
        else if (b<=31) price += 32;
        cout<<price*10000<<"\n";
    }
}