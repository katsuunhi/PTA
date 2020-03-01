#include <iostream>
using namespace std;


long long int gcd(long long int a, long long int b){
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int gcd(int a, int b){
	if(b == 0)
		return a;
	else
		return gcd(b, a%b);
}

int lcm(int a, int b){
	int m = gcd(a, b);
	if(m == 0)
		return 0;
	else
		return a*b/m;
}


long long int lcm(long long int a, long long int b){
	long long int m;
	m = gcd(a, b);
	if(m == 0)
		return 0;
	return a*b/m;
}

int main(int argc, char const *argv[])
{
	cout << gcd(33,44) << endl << lcm(33, 44) << endl;
	return 0;
}
