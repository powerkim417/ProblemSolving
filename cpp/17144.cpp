#include <iostream>

using namespace std;
int main(void){
    int r,c,t;
    cin>>r>>c>>t;
    int oldmap[r][c], newmap[r][c];
    int ac_i, ac_j;
    for (int i=0 ; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            cin>>oldmap[i][j];
            newmap[i][j] = oldmap[i][j];
            if (oldmap[i][j] == -1){
                ac_i = i;
                ac_j = j; // 공기청정기의 아래 좌표가 최종 저장됨
                newmap[i][j] = 0;
            }
        }
    }
    for (int loop=1 ; loop<=t ; loop++){
        // 1. 확산
        for (int i=0 ; i<r ; i++){
            for (int j=0 ; j<c ; j++){
                if (i-1>=0){
                    if ((j == ac_j) && ((i-1==ac_i)||(i-1==ac_i-1))){}
                    else {
                        newmap[i-1][j] += oldmap[i][j]/5;
                        newmap[i][j] -= oldmap[i][j]/5;
                    }
                }
                if (i+1<r){
                    if ((j == ac_j) && ((i+1==ac_i)||(i+1==ac_i-1))){}
                    else {
                        newmap[i+1][j] += oldmap[i][j]/5;
                        newmap[i][j] -= oldmap[i][j]/5;
                    }
                }
                if (j-1>=0){
                    if ((j-1 == ac_j) && ((i==ac_i)||(i==ac_i-1))){}
                    else {
                        newmap[i][j-1] += oldmap[i][j]/5;
                        newmap[i][j] -= oldmap[i][j]/5;
                    }
                }
                if (j+1<c){
                    if ((j+1 == ac_j) && ((i==ac_i)||(i==ac_i-1))){}
                    else {
                        newmap[i][j+1] += oldmap[i][j]/5;
                        newmap[i][j] -= oldmap[i][j]/5;
                    }
                }
            }
        }
            // new->old
            cout<<"time "<<loop<<" after diffusion"<<endl;
        for (int i=0 ; i<r ; i++){
            for (int j=0 ; j<c ; j++){
                oldmap[i][j] = newmap[i][j];
            	cout<<oldmap[i][j]<<" ";
            }
        	cout<<endl;
        }
        // 2. 순환
            // 위
        for (int i=0 ; i<=ac_i-1 ; i++){ // 0 1 2
            for (int j=0 ; j<c ; j++){
                if (i==0 && j!=c-1) newmap[i][j] = oldmap[i][j+1]; // <-
                if (j==0 && i!=0) newmap[i][j] = oldmap[i-1][j]; // v
                if (i==ac_i-1 && j!=0) newmap[i][j] = oldmap[i][j-1]; // ->
                if (j==c-1 && i!=ac_i-1) newmap[i][j] = oldmap[i+1][j]; // ^
                if (i==ac_i-1 && j==ac_j) newmap[i][j] = 0;
            }
        }
            // 아래
        for (int i=ac_i ; i<r ; i++){ // 3 4 5 6
            for (int j=0 ; j<c ; j++){
                if (i==r-1 && j!=c-1) newmap[i][j] = oldmap[i][j+1]; // <-
                if (j==c-1 && i!=ac_i) newmap[i][j] = oldmap[i-1][j]; // v
                if (i==ac_i && j!=0) newmap[i][j] = oldmap[i][j-1]; // ->
                if (j==0 && i!=r-1) newmap[i][j] = oldmap[i+1][j]; // ^
                if (i==ac_i && j==ac_j) newmap[i][j] = 0;
            }
        }
        
            // new->old
            cout<<"time "<<loop<<" after circum"<<endl;
        for (int i=0 ; i<r ; i++){
            for (int j=0 ; j<c ; j++){
                oldmap[i][j] = newmap[i][j];
            	cout<<oldmap[i][j]<<" ";
            }
        	cout<<endl;
        }
    }
    int sum = 0;
    for (int i=0 ; i<r ; i++){
        for (int j=0 ; j<c ; j++){
            sum += oldmap[i][j];
        }
    }
    cout<<sum;
}