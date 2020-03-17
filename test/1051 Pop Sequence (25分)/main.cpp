#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    freopen("in.txt", "r", stdin);
    cin >> a >> b >> c;

    for(int i = 0; i < c; i ++){
        stack<int> s;
        vector<int> v(b + 1);
        int flag = false, num = 1;
        for(int j = 1; j <= b; j ++)    scanf("%d", &v[j]);
        for(int j = 1; j <= b; j ++){
            s.push(j);
            if(s.size() > a)    break;
            while(!s.empty() && v[num] == s.top()){
                s.pop();
                num ++;
            }
        }
        if(num == b + 1)    flag = true;
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
