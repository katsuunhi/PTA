#include <iostream>
#include <time.h>
#include <sstream>
#include <string>
using namespace std;

string ss_to_string(int a){
	stringsteam ss;
	string str;
	ss << a; ss >> str;
	return str;
}

int ss_to_int(string str){
	stringstream ss;
	int a;
	ss << str; ss >> a;
	return a;
}

string ss_to_string(int a){
	stringstream ss;
	string str;
	ss << a; ss >> str;
	return str;
}

int ss_to_int(string str){
	stringstream ss;
	int a;
	ss << str; ss >> a;
	return a;
}

string c_to_string(int a){
	char str[20];
	sprintf(str, "%d", a);
	return str;
}

// int c_to_int(string str){
// 	int a;
// 	char temp[20] = str;


// 	sscanf(temp, "%d", &a);
// 	return a;
// }


int main(int argc, char const *argv[])
{

	string str[2] = {"a", "b"};
	cout << str;
	long long int dig = 1023;
	float flo= 1023.5;
	char str1[10];
	char str2[10];
	char str3[10] = "123454321";
	stringstream ss;


	int t1 = clock();
	for(int i = 0; i < 10000; i ++){
		sprintf(str1, "%lld", dig);
		sprintf(str2, "%.1f", flo);
		sscanf(str3, "%lld", &dig);
	}
	int t2 = clock();
	cout << t2 - t1 << "\t" << str1 << "\t" << str2 << "\t" << dig << endl;

	dig = 1023;
	char str4[10];
	char str5[10];
	char str6[10] = "123454321";

	t1 = clock();
	for(int i = 0; i < 10000; i ++){
		ss << dig; ss >> str4;
		ss.clear();
		ss << flo; ss >> str5;
		ss.clear();
		ss << str6; ss >> dig;
		ss.clear();
	}
	t2 = clock();
	cout << t2 - t1 << "\t" << str4 << "\t" << str5 << "\t" << dig << endl;

	cout << c_to_string(1023);
	return 0;
}