#include <iostream>
#include <vector>

using namespace std;

vector<int> pre, in, post;

bool unique = true;

void getIn(int prel, int prer, int postl, int postr){
	if(pre[prel] == pre[prer]){
		in.push_back(pre[prel]);
		return;
	}
	if(pre[prel] == post[postr]){
		int i = prel + 1;
		while(i < prer && pre[i] != post[postr - 1])
			i ++;
		if(i - prel > 1){
			getIn(prel + 1, i - 1, postl, postl + (i - prel - 1) - 1);
		}
		else
			unique = false;
		in.push_back(post[postr]);
		getIn(i, prer, postl + (i - prel - 1), postr - 1);
	}
}
int main() {
	int n;
	cin >> n;
	pre.resize(n);
	post.resize(n);
	for(int i = 0; i < n; i ++)
		cin >> pre[i];
	for(int i = 0; i < n; i ++)
		cin >> post[i];
	getIn(0, n-1, 0, n-1);
	cout << (unique == true? "Yes":"No")<< endl << in[0];
	for(int i = 1; i < n; i ++){
		cout << " " << in[i];
	}	
	cout << endl;
}
