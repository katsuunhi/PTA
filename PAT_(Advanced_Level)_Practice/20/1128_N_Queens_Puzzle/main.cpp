/*

Sample Input:
4
8 4 6 8 2 7 1 3 5
9 4 6 7 2 8 1 9 5 3
6 1 5 2 6 4 3
5 1 3 5 2 4
Sample Output:
YES
NO
NO
YES

*/

#include <iostream>
#include <math.h>
#include <vector>
#include <map>
using namespace std;

int main(){
	int k;
	int digit;
	int flag = 1;
	int j;
	int n;
	map<int, int> m;
	map<int, int>::iterator iter;
	map<int, int> row;
	map<int, int> north_west;
	map<int, int> south_west;
	scanf("%d", &k);
	getchar();
	for(int i = 1; i <= k; i ++){
		flag = 1;
		j = 1;
		m.clear();
		row.clear();
		north_west.clear();
		south_west.clear();
		scanf("%d", &n);
		getchar();
		while(getchar() != '\n'){
			scanf("%d", &digit);
			/*if(m.find(digit) != m.end()){
				cout << "No" << endl;
				continue;
			}
			m[digit] = j;
			j ++;*/
			m[j] = digit;
			j ++;

		}
		
		for(iter = m.begin(); iter != m.end(); iter ++){
//			cout << iter -> first << " " << iter -> second << " ";
			if(row.find(iter -> first) != row.end()){
//				cout << "row" << " ";
				cout << "NO" << endl;
				flag = 0;

				break;
			}
			else
				row[iter -> first] = 1;

			if(north_west.find(iter -> second - iter -> first) != north_west.end()){
//				cout << "north_west" << " ";
				cout << "NO" << endl;
				flag = 0;
				break;
			}
			else
				north_west[iter -> second - iter -> first] = 1;

			if(south_west.find(iter -> second + iter -> first) != south_west.end()){
//				cout << "south_west" << " ";
				cout << "NO" << endl;
				flag = 0;
				break;
			}
			else
				south_west[iter -> second + iter -> first] = 1;
			/*if(abs(iter -> second - ((++ iter) -> second)) == 1){
				cout << abs((iter -> second) - (++ iter -> second));
				cout << "No" << endl;
				flag = 0;
				break;
			}
			iter --;*/
		}
		if(flag){
			cout << "YES" << endl;
		}
	}
	
	return 0;
}