#include <iostream>

using namespace std;

int n;
char map[50][50];

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

int cnt(){
    int ret = 0;
    int temp = 1;
    for (int i=0 ; i<n ; i++){
        for (int j=1 ; j<=n ; j++){
            if (j==n || map[i][j] != map[i][j-1]){
                if (temp > ret) ret = temp;
                temp = 1;
            }
            else temp++;
        }
    }
    temp = 1;
    for (int j=0 ; j<n ; j++){
        for (int i=1 ; i<=n ; i++){
            if (i==n || map[i][j] != map[i-1][j]){
                if (temp > ret) ret = temp;
                temp = 1;
            }
            else temp++;
        }
    }
    return ret;
}

// cnt() 가 N^2고, 보드의 모든 경우의 수를 따지는게 N^2
// N<=50이므로 N^4도 가능
int main(void){
    cin>>n;
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            cin>>map[i][j];
        }
    }
    // 처음 최대 갯수 확인
    int answer = cnt();
    int temp;
    // 자기 오른쪽 또는 밑과 교환해보기
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j<n ; j++){
            if (j+1<n){
                swap(map[i][j], map[i][j+1]);
                temp = cnt();
                if (answer < temp) answer = temp;
                swap(map[i][j], map[i][j+1]);
            }
            if (i+1<n){
                swap(map[i][j], map[i+1][j]);
                temp = cnt();
                if (answer < temp) answer = temp;
                swap(map[i][j], map[i+1][j]);
            }
        }
    }
    cout<<answer;
    return 0;
}