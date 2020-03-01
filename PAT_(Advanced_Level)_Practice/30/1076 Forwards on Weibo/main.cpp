#include <bits/stdc++.h>
using namespace std;

struct node{
    int id, level;
};
vector<vector<int> > users;

int n, l, k;

int bfs(node tnode){
    bool book[1010] = {false};
    queue<node> q;
    q.push(tnode);
    book[tnode.id] = true;
    int cnt = 0;
    while(!q.empty()){
        node top = q.front();
        int topid = top.id;
        q.pop();
        for(int i = 0; i < users[topid].size(); i ++){
            if(book[users[topid][i]] == false && top.level < l){
                q.push({users[topid][i], top.level + 1});
                book[users[topid][i]] = true;
                cnt ++;
            }
        }
    }
    return cnt;

}

int main()
{
    cin >> n >> l;
    users.resize(n + 1);
    int temp;
    for(int i = 1; i <= n; i ++){
        cin >> temp;
        for(int j = 0; j < temp; j ++){
            int a;
            cin >> a;
            users[a].push_back(i);
        }
    }

    cin >> k;
    for(int i = 0; i < k; i ++){
        int temp;
        cin >> temp;
        node tnode = {temp, 0};
        cout << bfs(tnode) << endl;
    }
    return 0;
}
