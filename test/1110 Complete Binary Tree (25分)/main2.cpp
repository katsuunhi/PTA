#include <bits/stdc++.h>
using namespace std;
struct Node{
    int id, l, r, index;
}node[21];
vector<Node> ans;

void dfs(int root, int index){
    if(node[root].l != -1) dfs(node[root].l, index*2+1);
    ans.push_back({root, 0, 0, index});
    if(node[root].r != -1) dfs(node[root].r, index*2+2);
}

bool cmp(Node a, Node b){
    return a.index < b.index;
}

int main(){
    int n, root = 0, book[21] = {0};
    freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i ++){
        string l, r;
        node[i].id = i;
        cin >> l >> r;
        if(l != "-"){
            node[i].l = stoi(l);
            book[stoi(l)] = 1;
        }
        else    node[i].l = -1;
        if(r != "-"){
            node[i].r = stoi(r);
            book[stoi(r)] = 1;
        }
        else    node[i].r = -1;
    }
    while(book[root] != 0)  root ++;
    dfs(root, 0);
    sort(ans.begin(), ans.end(), cmp);
    if(ans[ans.size()-1].index == n-1)
        cout << "YES " << ans[ans.size()-1].id;
    else
        cout << "NO " << root;
    return 0;
}
