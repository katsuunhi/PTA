/*

Sample Input:
3
caseee1__thiiis_iiisss_a_teeeeeest
Sample Output:
ei
case1__this_isss_a_teest


*/
//注意并不是大于k次，而是重复k次，当有2k个重复时要变成两个字母
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <math.h>
using namespace std;



int main(int argc, char const *argv[])
{
	int k;
	int flag = 0;
	int num = 1;
	map<int, int> m;
	map<int, int>::iterator iter;
	string str;
	char ch;
	scanf("%d", &k);
	cin >> str;
	for(int i = 0; i < str.size(); i ++){
		num = 1;
		//第一次出现
		if(m.find(str[i]) == m.end()){
			while(str[i] == str[i + 1]){//连续出现次数
				num ++;
				i ++;
				if(num == k)			//k次结束
					break;
			}
			if(num == k)		//次数等于k
				m[str[i]] = 1;	//记录
			else
				m[str[i]] = 0;
			continue;			//否则下一个
		}
		//已经被记录
		if(m.find(str[i]) != m.end()){
			if(m[str[i]] == 1){
				while(str[i] == str[i + 1]){//连续出现次数
					num ++;
					i ++;
					if(num == k)		//k次结束
						break;
				}
				if(num < k)		//次数小于k
					m[str[i]] = 0;	//记录改成0，以后不再记录
			}
			if(m[str[i]] == 0){		//已经被记录但是已经被
				continue;
			}
		}

	}

// 	for(iter = m.begin(); iter != m.end(); iter ++)
// //		cout << iter->first << " " << iter->second << endl;
// 		printf("%c %d", iter -> first, iter -> second);

	//按顺序取出坏掉的字母
	//防止重复，将以取出的字母map->second置为2
	for(int i = 0; i < str.size(); i ++){
		if(m[str[i]] == 1){
			printf("%c", str[i]);
			m[str[i]] = 2;
		}
	}

	cout << endl;

	//打印原字符串，遇到map中标记不为0的字母，跳过k个
	for(int i = 0; i < str.size(); i ++){
		num = 1;
		if(m[str[i]] != 0){
			cout << str[i];
			while(str[i] == str[i + 1]){
				i ++;
				num ++;
				if(num == k)			//k次结束
					break;
			}
		}
		else
			cout << str[i];
	}
	return 0;
}