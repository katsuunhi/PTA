/*

Sample Input:
6
1111
6666
8888
1234
5555
0001
6
8888
0001
1111
2222
8888
2222
Sample Output:
8888: Minion
0001: Chocolate
1111: Mystery Award
2222: Are you kidding?
8888: Checked
2222: Are you kidding?

*/

#include <iostream>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;


int is_prime(int digit){
	if(digit == 1)
		return 0;
	for(int i = 2; i <= sqrt(digit); i ++)
		if(digit%i == 0)
			return 0;
	return 1;
}

int main(int argc, char const *argv[])
{
	
	map<int, int> m;
	int n, id, k;
	scanf("%d", &n);
	int checked[n + 1] = {0};
	for(int i = 0; i < n; i ++){
		scanf("%d", &id);
		m[id] = i + 1;
		checked[m[id]] = 1;
	}
	scanf("%d", &k);

	for(int i = 0; i < k; i ++){
		scanf("%d", &id);
//		cout << id << ": ";
		printf("%04d: ", id);
		if(m.find(id) == m.end()){
			cout << "Are you kidding?" << endl;
			continue;
		}
		if(checked[m[id]] == 0){
			cout << "Checked" << endl;
			continue;
		}
		if(checked[m[id]] == 1){
			if(m[id] == 1){
				cout << "Mystery Award" << endl;
				checked[m[id]] = 0;
				continue;
			}
			else if(is_prime(m[id])){
				cout << "Minion" << endl;
				checked[m[id]] = 0;
				continue;
			}
			else{
				cout << "Chocolate" << endl;
				checked[m[id]] = 0;
				continue;
			}
		}
	}


	return 0;
}