#include <iostream>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int hobby[1001] = {0};

int find(int n){
	if(hobby[n] == 0)
		return 10000;
	if(hobby[n] < 0)
		return n;
	else
		return find(hobby[n]);
}

int main(int argc, char const *argv[])
{
	int n;
	bool add = 0;
	cin >> n;
	for(int i = 0; i < n; i ++){
		int k;
		int first;
		scanf("%d: %d",  &k, &first);
		if(find(first) == 10000){ //第一个
			hobby[first] = -1;
		}
		for(int j = 0; j < k; j ++){
			int temp;
			cin >> temp;
			hobby[temp] = first;
		}
	}
	return 0;
}