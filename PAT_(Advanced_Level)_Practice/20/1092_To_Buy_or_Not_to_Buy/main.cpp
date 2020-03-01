#include <iostream>
#include <map>
#include <string>

using namespace std;

/*
Sample Input 1:
ppRYYGrrYBR2258
YrR8RrY
Sample Output 1:
Yes 8
Sample Input 2:
ppRYYGrrYB225
YrR8RrY
Sample Output 2:
No 2
*/


int main(int argc, char const *argv[])
{
	string owner, eva;
	map<char, int> m;
	cin >> owner;
	cin >> eva;
	int n = 0;
	for(int i = 0; i < owner.length(); i ++){
		if(m.find(owner[i]) == m.end())
			m[owner[i]] = 1;
		else
			m[owner[i]] ++;
	}
	for(int i = 0; i < eva.length(); i ++){
		if(m.find(eva[i]) != m.end()){
			if(m[eva[i]] <= 0)
				n ++;
			m[eva[i]] --;
		}
		else
			n ++;
	}
	if(n == 0)
		cout << "Yes " << owner.length() - eva.length();
	else
		cout << "No " << n;
	return 0;
}