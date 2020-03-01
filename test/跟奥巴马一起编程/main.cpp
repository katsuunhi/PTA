#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    char ch;
    cin >> n;
    cin >> ch;
    int line = (int)(n/2.0 + 0.5) - 2;
    for(int i = 0; i < n; i ++)
        cout << ch;
    for(; line > 0; line --){
        cout << endl << ch;
        for(int i = 0; i < n - 2; i ++) cout << " ";
        cout << ch;
    }
    cout << endl;
    for(int i = 0; i < n; i ++)
        cout << ch;
    return 0;
}
