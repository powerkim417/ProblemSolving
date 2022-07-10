#include <iostream>
#include <string>

using namespace std;

string code[10] = {"063", "010", "093", "079", "106",
                    "103", "119", "011", "127", "107"};

int decode(string str){
    for (int i=0 ; i<=9 ; i++){
        if (str == code[i]){
            return i;
        }
    }
}

string encode(int i){
    return code[i];
}

int main(void){
    string s;
    while (1){
        cin>>s;
        if (s == "BYE") return 0;
        cout<<s;
        int len = s.length();
        int plus;
        for (int i=0 ; i<len ; i++){
            if (s[i]=='+') {
                plus = i; // + 기호의 인덱스
                break;
            }
        }
        string a = s.substr(0, plus); // 0 ~ plus-1
        string b = s.substr(plus+1, len-plus-2); // plus+1 ~ len-2
        int len_a = a.length();
        int len_b = b.length();
        int num_a = 0, num_b = 0;
        for (int i=0 ; i<len_a ; i = i+3){
            num_a *= 10;
            num_a += decode(a.substr(i, 3));
        }
        for (int i=0 ; i<len_b ; i = i+3){
            num_b *= 10;
            num_b += decode(b.substr(i, 3));
        }
        int sum = num_a + num_b;
        string answer = "";
        while (sum>0){
            answer = encode(sum%10) + answer;
            sum /= 10;
        }
        cout<<answer<<"\n";
    }
}
