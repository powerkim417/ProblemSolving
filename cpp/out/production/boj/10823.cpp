#include <iostream>

using namespace std;

int main(void){
    char c;
    int sum = 0, temp = 0;    
    while (1){
        c = getchar();
        if (c == '\n') continue;
        if (c == EOF) break;
        if (c == ','){
            sum += temp;
            temp = 0;
        }
        else {
            temp *= 10;
            temp += c-'0';
        }
    }
    sum += temp;
    cout<<sum;
}