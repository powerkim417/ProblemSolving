#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool has_no_zero(int num){
    for (int i=0 ; i<4 ; i++){
        if (num%10 == 0) return false;
        num /= 10;
    }
    return true;
}

bool is_ascending(int num){
    for (int i=0 ; i<3 ; i++){
        if ((num/10)%10 > num%10) return false;
        num /= 10;
    }
    return true;
}

int find_clock(int num){
    int ret = num;
    for (int i=0 ; i<3 ; i++){
        int temp = (num%10)*1000 + num/10;
        if (temp < ret) ret = temp;
        num = temp;
    }
    return ret;
}

// 모든 십자를 다 만들어서 isClock으로 기록해도 되지만, find_clock 함수를 활용한 것이 더 센스있음
// 시계수: 0이 없고 오름차순인 수
int main(void){
    int num = 0, temp;
    for (int i=0 ; i<4 ; i++){
        cin>>temp;
        num *= 10;
        num += temp;
    }
    num = find_clock(num);
    // num = 입력된 카드의 시계수
    int answer = 0;
    for (int i=1111 ; i<=num ; i++){
        if (i!=find_clock(i)) continue; // !!!! find_clock 함수 활용이 포인트
        answer++;
    }
    cout<<answer;
    return 0;
}