/*

Sample Input:
10
5 -25 9 6 1 3 4 2 5 17
Sample Output:
7

*/
//iterator 不能 + 1， 只能++、--，注意操作
//m.begin()指向第一个元素，m.end()指向最后一个元素之后的元素
#include <iostream>
#include <map>

using namespace std;

int main(int argc, char const *argv[])
{
	map<int, int> m;
	map<int, int>::iterator iter;
	int n;
	int digit;
	m[0] = 1;
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> digit;
		if(digit <= 0)
			continue;
		m[digit] = 1;
	}
	for(iter = m.begin(); iter != m.end(); ){
		if(iter->first + 1 != (++ iter)->first){
			iter --;
			cout << iter->first + 1;
			return 0;
		}
	}
	cout << (-- m.end())->first + 1;
	return 0;
}