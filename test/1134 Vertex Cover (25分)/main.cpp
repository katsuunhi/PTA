#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, k;
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    vector<pair<int, int>> v;
    int book[10010] = {0};
    for(int i = 0; i < m; i ++){
        int a, b;
        scanf("%d%d", &a, &b);
        v.push_back({a, b});
    }
    cin >> k;
    for(int i = 0; i < k; i ++){
        int num, flag = 0;
        scanf("%d", &num);
        int book[10010] = {0};
        for(int j = 0; j < num; j ++){
            int temp;
            scanf("%d", &temp);
            book[temp] = 1;
        }
        for(auto it : v){
            if(book[it.first] == 0 && book[it.second] == 0){
                //cout << it.first << " " << it.second << endl;
                flag = 1;
                break;
            }
        }
        printf("%s\n", (flag ? "No" : "Yes"));
    }
    return 0;
}
