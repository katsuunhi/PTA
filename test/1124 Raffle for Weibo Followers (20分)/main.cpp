#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, s, n;
    set<string> S;
    vector<string> v(1001);
    freopen("in2.txt", "r", stdin);
    cin >> m >> s >> n;
    if(m < n){
        cout << "Keep going...";
        return 0;
    }
    for(int i = 0; i < m; i ++){
        cin >> v[i];
    }
    for(int i = n - 1; i < m; i += s){
        while(S.find(v[i]) != S.end() && i < m){
            i ++;
        }
        printf("%s\n", v[i].c_str());
        S.insert(v[i]);
    }
    return 0;
}
