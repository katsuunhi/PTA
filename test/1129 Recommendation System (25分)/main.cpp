#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 50010;
struct node{
    int value;
    int cnt;
    node(int a, int b): value(a), cnt(b){}
    bool operator < (const node &a) const {
        return (cnt != a.cnt) ? cnt >a.cnt : value < a.value;
    }
};
int book[maxn] = {0};
int main()
{
    int n, k, num;

    freopen("in.txt", "r", stdin);
    cin >> n >> k;
    set<node> s;
    for(int i = 0; i < n; i ++){
        scanf("%d", &num);
        if(i != 0){
            printf("%d:", num);
            int tempcnt = 0;
            for(auto it = s.begin();it != s.end() && tempcnt < k; it ++){
                printf(" %d", it->value);
                tempcnt ++;
            }
            printf("\n");
        }
        auto it = s.find(node(num, book[num]));
        if(it != s.end())
            s.erase(it);
        book[num] ++;
        s.insert(node(num, book[num]));
    }

    return 0;
}
