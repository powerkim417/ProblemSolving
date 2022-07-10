#include <iostream>

using namespace std;

// adx + bdy = cd
// adx + aey = af
// y = (cd-af)/(bd-ae)

// aex + bey = ce
// bdx + bey = bf
// x = (ce-bf)/(ae-bd)
int main(void){
    int a, b, c, d, e, f;
    cin>>a>>b>>c>>d>>e>>f;
    cout<<(c*e-b*f)/(a*e-b*d)<<" "<<(c*d-a*f)/(b*d-a*e);
    return 0;
}