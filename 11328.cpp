#include <iostream>

using namespace std;

string a,b;
int cnt_a[26], cnt_b[26];

int main(void){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    for (int t=0 ; t<n ; t++){
        cin>>a>>b;
        for (int i=0 ; i<26 ; i++){
            cnt_a[i] = 0;
            cnt_b[i] = 0;
        }
        int len_a = a.length();
        int len_b = b.length();
        for (int i=0 ; i<len_a ; i++) cnt_a[a[i]-'a']++;
        for (int i=0 ; i<len_b ; i++) cnt_b[b[i]-'a']++;
        bool flag = true;
        for (int i=0 ; i<26 ; i++){
            if (cnt_a[i] != cnt_b[i]) {
                flag = false;
                break;
            }
        }
        if (flag) cout<<"Possible\n";
        else cout<<"Impossible\n";
    }
}