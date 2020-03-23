#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
    string str;
    int cnt;
    bool operator < (const node &b) const{
        return (cnt != b.cnt) ? cnt > b.cnt : str < b.str;
    }
};

map<string, int> m;
set<node> s;
int main()
{
    char ch;
    string str;
    freopen("in.txt", "r", stdin);
    while(ch = getchar(), ch != EOF){
        if(('0' <= ch && ch <= '9') || (ch>='a'&&ch<='z')||(ch>='A' && ch <= 'Z')){
            str += ch;
        }
        else if(str.size() != 0){
            transform(str.begin(), str.end(), str.begin(), ::tolower);
            if(m.find(str) == m.end())
                m[str] = 1;
            else    m[str] ++;
            str.clear();
        }
    }
    for(auto it : m){
        s.insert({it.first, it.second});
    }
    cout << s.begin()->str << " " << s.begin() -> cnt;

    return 0;
}
