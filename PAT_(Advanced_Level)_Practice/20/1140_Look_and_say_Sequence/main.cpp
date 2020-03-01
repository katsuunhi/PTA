/*

Sample Input:
1 8
Sample Output:
1123123111

*/

#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	int d, n;

	scanf("%d%d", &d, &n);
	string str, temp;
	str += d + '0';
	int j = 0;
	
	for(int i = 0; i < n - 1; i ++){
		temp += str[0];
		j = 1;
		temp += '1';
		for(int k = 1; k < str.size(); k ++){
			if(str[k] != temp[j - 1]){
				j += 2;
				temp += str[k];
				temp += '1';
			}
			else{
				temp[j] ++;
			}
		}
//		cout << i << " " << temp << endl;
		str = temp;
		temp = "";
	}
	cout << str;
	return 0;
}