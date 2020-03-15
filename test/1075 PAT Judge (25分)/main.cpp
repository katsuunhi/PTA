#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int maxn1 = 10010;
const int maxn2 = 100010;
int p[maxn2] = {0};
struct node{
    int r, id, score = 0;
    vector<int> p;
    int cnt = 0;
    bool flag = false;
}l[maxn1];

bool cmp(node a, node b){
    if(a.score != b.score)  return a.score > b.score;
    else if(a.cnt != b.cnt) return a.cnt > b.cnt;
    else return a.id < b.id;
}

int main()
{
    int m, n, t;
    freopen("in.txt", "r", stdin);
    cin >> m >> n >> t;
    for(int i = 1; i <= n; i ++)
        cin >> p[i];
    for(int i = 1; i <= m; i ++)
        l[i].p.resize(n + 1, -1);
    for(int i = 0; i < t; i ++){
        int id, num, score;
        cin >> id >> num >> score;
        l[id].id = id;
        if(score > l[id].p[num])
            l[id].p[num] = score;
        if(score != -1) l[id].flag = true;
        else if(l[id].p[num] == -1) l[id].p[num] = -2;

    }
    for(int i = 1; i <= m; i ++){
        for(int j = 1; j <= n; j ++){
            if(l[i].p[j] != -1 && l[i].p[j] != -2)
                l[i].score += l[i].p[j];
            if(l[i].p[j] == p[j])
                l[i].cnt ++;
        }
    }
    sort(l + 1, l + m + 1, cmp);
    l[1].r = 1;
    for(int i = 2; i <= m; i ++){
        if(l[i].score == l[i - 1].score)    l[i].r = l[i-1].r;
        else    l[i].r = i;
    }
    for(int i = 1; i <= m; i ++){
        if(l[i].flag){
            printf("%d %05d %d", l[i].r, l[i].id, l[i].score);
            for(int j = 1; j <= n; j ++){
                if(l[i].p[j] != -1 && l[i].p[j] != -2)
                    cout << " " << l[i].p[j];
                else if(l[i].p[j] == -1)
                    cout << " -";
                else
                    cout << " 0";
            }
            cout << endl;
        }
    }
    return 0;
}
