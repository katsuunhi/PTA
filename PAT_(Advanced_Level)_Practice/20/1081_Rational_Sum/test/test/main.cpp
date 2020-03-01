#include<iostream>
//#include<algorithm>
#include<math.h>



using namespace std;

long int gcd(long int a, long int b){
	if(b == 0)
		return a;
	return gcd(b, a%b);
}
long int lcm(long int a, long int b){
	long int m = gcd(a, b);
	if(m == 0)
		return 0;
	return a*b/m;
}
//输入例子:
//5
//2/5 4/15 1/30 -2/60 8/3
//
//输出例子:
//3 1/3
int main(){
	int num;
	cin >> num;
	static long int nume[100];
	static long int deno[100];
	for(int i = 0; i < num; i ++){
		scanf("%ld/%ld", &nume[i], &deno[i]);
	}
	for(int i = 0; i < num; i ++){
		printf("%ld/%ld ", nume[i], deno[i]);
	}

	long int result_nume = nume[0];
	long int result_deno = deno[0];
	int LCM = 0;
	int GCD = 1;

	for(int i = 1; i < num; i ++){
		LCM = lcm(result_deno, deno[i]);
		result_nume *= LCM/result_deno;
		nume[i] *= LCM/deno[i];
		result_nume += nume[i];
		GCD = gcd(result_nume, LCM);
		result_nume /= GCD;
		result_deno = LCM/GCD;
	}
	cout << result_nume << '/' << result_deno << endl;
	if(result_nume == 0 || result_nume%result_deno == 0)
		cout << result_nume/result_deno;
	else if(abs(result_nume) < result_deno)
		cout << result_nume << '/' << result_deno << endl;
	else
		cout << result_nume/result_deno << " " << result_nume%result_deno << '/' << result_deno << endl;
	system("pause");
	return 0;
	
}