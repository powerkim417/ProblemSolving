#include <iostream>

using namespace std;

int max(int a, int b, int c){
    int temp = (a>b)?a:b;
    return (temp>c)?temp:c;
}

int main(void){
    int r, n;
    string p, f[50];
    cin>>r>>p>>n;
    int score = 0;
    for (int i=0 ; i<n ; i++) {
        cin>>f[i];
        for (int j=0 ; j<r ; j++){
            if (p[j]==f[i][j]) score += 1;
            else {
                if (p[j]=='S' && f[i][j]=='P') score += 2;
                if (p[j]=='P' && f[i][j]=='R') score += 2;
                if (p[j]=='R' && f[i][j]=='S') score += 2;
            }
        }
    }
    int mx = 0;
    for (int i=0 ; i<r ; i++){
        int rock=0, pap=0, sci=0;
        for (int j=0 ; j<n ; j++){
            switch (f[j][i]){
                case 'R':
                rock++;
                break;
                case 'P':
                pap++;
                break;
                case 'S':
                sci++;
                break;
            }
        }
        mx += max(rock*2 + pap, pap*2 + sci, sci*2 + rock);
    }
    cout<<score<<"\n"<<mx;
    return 0;
}