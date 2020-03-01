/*

Sample Input:
4
0.1 0.2 0.3 0.4
Sample Output:
5.00

*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	long int n;
	cin >> n;
	double sequence[n];
	for(long int i = 0; i < n; i ++)
		cin >> sequence[i];
	double sum = 0;
	for(long int i = 0; i < n; i ++)
		sum += sequence[i]*(n - i)*(i + 1);
	printf("%.2lf", sum);
	return 0;
}