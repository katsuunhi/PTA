#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    int num, index, level;
};

bool cmp(node a, node b){
    if(a.level != b. level) return a.level < b.level;
    if(a.level%2 != 0)  return a.index > b.index;
    return a.index < b.index;
}

vector<int> in, post;
vector<node> ans;
void pre(int root, int start, int end, int level, int index){
    if(start > end) return;
    int i = start;
    while(i < end && in[i] != post[root])   i ++;
    ans.push_back({post[root], index, level});
    pre(root - end + i - 1, start, i - 1, level + 1, index*2);
    pre(root - 1, i + 1, end, level + 1, index*2+1);
    return;
}


int main()
{
    int n;
    freopen("in.txt", "r", stdin);
    cin >> n;
    in.resize(n); post.resize(n);
    for(int i = 0; i < n; i ++) scanf("%d", &in[i]);
    for(int i = 0; i < n; i ++) scanf("%d", &post[i]);
    pre(n-1, 0, n-1, 1, 1);
    sort(ans.begin(), ans.end(), cmp);
    bool start = 1;
    for(auto it : ans){
        printf("%s%d", (start?"":" "), it.num);
        start = 0;
    }
    return 0;
}
