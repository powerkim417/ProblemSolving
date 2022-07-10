#include <iostream>

using namespace std;

int main(void){
    int t;
    cin>>t;
    double igd[5];
    int topp[4];
    while (t--){
        for (int i=0 ; i<5 ; i++) cin>>igd[i];
        igd[0] /= 8;
        igd[1] /= 8;
        igd[2] /= 4;
        igd[4] /= 9;
        // for (int i=0 ; i<5 ; i++) cout<<igd[i]<<" ";
        // cout<<"\n";

        double dough = 2147483647;
        for (int i=0 ; i<5 ; i++) {
            if (dough>igd[i]) dough = igd[i];
        }
        dough = (int)(16*dough);
        // cout<<dough<<"\n";

        for (int i=0 ; i<4 ; i++) cin>>topp[i];
        topp[1] /= 30;
        topp[2] /= 25;
        topp[3] /= 10;
        // for (int i=0 ; i<4 ; i++) cout<<topp[i]<<" ";
        // cout<<"\n";

        int toppsum = topp[0] + topp[1] + topp[2] + topp[3];
        cout<<(int)((dough>toppsum)?toppsum:dough)<<"\n";
    }
    return 0;
}