#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int book[maxn] = {0};
int main()
{
    int n;
    //freopen("in.txt", "r", stdin);
    cin >> n;
    while(n --){
        int temp;
        scanf("%d", &temp);
        if(temp < maxn && temp >0)
            book[temp] = 1;
    }
    int ans = 1;
    while(1){
        if(book[ans] == 0){
            cout << ans;
            return 0;
        }
        ans ++;
    }
    return 0;
}
