#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;


struct node{
    string id;
    int gp = -1, gm = -1, gf = -1, g = -1;
};
map<string, node> m;
bool cmp(node a, node b){
    return a.g!=b.g ? a.g > b.g : a.id < b.id;
}
int main()
{
    int p, q, n;
    freopen("in.txt", "r", stdin);
    cin >> p >> q >> n;
    for(int i = 0; i < p; i ++){
        string id;
        int temp;
        cin >> id >> temp;
        m[id].gp = temp;
    }
    for(int i = 0; i < q; i ++){
        string id;
        int temp;
        cin >> id >> temp;
        m[id].gm = temp;
    }
    for(int i = 0; i < n; i ++){
        string id;
        int temp;
        cin >> id >> temp;
        m[id].gf = temp;
        m[id].id = id;
    }
    vector<node> ans, a;
    for(auto it : m){
        ans.push_back(it.second);
    }
    for(auto it : ans){
        if(it.gm > it.gf){
            it.g = 0.4*it.gm + 0.6*it.gf + 0.5;
        }
        else    it.g = it.gf;
        if(it.gp >= 200 && it.g >= 60)
            a.push_back(it);

    }
    sort(a.begin(), a.end(), cmp);
    for(auto it:a)
        cout << it.id << " " << it.gp << " " << it.gm << " " << it.gf << " " << it.g << endl;
    return 0;
}
