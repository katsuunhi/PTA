#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
struct node{
    string name;
    int height;
}l[maxn];
bool cmp(node a, node b){
    return a.height != b.height ? a.height > b.height : a.name < b.name;
}


int main()
{
    int n, k, cnt = 0;
    freopen("in.txt", "r", stdin);
    cin >> n >> k;
    vector<string> r[k];
    for(int i = 0; i < n; i ++)
        cin >> l[i].name >> l[i].height;
    sort(l, l + n, cmp);
    int cnt_last = n - n/k * (k-1);
    int cen_last = cnt_last/2;
    int i = 0;
    int cen = k/2;
    r[0].resize(cnt_last);
    r[i] = l[cnt];
    cnt ++;
    while(cnt <= cnt_last){
        if(cnt % 2 == 0){
            r[0][cen_last + cnt] = l[i];
        }
    }
    return 0;
}
