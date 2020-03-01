#include <iostream>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct bign{
	int d[1000];
	int len;
	bign(){
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

bign change(string str){
	bign b;
	b.len = str.length();
	for(int i = 0; i < str.length(); i ++){
		b.d[i] = str[b.len - i - 1] - '0';
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
	if(carry != 0)
		c.d[c.len ++] = carry;
	return c;


}

/*
Sample Input 1:
67 3
Sample Output 1:
484
2
Sample Input 2:
69 3
Sample Output 2:
1353
3
*/

bool is_Palindromic(bign b){
	for(int i = 0; i < b.len/2; i ++){
		if(b.d[i] != b.d[b.len - i - 1])
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	string str;
	int k;
	cin >> str;
	cin >> k;
	bign b = change(str);
	if(is_Palindromic(b)){
		cout << str << endl << 0;
		return 0;
	}
	for(int i = 1; i <= k; i ++){
		bign temp;
		temp.len = b.len;
		for(int j = 0; j < temp.len; j ++)
			temp.d[j] = b.d[b.len - j - 1];
		b = add(temp, b);
		
		if(is_Palindromic(b)){
			for(int j = b.len - 1; j >= 0; j --)
				cout << b.d[j];
			cout << endl << i;
			return 0;
		}
	}
	for(int j = b.len - 1; j >= 0; j --)
		cout << b.d[j];
	cout << endl << k;
/*	cout << b.len << endl;
	for(int i = 0; i < b.len; i ++)
		cout << b.d[i];*/

	return 0;
}