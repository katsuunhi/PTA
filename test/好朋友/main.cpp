#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int father[210];
bool isRoot[210];

void init(int n){
    for(int i = 1; i <= n; i ++){
        father[i] = i;
        isRoot[i] = false;
    }
}

int findfather(int v){
    if(v == father[v])  return v;
    else{
        int f = findfather(father[v]);
        father[v] = f;
        return f;
    }
}

void Union(int a, int b){
    int faA = findfather(a);
    int faB = findfather(b);
    if(faA != faB){
        father[faA] = faB;
    }
}

int main()
{
    freopen("in2.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    init(n);

    for(int i = 0; i < m; i ++){
        int a, b;
        scanf("%d %d", &a, &b);
        Union(a, b);
    }
    for(int i = 1; i <= n; i ++){
        isRoot[findfather(i)] = true;
    }
    int ans = 0;
    for(int i = 0; i <= n; i ++){
        if(isRoot[i])
            ans ++;
    }
    cout << ans;
    return 0;
}
