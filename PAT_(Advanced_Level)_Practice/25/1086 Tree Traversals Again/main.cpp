#include <bits/stdc++.h>
using namespace std;


vector<int> pre, in, post;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void Post(int prel, int prer, int inl, int inr){
	int i = inl;
	if(prer < prel)	return;
	if(prer == prel){
		post.push_back(pre[prer]);
		return;
	}
	while(i <= inr && in[i] != pre[prel])	i++;
	Post(prel + 1, prel + i - inl, inl, i - 1);
	Post(prel + i - inl + 1, prer, i + 1, inr);
	post.push_back(pre[prel]);
}

int main(int argc, char** argv) {
	
	stack<int> s;
	int n;
	string op;
	int temp;
	cin >> n;
	for(int i = 0; i < n; ){
		cin >> op;
		if(op.size() > 3){
			cin >> temp;
			s.push(temp);
			pre.push_back(temp);
		}
		else{
			in.push_back(s.top());
			s.pop();
			i ++;
		}
	}
	Post(0, n-1, 0, n-1);
	cout << post[0];
	for(int i = 1; i < post.size(); i ++)
		cout << " " << post[i];
	cout << endl;
	return 0;
}
