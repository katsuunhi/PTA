#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string itos(int a){
    //stringstream ss;
    char str[40];
    sprintf(str, "%d", a);
    //string str;
    //ss << a; ss >> str;
    return str;
}

int main()
{
    int n, cnt = 0;
    cin >> n;
    for(int i = 0; i <= n; i ++){

        for(auto it : itos(i)){
            if(it == '1')   cnt ++;
        }
    }
    cout << cnt;
    return 0;
}
