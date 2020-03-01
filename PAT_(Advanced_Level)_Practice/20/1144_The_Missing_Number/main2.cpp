#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int digit[n] = {0}; 
	for(int i = 0; i < n; i++){
		cin >> digit[i];
	}
	sort(digit, digit + n);
	for(int i = 0; i < n - 1; i ++){

		if(digit[i] < 1)
			continue;
		if(digit[i + 1] != digit[i] + 1){
			cout << "test";
			cout << digit[i] + 1;
			return 0;
		}
	}
	cout << digit[n - 1] + 1;
	return 0;
}