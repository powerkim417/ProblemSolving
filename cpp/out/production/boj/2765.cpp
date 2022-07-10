#include <iostream>

using namespace std;

int main(void){
    int r;
    double d, t;
    int tc = 1;
    while (1){
        cin>>d>>r>>t;
        if (r==0) break;
        cout<<"Trip #"<<(tc++)<<": ";
        cout<<fixed;
        cout.precision(2);
        double dist = d*(3.1415927)*r/(5280*12);
        cout<<dist<<" "<<(dist/t)*3600<<"\n";
    }
    return 0;
}