#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
struct Node{
    int index;
    int data;
    int next;
    int flag = -1;
    int num;
}node[maxn];

bool cmp(Node a, Node b){
    if(a.flag != b.flag)
        return a.flag > b.flag;
    else
        return a.num < b.num;
}


int main()
{
    int s, n, k;
    freopen("in.txt", "r", stdin);
    cin >> s >> n >> k;
    int index, data, next;
    for(int i = 0; i < n; i ++){
        scanf("%d %d %d", &index, &data, &next);
        node[index].index = index;
        node[index].data = data;
        node[index].next = next;
        if(data < 0)    node[index].flag = 2;
        else if(data > k)    node[index].flag = 0;
        else if(data >= 0 && data <= k)   node[index].flag = 1;
    }
    int num = 0;
    for(int p = s; p != -1; p = node[p].next){
        node[p].num = num ++;
    }
    sort(node, node + maxn, cmp);

    for(int i = 0; i < n - 1; i ++){
        printf("%05d %d %05d\n", node[i].index, node[i].data, node[i+1].index);
    }
    printf("%05d %d -1", node[n-1].index, node[n-1].data);
    return 0;
}
