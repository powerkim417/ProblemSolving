#include <iostream>

using namespace std;

int len = 0;
int powerten = 1;

void rotate(int& n){
    int one = n%10;
    n /= 10;
    n += one*powerten;
}

int main(void){
    int n; cin>>n;
    int temp = n;
    while (temp>0){
        len++; temp /= 10;
        powerten *= 10;
    }
    powerten /= 10;
    long long answer = 0;
    for (int i=0 ; i<len ; i++){
        answer += n;
        rotate(n);
    }
    cout<<answer;
    return 0;
}