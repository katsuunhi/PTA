#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> in(1010);
int g[1010][1010] = {0};
int main2()
{
    int n, m;
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < m; i ++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a][b] = 1;
        in[b] ++;
    }
    int k;
    bool start = true;
    cin >> k;
    for(int j = 0; j < k; j ++){
        vector<int> itemp(in);
        int judge = 1;
        for(int i = 0; i < n; i ++){
            int temp;
            scanf("%d", &temp);
            if(judge == 0)  continue;
            if(itemp[temp] != 0){
                if(start)   cout << j;
                else    printf(" %d", j);
                start = false;
                judge = 0;
            }
            else{
                for(int l = 1; l <= n; l ++){
                    if(g[temp][l] == 1)
                        itemp[l] --;
                }
            }

        }
    }
    return 0;
}
