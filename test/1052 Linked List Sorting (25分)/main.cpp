#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
struct Node{
    int index;
    int key;
    int next;
    int flag = -1;
}node[maxn];

bool cmp(Node a, Node b){
    if(a.flag == -1 || b.flag == -1){
        return a.flag > b. flag;
    }
    else    return a.key < b.key;
}

int main()
{
    int n, s;
    freopen("in.txt", "r", stdin);

    cin >> n >> s;
    int index, key, next;

    for(int i = 0; i < n; i ++){
        scanf("%d %d %d", &index, &key, &next);

        node[index].index = index;
        node[index].key = key;
        node[index].next = next;
    }
    int p = s;
    int num = 0;
    while(p != -1){
        node[p].flag = 1;
        p = node[p].next;
        num ++;
    }


    if(num == 0){
        printf("0 -1");
        return 0;
    }
    sort(node, node + maxn, cmp);
    printf("%d %05d\n", num, node[0].index);
    for(int i = 0; i < num - 1; i ++){
        printf("%05d %d %05d\n", node[i].index, node[i].key, node[i + 1].index);
    }
    printf("%05d %d -1", node[num-1].index, node[num-1].key);

    return 0;
}
