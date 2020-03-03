#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int r = 1;
    string ins;
    int tws = 0;
    int ns = 0;
};

bool cmp(node a, node b){
    if(a.tws != b.tws)  return a.tws > b.tws;
    else return a.ns != b.ns ? a.ns < b.ns : a.ins < b.ins;
}

int main()
{
    int n;
    map<string, node> m;
    map<string, double> s;
    freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i ++){
        string id, ins;
        int score;
        cin >> id >> score >> ins;
        transform(ins.begin(), ins.end(), ins.begin(), ::tolower);
        m[ins].ins = ins;
        m[ins].ns ++;
        if(id[0] == 'A')    s[ins] += score;
        else if(id[0] == 'B')    s[ins] += score/1.5;
        else if(id[0] == 'T')    s[ins] += score*1.5;
    }
    for(auto it : s){
        m[it.first].tws = it.second;
    }
    vector<node> v;
    for(auto it : m)
        v.push_back(it.second);
    sort(v.begin(), v.end(), cmp);
    for(int i = 1; i < v.size(); i ++){
        if(v[i].tws == v[i - 1].tws)
            v[i].r = v[i - 1].r;
        else    v[i].r = i + 1;
    }
    int cnt = m.size();
    cout << cnt << endl;
    for(auto it : v){
        printf("%d %s %d %d\n", it.r, it.ins.c_str(), it.tws, it.ns);
    }

    return 0;
}
