#include <iostream>
#include <bits/stdc++.h>
using namespace std;
map<int, vector<int> > m;

int main()
{
    int n, p, k;
    freopen("in.txt", "r", stdin);
    cin >> n >> p;
    for(int i = 0; i < n; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        m[a].push_back(b);
        m[b].push_back(a);
    }
    while(p --){
        scanf("%d", &k);
        vector<int> v(k);
        bool flag = false;
        int book[100000] = {0};
        for(int i = 0; i < k; i ++){
            scanf("%d", &v[i]);
            book[v[i]] = 1;
        }
        for(int i = 0; i < v.size(); i ++){
            for(int j = 0; j < m[v[i]].size(); j ++){
                if(book[m[v[i]][j]] == 1) flag = true;
            }
        }
        printf("%s\n", flag ? "No" : "Yes");
    }
    return 0;
}
