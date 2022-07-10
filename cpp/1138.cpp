#include <iostream>
#include <vector>

using namespace std;

int main(void){
    int n;
    cin>>n;
    int bigger[n+1];
    vector<int> seat;
    for (int i=1 ; i<=n ; i++){
        cin>>bigger[i];
    }
    /* 큰 사람부터 자리를 배정해주면 됨.
    현재 배정되는 사람의 경우 이미 자리가 배정된 사람들은
    전부 다 자신보다 큰 사람들이므로
    기억하는 수의 인덱스만큼 오른쪽으로 가서 자리하면 된다.
    ex) 키가 1인 사람이 기억하는 수가 2이고,
    4 2 3 인 경우 인덱스 2 위치에 끼워넣어서 4 2 1 3이 되도록 한다. */
    for (int i=n ; i>=1 ; i--){
        seat.insert(seat.begin()+bigger[i], i);
    }
    for (int i=0 ; i<n ; i++){
        cout<<seat[i]<<" ";
    }
}