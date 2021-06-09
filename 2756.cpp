#include <iostream>

using namespace std;

int score(double x, double y){
    double d2 = x*x + y*y;
    if (d2 <= 9) return 100;
    else if (d2 <= 36) return 80;
    else if (d2 <= 81) return 60;
    else if (d2 <= 144) return 40;
    else if (d2 <= 225) return 20;
    else return 0;
}

int main(void){
    int t;
    cin>>t;
    while (t--){
        int n=0, m=0;
        double x, y;
        for (int i=0 ; i<3 ; i++){
            cin>>x>>y;
            n += score(x, y);
        }
        for (int i=0 ; i<3 ; i++){
            cin>>x>>y;
            m += score(x, y);
        }
        cout<<"SCORE: "<<n<<" to "<<m<<", ";
        if (n==m) cout<<"TIE.\n";
        else cout<<"PLAYER "<<((n>m)?"1":"2")<<" WINS.\n";
    }
    return 0;
}