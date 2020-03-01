#include <iostream>
#include <algorithm>
#include <string.h>
#include <math.h>

using namespace std;

struct bign{
	int d[1000];
	int len;
	bign(){
		memset(d, 0, sizeof(d));
	}
};


// struct bign{
// 	int d[1000];
// 	int len;
// 	bign(){
// 		memset(d, 0, sizeof(d));
// 		len = 0;
// 	}
// };

bign change(string str){
	bign b;
	b.len = str.length();
	for(int i = 0; i < b.len; i ++){
		b.d[i] = str[str.length() - i - 1] - '0';
	}
	return b;
}

bign add(bign a, bign b){
	bign c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i ++){
		int sum = a.d[i] + b.d[i] + carry;
		c.d[c.len ++] = sum%10;
		carry = sum/10;
	}
	if(carry){
		c.d[c.len ++] = carry;
	}
	return c;
}



int main(int argc, char const *argv[])
{
	
	return 0;
}