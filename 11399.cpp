#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    int n;
    cin>>n;
    vector<int> p;
    int temp;
    for (int i=0 ; i<n ; i++) {
        cin>>temp;
        p.push_back(temp);
    }
    sort(p.begin(), p.end());
    /* 1 2 3 3 4 순서대로 설 경우
       1
       1 2
       1 2 3
       1 2 3 3
       1 2 3 3 4 의 시간이 소요된다. 이들의 합이 정답. */
    int sum = 0;
    for (int i=0 ; i<n ; i++){
        sum +=p[i]*(n-i);
    }
    cout<<sum;


}