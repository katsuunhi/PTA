#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    map<char, int> m1, m2;
    int miss = 0, flag = 0;
    string str1, str2;
    freopen("in.txt", "r", stdin);
    cin >> str1 >> str2;
    for(auto ch:str1)   m1[ch] ++;
    for(auto ch:str2)   m2[ch] ++;
    for(auto m:m2){
        if(m1.find(m.first) == m1.end()){
            miss += m.second;
            flag = 1;
        }
        else if(m1[m.first] < m.second){
            miss += m.second - m1[m.first];
            flag = 1;
        }
    }
    printf("%s %d", flag ? "No" : "Yes", flag ? miss : str1.size()-str2.size());
    return 0;
}
