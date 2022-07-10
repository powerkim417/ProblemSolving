#include <iostream>

using namespace std;

int min(int x, int y){
    return (x>y)?y:x;
}

int abs(int x){
    return (x>0)?x:(-x);
}

int main(void){
    int x, y, p1, p2;
    cin>>x>>y>>p1>>p2;
    // (x의 배수)+p1 이 (y의 배수)+p2 꼴인지 검사
    // 단, x와 y가 서로 약배수 관계이고, 둘 중 약수를 g라고 둘 때 |p1-p2|가 g의 배수가 아닌 경우는 닿지 못한다.
    if ((x%y==0 || y%x==0) && abs(p1-p2)%min(x,y)!=0) {
        cout<<"-1";
        return 0;
    }
    else {
        if (p1<p2){
            int num = p1;
            while (1){
                if (num<p2){
                    num += x;
                    continue;
                }
                if ((num-p2)%y==0) break;
                else num += x;
            }
            cout<<num;
        }
        else {
            int num = p2;
            while (1){
                if (num<p1){
                    num += y;
                    continue;
                }
                if ((num-p1)%x==0) break;
                else num += y;
            }
            cout<<num;
        }
        return 0;
    }
}