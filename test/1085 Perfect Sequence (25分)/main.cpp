#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long int n, p, cnt = 0;
    int flag = 0;
    freopen("in.txt", "r", stdin);
    cin >> n >> p;
    vector<long int> v(n);
    for(long int i = 0; i < n; i ++)
        cin >> v[i];
    sort(v.begin(), v.end());
    long int i = 0, j = 0;
    while(i < n && j < n){
        while(j < n && v[j] <= v[i]*p){
            cnt = max(cnt, j - i + 1);
            j ++;
        }
        i ++;
    }
    cout << cnt;
    return 0;
}
