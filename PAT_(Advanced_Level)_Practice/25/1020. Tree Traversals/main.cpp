#include <bits/stdc++.h>
using namespace std;

struct node{
	int index, value;
};
vector<int> in, post;
vector<node> level;
bool cmp(node a, node b){
	return a.index < b.index;
}
/*7
2 3 1 5 7 6 4
1 2 3 4 5 6 7*/
void pre(int postl, int postr, int inl, int inr, int index){
	int i = inl;
	if(inr < inl)	return;
	if(postl == postr){
		level.push_back({index, post[postl]});
		return;
	}
	while(i <= inr && in[i] != post[postr]) i++;
	level.push_back({index, post[postr]});
	pre(postl, postl + i - inl - 1, inl, i - 1, 2*index + 1);
	pre(postl + i - inl, postr - 1, i + 1, inr, 2*index + 2);
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n, postl, postr, inl, inr;
	cin >> n;
	in.resize(n);
	post.resize(n);
	for(int i = 0; i < n; i ++)
		cin >> post[i];
	for(int i = 0; i < n; i ++)
		cin >> in[i];
	pre(0, n-1, 0, n-1, 0);
	
	sort(level.begin(), level.end(), cmp);
	cout << level[0].value;
	for(int i = 1; i < n; i ++)
		cout << " " << level[i].value;
	cout << endl;
	return 0;
}
