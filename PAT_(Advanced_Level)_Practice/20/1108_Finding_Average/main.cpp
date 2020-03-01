/*

Sample Input 1:
7
5 -3.2 aaa 9999 2.3.4 7.123 2.35
Sample Output 1:
ERROR: aaa is not a legal number
ERROR: 9999 is not a legal number
ERROR: 2.3.4 is not a legal number
ERROR: 7.123 is not a legal number
The average of 3 numbers is 1.38
Sample Input 2:
2
aaa -9999
Sample Output 2:
ERROR: aaa is not a legal number
ERROR: -9999 is not a legal number
The average of 0 numbers is Undefined

*/

#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

float s_to_int(string str){
	int flag = 0;
	if(str[0] == '-')
		flag = 1;

	float result = 0;
	int dot = str.size();
	for(int i = 0; i < str.size(); i ++){
		if(str[i] == '.')
			dot = i;
	}

	for(int i = 0; i < dot; i ++){
		if(str[i] == '-')
			continue;
		result += (str[i] - '0')*floor(pow(10, dot - i - 1));
	}
	if(dot != str.size()){
		for(int i = dot + 1; i < str.size(); i ++){
			result += (str[i] - '0')*pow(10, dot - i);
		}
	}
	if(flag)
		result = -result;
//	cout << str << " is " << result << endl;

	return result;
}

//含有非数字或者多个小数点
int not_digit(string str){
	int dot_num = 0;
	if(str[0] == '-'){

	}
	else if(str[0] < '0' || str[0] > '9')
		return 1;
	for(int i = 1; i < str.size(); i ++){
		if(str[i] == '.'){
			dot_num ++;
			if(dot_num == 2)
				return 1;
			continue;
		}
		if(str[i] < '0' || str[i] > '9'){
			return 1;
		}
	}
	return 0;
}

int accurate_error(string str){

	for(int i = 0; i < str.size(); i ++){
		if(str[i] == '.' && (str.size() - i > 3 || str.size() == i + 1))
			return 1;
	}
	return 0;
}

int not_range(string str){
	float num = s_to_int(str);
	if(num > 1000 || num < -1000)
		return 1;
	return 0;

}


int main(int argc, char const *argv[])
{
	int n;
	float sum = 0;
	int count = 0;
	cin >> n;
	int legal[n] = {0};
	string str[n];
	for(int i = 0; i < n; i ++){
		cin >> str[i];

		//不全都是数字或者.
		if(not_digit(str[i])){
//			cout << "not_digit" << endl;
			legal[i] = 1;
		}

		//小数点后超过两位或者最后一位是小数点
		else if(accurate_error(str[i])){
//			cout << "accurate_error" << endl;
			legal[i] = 1;
		}
		//大于1000或者小于-1000
		else if(not_range(str[i])){
//			cout << "not_range" << endl;
			legal[i] = 1;
		}

	}
	for(int i = 0; i < n; i ++){
		
		if(!legal[i]){
			sum += s_to_int(str[i]);
			count ++;
		}
		else
			cout << "ERROR: "<< str[i] << " is not a legal number" << endl;
	}
	if(count == 0)
		printf("The average of 0 numbers is Undefined");
	else if(count == 1)
		printf("The average of %d numbers is %.2f", 1, sum);
	else
		printf("The average of %d numbers is %.2f", count, sum/count);


	
	return 0;
}