#include <bits/stdc++.h>
using namespace std;
int b[100],n,cnt;

struct node{
	int v, l, r, index, level;
}a[110];

bool cmp(node a, node b){
	if(a.level != b.level)
		return a.level < b.level;
	return a.index < b.index;
}

void dfs(int root, int index, int level) {
    if (a[root].l == -1 && a[root].r == -1) {
        a[root] = {b[cnt++], a[root].l, a[root].r, index, level};
	}
	else{
		if(a[root].l != -1)
			dfs(a[root].l, index*2 + 1, level + 1);
		a[root] = {b[cnt++], a[root].l, a[root].r, index, level};
		if(a[root].r != -1)
			dfs(a[root].r, index*2 + 2, level + 1); 
	} 
}


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cin >> n;
	for(int i = 0; i < n; i ++)
		cin >> a[i].l >> a[i].r;
	for(int i = 0; i < n; i ++)
		cin >> b[i];
	sort(b, b + n);
	dfs(0, 0, 0);
	sort(a, a + n, cmp);
	cout << a[0].v;
	for(int i = 1; i < n; i ++)
	cout << " " << a[i].v;
	return 0;
}
