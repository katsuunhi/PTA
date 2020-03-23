#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int index, num;
};

vector<int> post, in;
vector<node> ans;
bool cmp(node a, node b){
    return a.index < b.index;
}

void pre(int root, int start, int end, int index){
    if(start > end) return;
    int i = start;
    while(start < end && post[root] != in[i])   i ++;
    ans.push_back({index, post[root]});
    pre(root - end + i - 1, start, i - 1, index*2);
    pre(root - 1, i + 1, end, index*2+1);
}

int main()
{
    int n;
    freopen("in.txt", "r", stdin);
    cin >> n;
    post.resize(n); in.resize(n);
    for(int i = 0; i < n; i ++) scanf("%d", &post[i]);
    for(int i = 0; i < n; i ++) scanf("%d", &in[i]);
    pre(n-1, 0, n-1, 1);
    sort(ans.begin(), ans.end(), cmp);
    bool flag = 1;
    for(auto it : ans) {
        printf("%s%d", (flag?"":" "), it.num);
        flag = false;
    }
    return 0;
}
