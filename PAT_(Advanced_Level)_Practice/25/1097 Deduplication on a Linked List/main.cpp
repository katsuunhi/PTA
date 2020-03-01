#include <bits/stdc++.h>

using namespace std;
const int maxn = 100000;
struct node{
	int addr;
	int key;
	int next;
	int num = 2*maxn;
}a[maxn];

int book[maxn] = {0};

int cmp(node a, node b){
	return a.num < b.num;
}

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
Sample Input:

00100 5
99999 -7 87654
23854 -15 00000
87654 15 -1
00000 -15 99999
00100 21 23854

Sample Output:
00100 21 23854
23854 -15 99999
99999 -7 -1
00000 -15 87654
87654 15 -1
*/

int main(int argc, char** argv) {
	int head, n, cnt1 = 0, cnt2 = 0, temp;
	cin >> head;
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> temp;
		a[temp].addr = temp;
		cin >> a[temp].key;
		cin >> a[temp].next;
	}
	for(int i = head; i != -1; i = a[i].next){
		if(!book[abs(a[i].key)]){
			book[abs(a[i].key)] = 1;
			a[i].num = cnt1;
			cnt1 ++;
		}
		else{
			a[i].num = maxn + cnt2;
			cnt2 ++;
		}
	}
	sort(a, a + maxn, cmp);
	int cnt = cnt1 + cnt2;
	for(int i = 0; i < cnt; i ++){
		if(i != cnt1 - 1 && i != cnt -1){
			printf("%05d %d %05d\n", a[i].addr, a[i].key, a[i + 1].addr);
		}
		else{
			printf("%05d %d -1\n", a[i].addr, a[i].key);
	
		}
	}
	
	
	
	return 0;
}
