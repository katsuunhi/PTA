#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
    string id;
    int fr = 1, ln, lr, score;
};

bool cmp(node a, node b){
    if(a.score != b.score)  return a.score > b.score;
    return a.id < b.id;
}

int main()
{
    int n, k;
    vector<node> ans;
    freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> k;
        vector<node> v(k);
        while(k --){
            cin >> v[k].id >> v[k].score;
            v[k].ln = i;
        }
        sort(v.begin(), v.end(), cmp);
        v[0].lr = 1;
        ans.push_back(v[0]);
        for(int j = 1; j < v.size(); j ++){
            if(v[j].score == v[j-1].score)  v[j].lr = v[j-1].lr;
            else    v[j].lr = j + 1;
            ans.push_back(v[j]);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    //ans[0].fr = 1;
    for(int j = 1; j < ans.size(); j ++){
        if(ans[j].score == ans[j-1].score)  ans[j].fr = ans[j-1].fr;
        else    ans[j].fr = j + 1;
    }
    cout << ans.size() << endl;
    for(auto it : ans)  cout << it.id << " " << it.fr << " " << it.ln << " " << it.lr << endl;
    return 0;
}
