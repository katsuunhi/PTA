#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<vector<int> > v(1010);
    int n, m, a, b, flag = 0;
    vector<int> in(1010);
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        in[b] ++;
    }
    int k;
    cin >> k;
    for(int i = 0; i < k; i ++){
        int temp;
        int judge = 1;
        vector<int> itemp(in);
        for(int j = 0; j < n; j ++){
            scanf("%d", &temp);
            if(itemp[temp] != 0) judge = 0;
            else    for(auto it : v[temp]) itemp[it] --;
        }
        if(judge) continue;
        printf("%s%d", flag ? " " : "", i);
        flag = 1;

    }
    return 0;
}
