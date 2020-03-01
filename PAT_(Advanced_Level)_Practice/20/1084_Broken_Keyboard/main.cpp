/*

Sample Input:
7_This_is_a_test
_hs_s_a_es
Sample Output:
7TI

*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

//map容器常用方法
//map<type,type>::iterator iter; 迭代器，遍历时使用，iter->first表示第一个参数，iter->second表示第二个参数
//m.count(variety);	某个变量的个数，可以用来查找
//数组方式插入，可重复；insert方式插入，是以集合的方式，不可重复
int main(int argc, char const *argv[])
{
	map<int, int> m;
	map<int, int>::iterator iter;
	string original, typed;
	cin >> original;
	cin >> typed;

	for(int i = 0; i < typed.size(); i ++){
		if(typed[i] >= 'a' && typed[i] <= 'z')
			typed[i] = typed[i] - 'a' + 'A';
		m[typed[i]] = 1;
	}
	for(int i = 0; i < original.size(); i ++){
		if(original[i] >= 'a' && original[i] <= 'z')
			original[i] = original[i] - 'a' + 'A';
		if(!m.count(original[i])){
			cout << original[i];
			m[original[i]] = 1;
		}

	}
	


/*	for(iter = m.begin(); iter != m.end(); iter ++)
		if(!iter->second){
			if(iter->first == '_'){
				printf(" ");
				continue;
			}
			printf("%c", iter->first);
		}*/
	return 0;
}
