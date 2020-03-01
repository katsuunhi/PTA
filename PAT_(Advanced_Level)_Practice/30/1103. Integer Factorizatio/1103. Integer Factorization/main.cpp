#include <bits/stdc++.h>
using namespace std;

int n, k, p, maxfacSum = -1;
vector<int> ans, v, anstemp;

void init(){
	int index = 1;
	int temp = 0;
	while(temp <= n){
		v.push_back(temp);
		temp = pow(index, p);
		index ++;
	}
}

void dfs(int index, int sum, int ksum, int facsum){
	if(ksum == k){
		if(sum == n && facsum > maxfacSum){
			ans = anstemp;
			maxfacSum = facsum;
		}
		return;
	}
	while(index >= 1){
		if(sum + v[index] <= n){
			anstemp[k] = index;
			cout << index << "\t";
			dfs(index, sum + v[index], ksum + 1, facsum + index);
		}
		if(index == 1)	return;
		cout << index << "\t";
		index --;
	}
		
}
int main(){
	cin >> n >> k >> p;
	init();
	anstemp.resize(k);
	cout << v[v.size() - 1];
	dfs(v.size() - 1, 0, 0, 0);
	if(maxfacSum == -1){
		cout << "Impossible";
		return 0;
	}
	cout << n << " = " << ans[0] << "^" << p;
	for(int i = 1; i < ans.size(); i ++){
		cout << " + " << ans[i] << "^" << p;
	}
	return 0;
}
