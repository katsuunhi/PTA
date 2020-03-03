#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int maxn = 60;
vector<set<int> > s(maxn);

void print(set<int> i){
        for(auto iter:i){
        cout << iter << " ";
    }
    cout << endl;
}


int main()
{
    int n, m, k;
    freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n ; i ++){
        scanf("%d", &m);
        for(int j = 0; j < m; j ++){
            int temp;
            scanf("%d", &temp);
            s[i].insert(temp);
        }
    }

    cin >> k;
    int nt, nc = 0;
    for(int i = 0; i < k; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        nt = s[b].size();
        nc = 0;
        print(s[a]);
        print(s[b]);
        for(auto j:s[a]){
            if(s[b].find(j) != s[b].end())
                nc ++;
            else
                nt ++;
        }
        if(i == k-1)
            printf("%.1f%%", 100*(float)nc/nt);
        else
            printf("%.1f%%\n", 100*(float)nc/nt);

    }

    return 0;
}
