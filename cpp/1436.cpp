#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int cnt = 0;
    int i = 0;
    while (1){ // 각 숫자
        int cont_six = 0;
        i++;
        int temp = i;
        while (temp>0) {
            if (temp%10 == 6)
                cont_six++;
            else 
                cont_six = 0;
            if (cont_six == 3){
                cnt++;
                // cout<<i<<endl;
                if (cnt == n){
                    cout<<i;
                    return 0;
                }
            }
            temp /= 10;
        }
    }
}