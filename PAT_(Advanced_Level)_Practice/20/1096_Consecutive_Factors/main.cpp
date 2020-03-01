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

const int maxn = 31;

long long int fact(long long int i, long long int j){
	if(i == j)
		return j;
	return i*fact(i - 1, j);
}

int main(int argc, char const *argv[])
{
	long long int n;
	cin >> n;
	long long int start = 2;
	long long int len = 0; 
	for(int i = 2; i < sqrt(n); i ++){
		for(int j = 1; j <= 12; j ++){
			if(n%fact(i + j - 1, i) == 0){
				// cout << n << "%" << fact(i + j - 1, i) << endl;
				// cout << i << "->" << j << endl;
				if(j > len){
					start = i;
					len = j;
				}
			}
		}
	}
	if(len == 0){
		start = n;
		len = 1;
	}
	cout << len << endl << start;
	for(int i = 1; i < len; i ++){
		cout << "*" << start + i;
	}
	return 0;
}
