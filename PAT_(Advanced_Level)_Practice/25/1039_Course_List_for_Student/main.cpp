#include <iostream>
#include <set>
#include <string>
#include <map>
#include <algorithm>

using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


int main(int argc, char** argv) {
	int n, k;
	map<string, set<int> > m;
	map<string, set<int>  >::iterator iter;
	cin >> n;
	cin >> k;
	for(int i = 0; i < k; i ++){
		int temp;
		int index;
		
		cin >> index;
		cin >> temp;
		for(int j = 0; j < temp; j ++){
			string name;
			cin >> name;
			m[name].insert(index);
		}	
	}
	
	for(int i = 0; i < n; i ++){
		string query;
		cin >> query;
		cout << query << " " << m[query].size();
		for(set<int>::iterator j = m[query].begin(); j != m[query].end(); j ++){
			cout << " " << *j;
		}
		cout << endl;
	}
	
	return 0;
}
