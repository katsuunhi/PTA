#include <bits/stdc++.h>
using namespace std;

struct node{
	int v;
	struct node *left, *right;
};

node *build(node *root, int v){
	if(root == NULL){
		root = new node();
		root -> v = v;
		root -> left = root -> right = NULL;
	}
	else if(v > root -> v)
		root -> right = build(root -> right, v);
	else
		root -> left = build(root -> left, v);
	return root;
}

vector<int> num(1000);
int maxdepth = -1;
void dfs(node *root, int depth){
	if(root == NULL){
		maxdepth = max(depth, maxdepth);
		return;
	}
	num[depth] ++;
	dfs(root -> left, depth + 1);
	dfs(root -> right, depth + 1);
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int n;
	cin >> n;
	node *root = NULL;
	for(int i = 0; i < n; i ++){
		int temp;
		cin >> temp;
		root = build(root, temp);
	}
	dfs(root, 0);
	printf("%d + %d = %d", num[maxdepth - 1], num[maxdepth - 2], num[maxdepth - 1] + num[maxdepth - 2]);
	return 0;
}
