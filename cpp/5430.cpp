#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

vector<string> tokenize(string s){
    vector<string> ret;
    stringstream ss(s);
    string token;
    while (getline(ss, token, ',')) ret.push_back(token);
    return ret;
}

int s2i(string s){
    int ret = 0;
    for (char c: s){
        if (c=='[' || c==']') continue;
        ret *= 10;
        ret += c-'0';
        
    }
    return ret;
}

// tokenize된걸 바로 갖다 쓸 예정이므로 callbyref 안되는듯?
deque<int> parse_s2i(vector<string> vs){
    deque<int> ret;
    for (string s: vs){
        int num = s2i(s);
        if (num != 0) ret.push_back(num);
    }
    return ret;
}

// reverse가 O(n)이므로 직접 돌리지 말고,
// flag로 돌린 여부 체크하면서 앞 또는 뒤를 빼주도록 하면 됨

// reverse도 사실상 O(1)로 확인중이고, D도 deque에서 O(1)로 실행되므로 시간 초과 해결
int main(void){
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    string cmd, arrstr;
    int n;
    deque<int> arr;
    bool reversed, error;
    while (t--){
        reversed = false;
        error = false;
        cin>>cmd>>n>>arrstr;
        arr = parse_s2i(tokenize(arrstr));
        for (char c: cmd){
            if (c=='R') reversed = !reversed;
            else {
                if (arr.size()==0) {
                    error = true;
                    break;
                }
                if (reversed) arr.pop_back();
                else arr.pop_front();
            }
        }
        if (error){
            cout<<"error\n";
            continue;
        }
        // 뒤집혀 있는 경우 출력 전에 뒤집는거 잊지 말것
        if (reversed) reverse(arr.begin(), arr.end());
        cout<<"[";
        for (int i=0 ; i<arr.size() ; i++){
            if (i != 0) cout<<",";
            cout<<arr[i];
        }
        cout<<"]\n";
    }
    return 0;
}