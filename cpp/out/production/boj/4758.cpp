#include <iostream>

using namespace std;

int main(void){
    double v, w, s;
    bool flag;
    while (cin>>v>>w>>s){
        if (v==0 && w==0 && s==0) break;
        flag = false;
        if (v<=4.5 && w>=150 && s>=200) {
            cout<<"Wide Receiver ";
            flag = true;
        }
        if (v<=6.0 && w>=300 && s>=500) {
            cout<<"Lineman ";
            flag = true;
        }
        if (v<=5.0 && w>=200 && s>=300) {
            cout<<"Quarterback ";
            flag = true;
        }
        if (!flag) cout<<"No positions";
        cout<<"\n";
    }
    return 0;
}