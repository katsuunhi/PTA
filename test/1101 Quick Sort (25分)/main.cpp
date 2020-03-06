#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long int> v(n);
    for(int i = 0; i < n; i ++){
        scanf("%d", &v[i]);
    }
    vector<long long int> ans(v);
    set<long long int> s;
    int cnt = 0;
    sort(ans.begin(), ans.end());
    for(int i = 0; i < n; i ++){
        if(ans[i] == v[i]){
            cnt ++;
            s.insert(ans[i]);
        }
    }
    cout << cnt << endl;
    bool start = true;
    for(auto it : s){
        if(start)   printf("%d", it);
        else    printf(" %d", it);
        start = false;
    }
    return 0;
}
