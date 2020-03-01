/*

Sample Input 1:
97152
Sample Output 1:
97152 + 25179 = 122331
122331 + 133221 = 255552
255552 is a palindromic number.
Sample Input 2:
196
Sample Output 2:
196 + 691 = 887
887 + 788 = 1675
1675 + 5761 = 7436
7436 + 6347 = 13783
13783 + 38731 = 52514
52514 + 41525 = 94039
94039 + 93049 = 187088
187088 + 880781 = 1067869
1067869 + 9687601 = 10755470
10755470 + 07455701 = 18211171
Not found in 10 iterations.

*/
//应该是因为溢出，最后一个测试点不能通过
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

int StoI(string str){
	int digit = 0;
	for(int i = 0; i < str.size(); i ++){
		digit += (str[i] - '0') * floor(pow(10, str.size() - i - 1));
	}
	return digit;
}

string itos(int digit){
	string str;
	while(digit){
		str += digit%10 + '0';
		digit /= 10;
	}
	reverse(str.begin(), str.end());
	return str;
}

int main(int argc, char const *argv[])
{
	string str, temp;
	int digit;
	int flag = 1;
	cin >> str;
	temp = str;
	reverse(temp.begin(), temp.end());
	if(str == temp){
		cout << str <<" is a palindromic number.";
		return 0;
	}
	for(int i = 0; i < 10; i ++){
		cout << StoI(str) << " + " << StoI(temp) << " = ";
		digit = StoI(str) + StoI(temp);
		str = itos(digit);
		cout << str << endl;
		temp = str;
		reverse(temp.begin(), temp.end());
		if(temp == str){
			cout << str << " is a palindromic number.";
			return 0;
		}
		temp = str;
		reverse(temp.begin(), temp.end());
	}
	cout << "Not found in 10 iterations.";
	return 0;
}