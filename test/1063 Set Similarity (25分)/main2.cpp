#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int maxn = 60;
set<int> s[maxn];

void print(set<int> i){
        for(set<int>::iterator iter = i.begin(); iter != i.end(); iter ++){
        cout << *iter << " ";
    }
    cout << endl;
}


int main2()
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
    set<int> ans;
    for(int i = 0; i < k-1; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        set_union(s[a].begin(), s[a].end(), s[b].begin(), s[b].end(), back_inserter(ans));
        //ans.insert(s[a].begin(), s[a].end());
        //ans.insert(s[b].begin(), s[b].end());
        printf("%.1f%%\n", 100*(s[a].size()+s[b].size()-ans.size())/(float)(ans.size()));
        ans.clear();
    }
    int a, b;
    scanf("%d%d", &a, &b);
    set_union(s[a].begin(), s[a].end(), s[b].begin(), s[b].end(), back_inserter(ans));
    //ans.insert(s[a].begin(), s[a].end());
    //ans.insert(s[b].begin(), s[b].end());
    printf("%.1f%%", 100*(s[a].size()+s[b].size()-ans.size())/(float)(ans.size()));
    ans.clear();
    return 0;
}
