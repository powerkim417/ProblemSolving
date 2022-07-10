#include <iostream>

using namespace std;

int main(void){
    int score[6];
    while (1){
        bool finish = true;
        int M = -1, m = 11;
        double sum = 0;
        for (int i=0 ; i<6 ; i++){
            cin>>score[i];
            M = (score[i]>M)?score[i]:M;
            m = (score[i]<m)?score[i]:m;
            sum += score[i];
            if (score[i] != 0) finish = false;
        }
        if (finish) break;
        sum -= M+m;
        sum /= 4;
        cout<<sum<<"\n";
        
    }
    return 0;
}