#include <iostream>
#include <vector>

using namespace std;

// 투 포인터 풀이

int main(void){
    int g;
    cin>>g;
    vector<int> weights;
    // 1, 2, ..., n 까지의 수가 있을 때
    // 두 포인터 a=1, b=2에서 시작.
    // 한편, g=b^2-a^2=(b+a)(b-a)<=100000 에서 b가 가장 큰 경우는 b+a가 최대, b-a가 최소여야 한다.
    // ex) 10000=10000*1 = 100*100일 때를 생각하면 됨
    // 따라서 b+a=100000, b-a=1인데, 이는 자연수로 존재하지 않으므로 b+a=99999, b-a=1인 경우. 즉 b가 최대인 경우: n=50000
    // b^2-a^2가 g보다 작다면 b++, g보다 크다면 a++.(즉, 현재 몸무게는 b)
    // b가 50000에 도달할 때까지!
    long long int a=1, b=2, candidate;
    while (b<=50000){
        candidate = b*b-a*a;
        // cout<<a<<" "<<b<<" "<<candidate<<"\n";
        // 어쩌다가 a=b가 된 경우는 candidate<g가 되어 b가 다시 앞지르므로 걱정할 필요 없음
        if (candidate<g) b++;
        else if (candidate>g) a++;
        else { // 답인 경우. 이 경우는 a++, b++ 둘 중 아무거나 해도 됨
        // a . . . . b 에서 답인 경우, a는 더 이상 답에 속할 일이 없으므로 a를 더 볼 필요가 없으니 a++해도 되는 것은 자명.
        // 같은 아이디어로 b도 생각하면 됨
            weights.push_back(b);
            // a++;
            b++;
        }
    }

    int w_size = weights.size();
    if (w_size==0) cout<<"-1";
    else {
        for (int i=0 ; i<w_size ; i++){
            cout<<weights[i]<<"\n";
        }
    }
    return 0;
}