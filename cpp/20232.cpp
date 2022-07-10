#include <iostream>

using namespace std;

int main(void){
    int y;
    cin>>y;
    if (y<=1995) cout<<"ITMO";
    else if (y<=1997) cout<<"SPbSU";
    else if (y<=1999) cout<<"ITMO";
    else if (y<=2000) cout<<"SPbSU";
    else if (y<=2005) cout<<"ITMO";
    else if (y<=2006) cout<<"PetrSU, ITMO";
    else if (y<=2008) cout<<"SPbSU";
    else if (y<=2012) cout<<"ITMO";
    else if (y<=2013) cout<<"SPbSU";
    else if (y<=2017) cout<<"ITMO";
    else if (y<=2018) cout<<"SPbSU";
    else if (y<=2019) cout<<"ITMO";
    return 0;
}