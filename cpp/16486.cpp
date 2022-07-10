#include <cstdio>
#include <iomanip>

using namespace std;

int main(void){
    int d1, d2;
    scanf("%d %d", &d1, &d2);
    double answer = 2*d1 + 2*3.141592*d2;
    printf("%.6f", answer);
}