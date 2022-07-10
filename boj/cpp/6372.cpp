#include <iostream>

using namespace std;

char i2c(int a){
    if (a<10) return a+'0';
    else return a-10+'A';
}

int c2i(char a){
    if (a>='0' && a<='9') return a-'0';
    else return a-'A'+10;
}

int cc2i(char a, char b){
    return c2i(a)*16 + c2i(b);
}

int main(void){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    string mem;
    while (cin>>mem){
        // 종료 조건
        if (mem[0]=='8') break;
        char a,b,temp;
        int pc = 0;
        bool stop = false;
        char x, y;
        while (!stop){
            // cout<<"inst: "<<(mem[pc])<<"\n";
            switch (mem[pc++]){
                case '0':
                // a = c2i(mem[cc2i(mem[pc++], mem[pc++])]); // 이렇게 하면 오류나네.. 증감연산자가 증가하는게 모두에 반영되는듯
                a = c2i(mem[cc2i(mem[pc], mem[pc+1])]);
                pc += 2;
                break;
                
                case '1':
                mem[cc2i(mem[pc], mem[pc+1])] = i2c(a);
                pc += 2;
                break;
            
                case '2':
                temp = a;
                a = b;
                b = temp;
                break;

                case '3':
                temp = a+b;
                a = temp%16;
                b = temp/16;
                break;

                case '4':
                a = (a+1)%16;
                break;

                case '5':
                a = (a+15)%16;
                break;

                case '6':
                if (a==0) pc = cc2i(mem[pc], mem[pc+1]);
                else pc += 2;
                break;

                case '7':
                pc = cc2i(mem[pc], mem[pc+1]);
                break;

                case '8':
                stop = true;
                break;
            }
        }
        for (int i=0 ; i<256 ; i++){
            cout<<mem[i];
        }
        cout<<"\n";
    }
    
    return 0;
}