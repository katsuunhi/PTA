#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1010;
struct node{
    int w;
    float p, pp;
}l[maxn];

bool cmp(node a, node b){
    return a.pp > b.pp;
}


int main()
{
    int n, d;
    float ans = 0;
    freopen("in.txt", "r", stdin);
    cin >> n >> d;
    for(int i = 0; i < n; i ++) cin >> l[i].w;
    for(int i = 0; i < n; i ++){
        cin >> l[i].p;
        l[i].pp = l[i].p/l[i].w;
    }
    sort(l, l + n, cmp);
    int i = 0;
    while(d > 0 && i < n){
        if(d - l[i].w >= 0){
            ans += l[i].p;
            d -= l[i].w;
        }
        else if(d > 0 && d - l[i].w < 0){
            ans += l[i].pp*d;
            d = 0;
        }
        i ++;
    }
    printf("%.2f", ans);
    return 0;
}
