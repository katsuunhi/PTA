#include <bits/stdc++.h>
using namespace std;
struct Node{
    int id, index, l, r, level;
}node[11];
vector<Node> ans;

void dfs(int root, int index, int level){
    if(node[root].r != -1)  dfs(node[root].r, index*2+2, level + 1);
    ans.push_back({root, index, 0, 0, level});
    if(node[root].l != -1)  dfs(node[root].l, index*2+1, level + 1);
}

bool cmp(Node a, Node b){
    return a.level != b.level ? a.level < b.level : a.index > b.index;
}

int main(){
    int n, book[11] = {0}, root = 0;
    freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i ++){
        node[i].id = i;
        string l, r;
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
    while(book[root] == 1)  root ++;
    dfs(root, 0, 0);
    vector<Node> v(ans);
    bool start = true;

    sort(ans.begin(), ans.end(), cmp);

    for(int i = 0; i < n; i ++){
        if(i != 1)  cout << " ";
        cout << ans[i].id;
    }
    cout << endl;
    for(int i = 0; i < n; i ++){
        if(i != 0)  cout << " ";
        cout << v[i].id;
    }
    return 0;
}
