#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool cmp(string a, string b){
    return a + b < b + a;
}

string f(int a){
    stringstream ss;
    string str;
    ss << a; ss >> str;
    return str;
}

int main()
{
    vector<string> v;
    int n;
    freopen("in.txt", "r", stdin);
    cin >> n;
    v.resize(n);
    for(int i = 0; i < n; i ++) cin >> v[i];
    sort(v.begin(), v.end(), cmp);
    v[0] = f(stoi(v[0]));
    if(v[0] == "0"){
        cout << "0";
        return 0;
    }
    for(auto it : v)
        cout << it;
    return 0;
}
