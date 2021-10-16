#include <iostream>

using namespace std;

int reg[10] = {}, ram[1000];

int main(void){
    int i=0, temp;
    while (cin>>temp) ram[i++] = temp;
    int pc = 0;
    int cnt = 0;
    bool halt = false;
    int inst, x, y;
    while (!halt){
        inst = ram[pc]/100;
        x = (ram[pc]/10)%10;
        y = ram[pc]%10;
        cnt++;
        pc++; // pc는 다른데로 이미 가있는 상태에서 inst=0일 때 지시하는 주소로 가게 됨
        switch (inst){
            case 1:
            halt = true;
            break;
            
            case 2:
            reg[x] = y;
            break;

            case 3:
            reg[x] += y;
            reg[x] %= 1000;
            break;

            case 4:
            reg[x] *= y;
            reg[x] %= 1000;
            break;

            case 5:
            reg[x] = reg[y];
            break;

            case 6:
            reg[x] += reg[y];
            reg[x] %= 1000;
            break;

            case 7:
            reg[x] *= reg[y];
            reg[x] %= 1000;
            break;

            case 8:
            reg[x] = ram[reg[y]];
            break;

            case 9:
            ram[reg[y]] = reg[x];
            break;

            case 0:
            if (reg[y]!=0) pc = reg[x];
            break;
        }
    }
    cout<<cnt;
    return 0;
}