#include <iostream>

using namespace std;

int main(void){
    int n;
    cin>>n;
    string name;
    cin>>name;
    int n_len = name.length();
    int cnt = 0;
    string sign;
    for (int t=0 ; t<n ; t++){
        cin>>sign;
        // cout<<"Sign: "<<sign<<"\n";
        int s_len = sign.length();
        bool found = false;
        for (int i=0 ; i<s_len ; i++){
            if (sign[i] != name[0]) continue;
            // 첫글자가 일치한 경우!

            // j가 들어갔을 때의 name 틀의 길이 = n_len + (j-1)*(n_len-1) = j*(n_len-1) + 1
            for (int j=1 ; j*(n_len-1)+1<=s_len-i ; j++){ // j: name의 글자간 간격
                found = true; // (i, j) 조건에서 true로 시작. 어긋날 때 false로 바뀜.
                for (int k=1 ; k<n_len ; k++){
                    if (i+j*k >= s_len || sign[i+j*k] != name[k]) { // 나머지가 일치하지 않으면 넘김
                        // cout<<i<<" "<<j<<" fail at k="<<k<<endl;
                        found = false;
                        break;
                    }
                }
                if (found) {
                    // cout<<"Found location: "<<i<<" "<<j<<"\n";
                    break;
                }
            }
            if (found) { // 찾은 경우 sign을 더 훑어보지 않고 탈추
                cnt++;
                break;
            }
        }
    }
    cout<<cnt;
}