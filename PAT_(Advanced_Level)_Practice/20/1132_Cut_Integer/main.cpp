/*

Sample Input:
3
167334
2333
12345678
Sample Output:
Yes
No
No

*/
//浮点错误，即出现了/0或者%0的情况
#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	long long int digit, temp;
	long long int upper, bottom;
	int length = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		length = 0;
		scanf("%d", &digit);
		temp = digit;
		while(temp){
			temp /= 10;
			length ++;
		}
//		cout << length << endl;
		upper = digit/floor(pow(10, length/2));
		bottom = digit%(int)floor(pow(10, length/2));
		if(bottom == 0){
			cout << "No" << endl;
			continue;
		}
//		cout << upper << " " << bottom << endl;
		if(digit % (upper * bottom) == 0)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}