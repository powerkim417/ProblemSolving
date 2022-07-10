#include <iostream>
#include <cstring>
using namespace std;
int main(void){
    string size;
    int n;
    while (1){
        cin>>n;
		int joe=0, jean=0, jane=0, james=0, any=0;
        if (n==0) break;
        for (int i=0 ; i<n ; i++){
            cin>>size;
            if (size.length() == 2){ // 숫자사이즈
                int sizenum = (size[0]-'0')*10 + size[1]-'0';
                if (sizenum >= 12) jean++;
                else jane++;
            }
            else { // 글자사이즈
                if (size == "S") james++;
                else if (size == "M" || size == "L") joe++;
                else if (size == "X") any++;
                else jane++;
            }
        }
        cout<<joe<<" "<<jean<<" "<<jane<<" "<<james<<" "<<any<<"\n";
    }
}