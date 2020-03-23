#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, k;
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    vector<vector<int> > v(10010);
    for(int i = 0; i < m; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cin >> k;
    for(int j = 0; j < k; j ++){
        vector<int> color(n, 0);
        set<int> s;
        int flag = true;
        //cout << flag << " " << s.size() << endl;
        for(int i = 0; i < n; i ++){
            scanf("%d", &color[i]);
            s.insert(color[i]);
        }
        for(int i = 0; i < n; i ++){
            for(auto it : v[i]){
                if(color[i] == color[it]){
                    flag = false;
                    break;
                }
            }
            if(!flag)   break;
        }
        if(flag)    printf("%d-coloring\n", s.size());
        else    printf("No\n");
    }
    return 0;
}
