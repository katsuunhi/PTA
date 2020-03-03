#include <iostream>
#include <bits/stdc++.h>
using namespace std;


struct node{
    string str;
    int value;
};
bool cmp(node a, node b){
    return a.value != b.value ? a.value > b.value : a.str < b.str;
}

int main()
{
    int n, m;
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    node p[n];
    for(int i = 0; i < n; i ++)
        cin >> p[i].str >> p[i].value;
    for(int i = 0; i < m; i ++){
        int type, nt = 0, ns = 0;
        string str;
        vector<node> ans;
        cin >> type >> str;
        printf("Case %d: %d %s\n", i + 1, type, str.c_str());
        if(type == 1){
            for(int j = 0; j < n; j ++)
                if(p[j].str[0] == str[0])  ans.push_back(p[j]);
        }
        else if(type == 2){
                for(int j = 0; j < n; j ++)
                    if(p[j].str.substr(1, 3) == str){
                        nt ++;
                        ns += p[j].value;
                }
                if(nt != 0) printf("%d %d\n", nt, ns);
        }
        else if(type == 3){
            unordered_map<string, int> m;
            for(int j = 0; j < n; j ++){
                if(p[j].str.substr(4, 6) == str)  m[p[j].str.substr(1, 3)] ++;
            }
            for(auto x:m)   ans.push_back({x.first, x.second});

        }
        sort(ans.begin(), ans.end(), cmp);
        for(auto it:ans)    printf("%s %d\n", it.str.c_str(), it.value);
        if(((type == 1 || type == 3) && ans.size() == 0) ||(type == 2 && nt == 0))
            printf("NA\n");
        //for(int j = 0; j < ans.size(); j ++){}

    }
    return 0;
}
