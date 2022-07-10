#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i=0 ; i<n ; i++){
        scanf("%d", &a[i]);
    }
    int temp;
    char op;
    vector<int> ops;
    for (int i=0 ; i<4 ; i++){
        scanf("%d", &temp);
        for (int j=0 ; j<temp ; j++){
            ops.push_back(i);
        }
    }
    int max = -1000000000;
    int min = 1000000000;
    do {
        int answer = a[0];
        for (int i=0 ; i<n-1 ; i++){
           op = ops.at(i); // 0+, 1-, 2*, 3/
           if (op==0) answer += a[i+1];
           else if (op==1) answer -= a[i+1];
           else if (op==2) answer *= a[i+1];
           else if (op==3) answer /= a[i+1];
        }
        if (answer > max) max = answer;
        if (answer < min) min = answer;
    } while (next_permutation(ops.begin(), ops.end()));
    printf("%d\n%d", max, min);
}