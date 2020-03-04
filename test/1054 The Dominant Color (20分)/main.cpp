#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n , cnt = 0, ans = -1;
    freopen("in.txt", "r", stdin);
    cin >> m >> n;
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++){
            int temp;
            scanf("%d", &temp);
            if(temp == ans)
                cnt ++;
            else if(cnt > 1)
                cnt --;
            else if(cnt <= 1){
                ans = temp;
            }
        }
    }
    cout << ans;
    return 0;
}
