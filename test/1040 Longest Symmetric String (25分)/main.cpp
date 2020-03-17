#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool judge(string str){
    string s;
    s = str;
    reverse(s.begin(), s.end());
    if(s == str)    return true;
    return false;
}

int main()
{
    string str;
    freopen("in.txt", "r", stdin);
    getline(cin, str);
    int i = 0, j = 0, ans = 0;
    for(int i = 0; i < str.size(); i ++){
        for(int j = i + ans; j < str.size(); j ++){
            if(judge(str.substr(i, j-i+1)) && j - i + 1 > ans){
                ans = j - i + 1;
            }
        }
    }
    cout << ans;
    return 0;
}
