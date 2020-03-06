#include <bits/stdc++.h>
using namespace std;
vector<long int> v1, v2;
int main(){
    long int n, m, temp, cnt = 0, p = 0;
    freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i ++){
        scanf("%ld", &temp);
        v1.push_back(temp);
    }
    cin >> m;
    for(int i = 0; i < m; i ++){
        scanf("%ld", &temp);
        while(temp > v1[p] && cnt < (m+n+1)/2 && p < n){
            cnt ++;
            if(cnt == (m+n+1)/2){
                cout << v1[p];
            }
            p ++;
        }
        cnt ++;
        if(cnt == (m+n+1)/2){
            cout << temp;
            return 0;
        }
    }
    while(p <= n){
        cnt ++;
        if(cnt == (m+n+1)/2) cout << v1[p];
        p ++;
    }
    return 0;
}
