#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
struct node{
    string name;
    int height;
}l[maxn];
bool cmp(node a, node b){
    if(a.height != b.height)
        return a.height > b.height;
    return a.name < b.name;
    //return (a.height != b.height) ? (a.height > b.height) : (a.name < b.name);
}


int main()
{
    int n, k, cnt = 0, numl = 1, numr = 2;
    freopen("in.txt", "r", stdin);
    cin >> n >> k;
    vector<string> r[k];
    for(int i = 0; i < n; i ++)
        cin >> l[i].name >> l[i].height;

    sort(l, l + n, cmp);
    //×öºóÒ»ÅÅ
//    for(int i = 0; i < n; i ++){
//        cout << l[i].name << " ";
//    }
//    cout << endl;
    cnt = n - n/k*(k-1);
    int cen = cnt/2 + 1;
    r[0].resize(cnt);
    r[0][cen - 1] = l[0].name;

    for(int i = cen - 2; i >= 0; i --){
        r[0][i] = l[numl].name;
        numl += 2;
    }
    for(int i = cen; i < cnt; i ++){
        r[0][i] = l[numr].name;
        numr += 2;
    }


    cnt = n/k;
    int line = k-1;
    cen = cnt/2 + 1;
    for(int i = 1; i <= line; i ++){
        r[i].resize(cnt);
        int num = min(numr, numl);
        r[i][cen - 1] = l[num].name;
        numl = num + 1;
        numr = num + 2;
        for(int j = cen - 2; j >= 0; j --){
            r[i][j] = l[numl].name;
            numl += 2;
        }
        for(int j = cen; j < cnt; j ++){
            r[i][j] = l[numr].name;
            numr += 2;
        }
    }
    for(int i = 0; i < k; i ++){
        bool start = true;
        for(auto it : r[i]){
            if(start)
                cout << it;
            else
                cout << " " << it;
            start = false;
        }
        cout << endl;
        start = true;
    }
    return 0;
}
