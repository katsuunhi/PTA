#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    freopen("in.txt", "r", stdin);
    cin >> str;
    int i = 0;
    while(str[i] != 'E') i ++;
    string s = str.substr(1, i - 1);
    int n = stoi(str.substr(i+2));
    if(str[0] == '-')   cout << "-";
    if(str[i + 1] == '-'){
        cout << "0.";
        n--;
        while(n --) cout << "0";
        for(auto it:s)
            if(it != '.')   cout << it;
    }
    else{
        cout << s[0];
        int cnt, j;
        for(cnt = 0, j = 2; cnt < n && j < s.length(); j ++, cnt ++)    cout << s[j];
        if(j == s.length()){
            for(int k = 0; k < n - cnt ; k ++)  cout << '0';
        }
        else{
            cout << '.';
            for(int k = j; k < s.length(); k ++)   cout << s[k];
        }
    }
    return 0;
}
