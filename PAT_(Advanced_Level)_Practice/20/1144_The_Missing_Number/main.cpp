/*

Sample Input:
10
5 -25 9 6 1 3 4 2 5 17
Sample Output:
7

*/
//每个数字都是int型，因此hash表应该可以容纳int个变量
//最后一个测试点没跑通，需要换方法
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int hash[100010] = {0};		//5号测试点，最大值为100000
	int n;
	int digit;
	scanf("%d", &n);
	for(int i = 0; i < n; i ++){
		scanf("%d", &digit);
		if(digit < 0)
			continue;		//
		hash[digit] = 1;
	}
	for(int i = 1; i < 100010; i ++)
		if(hash[i] == 0){
			cout << i;
			return 0;
		}
	return 0;
}