#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int v[10010][10010] ={0};
int l[10010] = {0};
int cnt = 0;
void f(int a, int b, int c, int d){
    for(int i = b; i <= d; i ++)
        v[a][i] = l[cnt++];
    for(int i = a+1; i <= c; i ++)
        v[i][d] = l[cnt++];
    for(int i = d-1; i >= b; i --)
        v[c][i] = l[cnt++];
    for(int i = c-1; i >= a+1; i --)
        v[i][b] = l[cnt++];
}

int main()
{
    int n;
    freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> l[i];
    sort(l, l + n, greater<int>());
    int a = 0, b = 0, c, d;
    for(d = sqrt((double)n); d >= 1; d --){
        if(n % d == 0){
            c = n/d;
            break;
        }
    }
    c--;d--;
    if(d == 0){
        for(int i = 0; i < n; i ++)
        cout << l[i] << endl;
        return 0;
    }

    int C = c, D = d;
    while(b <= d){
        f(a, b, c, d);
        a++;b++;c--;d--;
    }
    for(a = 0; a <= C; a ++){
        for(b = 0; b <= D; b ++){
            if(b == 0) cout << v[a][b];
            else    cout << " " << v[a][b];
        }
        cout << endl;
    }
    return 0;
}
