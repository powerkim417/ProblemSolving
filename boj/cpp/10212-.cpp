#include <iostream>
#include <cstdlib>

using namespace std;

int main(void){
	int* a = new int;
	if ((long long)a%5) cout<<"Yonsei";
	else cout<<"Korea";
    delete a;
	return 0;
}