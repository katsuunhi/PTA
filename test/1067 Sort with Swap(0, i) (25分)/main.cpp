#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, cnt = 0;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i ++) cin >> v[i];
    for(int i = 0; i < n; i ++){
        if(v[i] != i){
            while(v[0] != 0){
                swap(v[0],v[v[0]]);
                cnt ++;
            }
        }
        if(v[i] != i){
            swap(v[0], v[i]);
            cnt ++;
        }
    }
    cout << cnt;
}
