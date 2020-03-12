#include <iostream>
#include <bits/stdc++.h>
using namespace std;



int main()
{
    int n, m;
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    int v[n][n] = {0};
    for(int i = 0; i < m; i ++){
        int a, b;
        cin >> a >> b;
        v[a][b] = 1;
        v[b][a] = 1;
    }
    int k;
    cin >> k;
    while(k--){

        set<int> s;
        bool flag = true;
        int num;
        cin >> num;
        vector<int> q(num);
        for(int i = 0; i < num; i ++){
            cin >> q[i];
            s.insert(q[i]);
        }

        if(s.size() != n || num != n + 1 || q[0] != q[num-1]) flag = false;
        for(int i = 1; i < num; i ++){
            if(v[q[i]][q[i-1]] == 0)
                flag = false;
        }
        if(flag)    cout << "YES" << endl;
        else    cout << "NO" << endl;

    }
    return 0;
}
