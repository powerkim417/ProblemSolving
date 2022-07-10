#include <iostream>

using namespace std;

int gcd(int a, int b){
    int temp;
    if (b>a){
        temp = b;
        b = a;
        a = temp;
    }
    // a>=b
    if (b==0) return a;
    else return gcd(b, a%b);
}

int main(void){
    int t;
    cin>>t;
    int n;
    int num[100];
    for (int tc=0 ; tc<t ; tc++){
        cin>>n;
        for (int i=0 ; i<n ; i++){
            cin>>num[i];
        }
        long long answer = 0;
        // 최악의 경우 100개 tc 모두 100개의 999999를 처리할 때
        // answer는 (99*100/2)*999999 = 4,949,995,050. 이는 int 범위를 넘어섬
        for (int i=0 ; i<n ; i++){
            for (int j=i+1 ; j<n ; j++){
                answer += gcd(num[i], num[j]);
            }
        }
        cout<<answer<<"\n";
    }
    return 0;
}