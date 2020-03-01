/*

Sample Input:
4
29
5
elo nov
tam
Sample Output:
hel mar
may
115
13

*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string mtoe(int high, int low){
	int temp;
	string str="";
	temp = high*13 + low;
	do{
		str += (temp%10 + '0');
		temp /= 10;
	}while(temp);
	reverse(str.begin(), str.end());
	return str;
}

int main(int argc, char const *argv[])
{
	string low[13] = {"", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
	string high[13] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
	map<string, string> m;
	string temp;
	for(int i = 0; i < 13; i ++){
		for(int j = 0; j < 13; j ++){
			if(i == 0 && j == 0)
				temp = "tret";
			else if(i == 0)
				temp = low[j];
			else if(j == 0)
				temp = high[i];
			else
				temp = high[i] + " " + low[j];
//			m[temp] = mtoe(i, j);
			m.insert(map<string, string>::value_type(temp, mtoe(i, j)));
		}
	}
	map<string, string> m2;
	map<string, string>::iterator iter;
	for(iter = m.begin(); iter != m.end(); iter++)  
 //       cout<<iter->first<<' '<<iter->second<<endl;
    	m2[iter -> second] = iter -> first;
//	cout << m2["29"];

	int n;
	cin >> n;
	string digits[n];
	getchar();
	for(int i = 0; i < n; i ++){
		getline(cin, digits[i]);

		if(m.find(digits[i]) == m.end())
			cout << m2[digits[i]] << endl;
		else
			cout << m[digits[i]] << endl;;
	}
	return 0;
}