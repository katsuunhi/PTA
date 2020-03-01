#include <iostream>
#include <map>

using namespace std;

/*
Sample Input 1:
8 15
1 2 8 7 2 4 11 15
Sample Output 1:
4 11
Sample Input 2:
7 14
1 8 7 2 4 11 15
Sample Output 2:
No Solution
*/

int main(int argc, char const *argv[])
{
	map<long int, int> m;
	map<long int, int>::iterator iter;
	long long int a, b;
	cin >> a;
	cin >> b;
	if(a < 2){
		cout << "No Solution";
		return 0;
	}

	long long int temp;
	for(long long int i = 0; i < a; i ++){
		cin >> temp;
		cout << i << "\t";
		if(m.find(temp) == m.end())
			m[temp] = 1;
		else
			m[temp] ++;
	}
	cout << "end";
	for(iter = m.begin(); iter != m.end(); iter ++){
		iter -> second --;
		if(m.find(b - iter -> first) != m.end() && m[b - iter -> first] >= 1){
			cout << iter -> first << " " << b - iter -> first;
			return 0;
		}
		
	}
	cout << "No Solution";

	return 0;
}