#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a;
    cin >> b;
    int c;
    c = a + b;
    int ans[31];
    int d;
    int num = 0;
    cin >> d;
    do{
        ans[num ++] = c%d;
        c = c/d;
    }while(c != 0);
    for(int i = num - 1; i >= 0; i --)
        cout << ans[i];
    return 0;
}
