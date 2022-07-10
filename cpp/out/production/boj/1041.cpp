#include <iostream>

using namespace std;

int dice[6];
// n=1일 때 답은 전체 면에서 가장 큰거 하나 뺀 것

// n^3 (n>=2)개를 쌓을 경우
// 면이 보이는 주사위: n^2 + (n-1)*(n^2-(n-2)^2) = 5n^2-8n+4
// 3면이 보이는 주사위: 4
// 1면이 보이는 주사위: (n-2)^2 + 4*(n-2)(n-1) = 5n^2-16n+12
// 2면이 보이는 주사위: 8n-12

// 2면의 경우 6^2로 비교하되, i,j가 마주보는 면인 경우 제외
// 3면의 경우 6^3으로 비교하되, i,j,k 중 마주보는 면이 있는 경우 제외
// 인풋 상 두 인덱스의 합이 5인 경우가 마주보는 면이다
int min_two(){ // 가능한 2면의 합 중 최소
    int ret = 101;
    for (int i=0 ; i<6 ; i++){
        for (int j=0 ; j<6 ; j++){
            if (i==j) continue;
            if (i+j==5) continue;
            if (dice[i]+dice[j] < ret) ret = dice[i]+dice[j];
        }
    }
    return ret;
}

int min_three(){ // 가능한 3면의 합 중 최소
    int ret = 151;
    for (int i=0 ; i<6 ; i++){
        for (int j=0 ; j<6 ; j++){
            if (i==j) continue;
            if (i+j==5) continue;
            for (int k=0 ; k<6 ; k++){
                if (i==k || j==k) continue;
                if (i+k==5 || j+k==5) continue;
                if (dice[i]+dice[j]+dice[k] < ret) ret = dice[i]+dice[j]+dice[k];
            }
        }
    }
    return ret;
}

int main(void){
    int n; cin>>n;
    int smallest = 51;
    for (int i=0 ; i<6 ; i++) {
        cin>>dice[i];
        if (smallest > dice[i]) smallest = dice[i];
    }
    if (n==1){
        int biggest = -1;
        int sum = 0;
        for (int i=0 ; i<6 ; i++) {
            sum += dice[i];
            if (dice[i]>biggest) biggest = dice[i];
        }
        cout<<(sum-biggest);
        return 0;
    }
    long long one = (5LL*n*n - 16*n + 12)*smallest;
    long long two = (8LL*n - 12)*min_two();
    long long three = 4LL*min_three();
    // cout<<one<<" "<<two<<" "<<three<<"\n";
    cout<<(one+two+three);
    return 0;
}