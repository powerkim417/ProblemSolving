#include <iostream>
#include <stack>

using namespace std;

int main(void){
	int N;
	cin>>N;
	int cnt = 0;
	string str;
	for (int t=0 ; t<N ; t++){
		cin>>str;
		int len = str.length();
		stack<int> s;
		for (int i=0 ; i<len ; i++){
			if (s.empty()) s.push(str[i]);
			else if (str[i] == s.top()) s.pop();
			else s.push(str[i]);
		}
		if (s.empty()) cnt++;
	}
	cout<<cnt;
}