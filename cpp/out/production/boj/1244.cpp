#include <iostream>

using namespace std;

bool flag[101]; // 1~n 까지 사용

int main(void){
    int n;
    cin>>n;
    for (int i=1 ; i<=n ; i++){
        cin>>flag[i];
    }
    int m;
    cin>>m;
    int sex, num;
    for (int i=0 ; i<m ; i++){
        cin>>sex>>num;
        if (sex==1){ // 남학생
            for (int j=1 ; j<=n ; j++){
                if (j%num==0) flag[j] = !flag[j];
            }
        }
        else { // 여학생
            int size = 1;
            flag[num] = !flag[num];
            while (1){
                if (num-size<1 || num+size>n) break;
                if (flag[num-size] != flag[num+size]) break;
                flag[num-size] = !flag[num-size];
                flag[num+size] = !flag[num+size];
                size++;
            }
        }
    }
    for (int i=1 ; i<=n ; i++){
        cout<<(int)flag[i]<<" ";
        if (i%20 == 0) cout<<"\n";
    }

}