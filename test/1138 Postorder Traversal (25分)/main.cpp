#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> pre, in, ans;
bool flag = 1;

void post(int root, int start, int end){
    //if(flag == 0)   return;
    if(start > end) return;
    int i = start;
    while(i < end && pre[root] != in[i])    i ++;
    post(root + 1, start, i - 1);
    post(root + i - start + 1, i + 1, end);
    ans.push_back(pre[root]);
    printf("%s%d", (flag?"":" "), pre[root]);
    flag = 0;
}

int main()
{
    int n;
    freopen("in.txt", "r", stdin);
    cin >> n;
    pre.resize(n);
    in.resize(n);
    for(int i = 0; i < n; i ++) scanf("%d", &pre[i]);
    for(int i = 0; i < n; i ++) scanf("%d", &in[i]);
    post(0, 0, n - 1);
    cout << ans[0];
    return 0;
}
