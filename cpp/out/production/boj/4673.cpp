#include <iostream>

using namespace std;

bool isSelf[10001];

int dn(int n){
    return n + n/10000 + (n/1000)%10 + (n/100)%10 + (n/10)%10 + n%10;
}

void selfCheck(int n){
    int temp = n;
    temp = dn(temp);
    while (temp<=10000){
        isSelf[temp] = false;
        temp = dn(temp);
    }
}

int main(void){
    for (int i=0 ; i<10001 ; i++){
        isSelf[i] = true;
    }

    for (int i=1 ; i<=10000 ; i++){
        // 특정 생성자를 통해 생성되면 그 수에 대해 isSelf는 false.
        selfCheck(i);
    }

    for (int i=1 ; i<=10000 ; i++){
        if (isSelf[i]){
            cout<<i<<endl;
        }
    }
}