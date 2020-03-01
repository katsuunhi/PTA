
//输入例子:
//5
//2/5 4/15 1/30 -2/60 8/3
//
//输出例子:
//3 1/3
#include "stdafx.h"
#include <algorithm>
#include <vector>
#include<map>
#include<stack>
#include<string>
#include<iostream>

using namespace std;


int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	return gcd(b, a%b);
}

int lcm(int a, int b){
	int m = gcd(a, b);
	if(m == 0)	return 0;
	else	return a*b/m;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout << lcm(3, 7);
	system("pause");
	return 0;
}

