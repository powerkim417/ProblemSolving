#include <iostream>
#include <map>

using namespace std;

int a, p;
map<int, int> visited; // D[1] = A일 때 visited[A] = 1

int power(int num){
    int ret = 1;
    for (int i=0 ; i<p ; i++) ret *= num;
    return ret;
}

int calc(int num){
    int ret = 0;
    while (num>0){
        ret += power(num%10);
        num /= 10;
    }
    return ret;
}

int main(void){
    cin>>a>>p;
    int seq = 1;
    visited[a] = seq;
    while (1){
        seq++;
        a = calc(a);
        // cout<<seq<<" "<<a<<"\n";
        if (visited[a] != 0){
            // visited[a]가 반복되는 수열의 시작.
            cout<<(visited[a]-1);
            return 0;
        }
        visited[a] = seq;
    }
    return 0;
}