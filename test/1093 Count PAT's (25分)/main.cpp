#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int cntp = 0, cnta = 0, cntt = 0, ans = 0;
    cin >> str;
    for(auto it : str)  if(it == 'T')   cntt ++;
    for(auto it : str){
        if(it == 'P')   cntp ++;
        if(it == 'T')   cntt --;
        if(it == 'A'){
            ans += cntp*cntt;
            ans %= 1000000007;
        }
    }
    cout << ans;
    return 0;
}
