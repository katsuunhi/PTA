#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    freopen("in.txt", "r", stdin);
    cin >> k;
    string str;
    cin >> str;
    unordered_set<char> s;
    unordered_set<char> ans;
    for(int i = 0; i < str.size();){
        if(s.find(str[i]) != s.end()){
            i ++;
            continue;
        }
        int cnt = 1;
        char temp = str[i];
        while(str[++i] == temp && i < str.size()){
            //cout << str[i];
            cnt ++;
        }
        if(cnt % k != 0){
            s.insert(temp);
            ans.erase(temp);
        }
        else    ans.insert(temp);
    }
    for(int i = 0; i < str.size(); i ++){
        if(ans.find(str[i]) != ans.end()){
            str.erase(i + 1, k - 1);
        }
    }

    for(auto it : str)
        if(ans.find(it) != ans.end()){
            ans.erase(it);
            printf("%c", it);
        }

    printf("\n%s", str.c_str());
    return 0;
}
