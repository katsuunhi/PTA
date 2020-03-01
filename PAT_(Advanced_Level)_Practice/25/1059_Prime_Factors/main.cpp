#include <iostream>
#include <math.h>
using namespace std;


/*

Sample Input:
630
Sample Output:
3
5*6*7

*/

const long int maxn = sqrt(2147483647);
long int prime[10000], pNum = 0;
bool p[maxn] = {0};

bool is_prime(long int a){
	if(a < 2)
		return false;
	for(int i = 2; i <= sqrt(a); i ++)
		if(a%i == 0)
			return false;
	return true;
}


void get_prime(){
	for(long int i = 2; i <= maxn; i ++){
		if(p[i] == 0){
			prime[pNum ++] = i;
			for(long int j = i + i; j <= maxn; j += i)
				p[j] = 1;
		}
	}
}

int main(int argc, char const *argv[])
{
	long int n, b;
	long int factor[100];
	long int len = 0;
	long int e = 1;
	cin >> n;
	b = n;
	
	if(n == 1 || is_prime(n)){
		cout << n << "=" << n;
		return 0; 
	}
	get_prime();
	while(n > 1){
		if(is_prime(n)){
			factor[len ++] = n;
			break;
		}
		for(long int i = 0; i <= pNum; i ++){
			if(n%prime[i] == 0){
				factor[len ++] = prime[i];
				n /= prime[i];

				break;
			}
		}
	}

	cout << b << "=" << factor[0];
	long int temp = factor[0];
	for(int i = 1; i < len; i ++){
		if(temp == factor[i]){
			e ++;
			continue;
		}
		if(e > 1){
			cout << "^" << e;
			e = 1;
		}
		cout << "*" << factor[i];
		temp = factor[i];
	}
	if(e > 1){
			cout << "^" << e;
			e = 1;
	}
	return 0;
}