/*

Sample Input 1:
5
2/5 4/15 1/30 -2/60 8/3
Sample Output 1:
3 1/3
Sample Input 2:
2
4/3 2/3
Sample Output 2:
2
Sample Input 3:
3
1/3 -1/6 1/8
Sample Output 3:
7/24

*/
//等做完重写吧，太乱了
#include <iostream>
#include <algorithm>
using namespace std;

struct rational{
	long int numerator;
	long int denominator;
};

long int greatest_common_divisor(long int a, long int b){
	if(a < 0)
		a = -a;
	if(b < 0)
		b = -b;
	if(a > b){
		int temp = a;
		a = b;
		b = temp;
	}
	long int gcd = a;
	if(b%a == 0)
		return a;
	else{
		gcd = b%a;
		while(a%gcd){
			
			gcd = a%gcd;
		}
		return gcd;
	}
}

long int least_common_multiple(long int a, long int b){
	if(a < 0)
		a = -a;
	if(b < 0)
		b = -b;
	return a*b/greatest_common_divisor(a, b);
}

//符号  测试1， -3/2
int main(int argc, char const *argv[]){

	int n;
	scanf("%d", &n);
	long int deno[n];
	struct rational test[n];
	struct rational result;
	result.numerator = 0;
	//存储
	for(int i = 0; i < n; i ++){
		scanf("%ld/%ld", &test[i].numerator, &test[i].denominator);
		if(test[i].numerator == 0){
			i --;
			n --;
			continue;
		}
		deno[i] = test[i].denominator;
	}
	//如果只有一个数直接输出
	if(n == 1){
		long int gcd = greatest_common_divisor(test[0].numerator, test[0].denominator);
	//	cout <<result.numerator << result.denominator << endl;
		if(gcd){
			test[0].numerator /= gcd;
			test[0].denominator /= gcd;
		}
		if(result.numerator < 0)
			result.numerator = - result.numerator;
	//	cout << gcd << " " << result.numerator << endl;
		long int integer = test[0].numerator/test[0].denominator;
		result.numerator = result.numerator - integer*result.denominator;
		if(integer)
			cout << integer;

		if(result.numerator){
			cout << " " << result.numerator;
		
			if(result.denominator != 1) 
				cout << "/" << result.denominator;
		}
		
	//	cout << gcd << " " << result.numerator << endl;
		
		return 0;
	}
	//求最小公倍数
	sort(deno, deno + n);
	long int lcm =  least_common_multiple(deno[0], deno[1]);
//	cout << lcm << endl;
	for(int i = 2; i < n; i ++){
		lcm = least_common_multiple(lcm, deno[i]);
//		cout << lcm << endl;
	}
	result.denominator = lcm;
	//通分
	for(int i = 0; i < n; i ++){
		result.numerator += lcm/test[i].denominator*test[i].numerator;
//		cout << result.numerator << endl;
	}
	//求结果的最小公约数并化简
	long int gcd = greatest_common_divisor(result.numerator, result.denominator);
//	cout <<result.numerator << result.denominator << endl;
	if(gcd){
		result.numerator /= gcd;
		result.denominator /= gcd;
	}
	if(result.numerator < 0)
		result.numerator = - result.numerator;
//	cout << gcd << " " << result.numerator << endl;
	long int integer = result.numerator/result.denominator;
	result.numerator = result.numerator - integer*result.denominator;
	if(integer)
		cout << integer;

	if(result.numerator){
		cout << " " << result.numerator;
	
		if(result.denominator != 1) 
			cout << "/" << result.denominator;
	}
	/*for(int i = 0; i < n; i ++)
		printf("%ld/%ld ", test[i].numerator, test[i].denominator);*/
//	cout << lcm;
	return 0;
}