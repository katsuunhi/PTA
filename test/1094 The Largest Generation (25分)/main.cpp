#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int book[100];
vector<int> v[100];
void dfs(int root, int level){
    book[level] ++;
    for(auto it : v[root]){
        dfs(it, level + 1);
    }
}

int main()
{
    int n, m, a, b, c;
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        scanf("%d %d", &a, &b);
        for(int j = 0; j < b; j ++){
            scanf("%d", &c);
            v[a].push_back(c);
        }
    }
    dfs(1, 1);
    int maxnum = 0, maxlevel = 1;
    for(int i = 1; i <= n; i ++){
        if(book[i] > maxnum){
            maxnum = book[i];
            maxlevel = i;
        }
    }
    cout << maxnum << " " << maxlevel;
    return 0;
}
