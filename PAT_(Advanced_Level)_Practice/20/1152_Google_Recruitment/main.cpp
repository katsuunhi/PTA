/*

Sample Input 1:
20 5
23654987725541023819
Sample Output 1:
49877
Sample Input 2:
10 3
2468024680
Sample Output 2:
404

*/
//2是最小的素数
#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int is_prime(long long int digit){
	if(digit == 2)
		return 1;
	for(long long int i = 2; i <= sqrt(digit); i ++)
		if(digit % i == 0)
			return 0;
	return 1;
}

int main(int argc, char const *argv[])
{
	int l, k;
	string digit;
	string temp;
	long long int num = 0;
	scanf("%d%d", &l, &k);
	
	cin >> digit;
	if(l == 0 || k == 0 || l < k){
		cout << "404";
		return 0;
	}
	for(int i = 0; i < digit.size(); i ++){
		num = 0;
		if((digit[i + k - 1] - '0')%2 == 0 && (digit[i + k - 1] - '0') != 2)
			continue;
		temp = digit.substr(i, k);
		for(int j = 0; j < k; j ++){
			num += (temp[j] - '0')*floor(pow(10, k-j-1));
		}
		
		
	//	cout << temp << " " << num << endl;
		if(is_prime(num)){
			cout << temp;
			return 0;
		}
	}
	cout << "404";

	return 0;
}