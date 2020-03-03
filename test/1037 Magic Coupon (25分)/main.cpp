#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int v1[maxn], v2[maxn];

int main()
{
    int nc, np, ans = 0;
    freopen("in.txt", "r", stdin);
    cin >> nc;
    for(int i = 0; i < nc; i ++)
        scanf("%d", &v1[i]);
    cin >> np;
    for(int i = 0; i < np; i ++)
        scanf("%d", &v2[i]);
    sort(v1, v1 + nc);
    sort(v2, v2 + np);
    int p = 0, q = 0;
    while(p < nc && q < np && v1[p] < 0 && v2[q] < 0){
        ans += v1[p]*v2[q];
        p ++; q++;
    }
    p = nc - 1;
    q = np - 1;
    while(p >= 0 && q >= 0 && v1[p] > 0 && v2[q] > 0){
        ans += v1[p]*v2[q];
        p --;
        q --;
    }
    cout << ans;
    return 0;
}
