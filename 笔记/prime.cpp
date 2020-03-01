#include <iostream>
#include <math.h>
#include <time.h>
using namespace std;

const int maxn = 1000000;
int prime[maxn], pNum = 0;
bool p[maxn] = {0};


//遍历法
bool is_prime(long long int a){
	if(a == 0 || a == 1)
		return false;
	for(int i = 2; i <= sqrt(a); i ++){
		if(a % i == 0)
			return false;
	}
	return true;
}

void find_prime(){
	for(int i = 0; i <= maxn; i ++){
		if(is_prime(i)){
			p[i] = 1;
			prime[pNum ++] = i;
		}
	}
}


void f(){
	for(int i = 2; i <= maxn; i ++){
		if(p[i] == 0){
			prime[pNum ++] = i;
		for(int j = i + i; j <= maxn; j += i)
			p[j] = 1;
		}
	}
}

//筛选法
void find_prime_select(){
	for(int i = 2; i <= maxn; i ++){
		if(p[i] == 0){
			prime[pNum ++] = i;
			for(int j = i + i; j <= maxn; j += i)
				p[j] = 1;
		}
	}
}



int main(int argc, char const *argv[])
{
	int t1 = clock();
	find_prime();
	int t2 = clock();
	cout << t2 - t1 << endl;
	
	t1 = clock();
	find_prime_select();
	t2 = clock();
	cout << t2 - t1 << endl;
	// for(int i = 0; i <= pNum; i ++){
	// 	cout << prime[i] << "\t";
	// }
	return 0;
}