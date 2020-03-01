/*

8
123 899 51 998 27 33 36 12
Sample Output:
4
3 6 9 26

*/

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int id(int digit){
	int sum = 0;
	while(digit){
		sum += digit%10;
		digit /= 10;
	}
	return sum;
}



int main(int argc, char const *argv[])
{
	int n;
	int count = 0;
	map<int, int> m;
	map<int, int>::iterator iter;
	scanf("%d", &n);
	int digit;
	for(int i = 0; i < n; i ++){
		scanf("%d", &digit);
		m[id(digit)] = 1;

	}
	cout << m.size() << endl;
	iter = m.begin();
	cout << iter -> first;
	iter ++;
	for(; iter != m.end(); iter ++)
		cout << " " << iter -> first;

	return 0;
}