/*
Sample Input 1:
2/3 -4/2
Sample Output 1:
2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)
Sample Input 2:
5/3 0/6
Sample Output 2:
1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf
*/


#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	long int numerators[2];
	long int denominators[2];
	long int a, b;
	long int sum = 0;
	long int subtraction = 0;
	long int multiplication = 0;

	scanf("%ld/%ld%ld/%ld", &numerators[0], &denominators[0], &numerators[1], &denominators[1]);
	printf("%ld/%ld%ld/%ld", numerators[0], denominators[0], numerators[1], denominators[1]);
	if(numerators[0]%denominators[0] == 0)
		a = numerators[0]/denominators[0];
	if(numerators[1]%denominators[1] == 0)
		b = numerators[1]/denominators[1];

	return 0;
}