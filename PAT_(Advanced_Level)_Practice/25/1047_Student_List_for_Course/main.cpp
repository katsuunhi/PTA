#include <iostream>
#include <set>
#include <string>
#include <map>
#include <algorithm>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main1(int argc, char** argv) {
	int n, k;
	map<int, set<string> > m;
	cin >> n;
	cin >> k;
	for(int i = 0; i < n; i ++){
		string name;
		cin >> name;
		int num;
		cin >> num;
		for(int j = 0; j < num; j ++){
			int index;
			cin >> index;
			m[index].insert(name);
		}
	}
	for(map<int, set<string> >::iterator iter = m.begin(); iter != m.end(); iter ++){
		cout << iter -> first << " " << (iter -> second).size();
		for(set<string>::iterator i = (iter -> second).begin(); i != (iter -> second).end(); i ++)
			cout << endl << *i;
		cout << endl;
	}
	return 0;
}
