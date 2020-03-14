#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct node{
    string name, id;
    int grade;
}l[maxn];

bool cmp(node a, node b){
    return a.grade > b.grade;
}

int main()
{
    int n, low, high;
    freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i ++){
        cin >> l[i].name >> l[i].id >> l[i].grade;
    }
    cin >> low >> high;

    sort(l, l + n, cmp);
    vector<node> ans;
    for(int i = 0; i < n; i ++){
        if(l[i].grade >= low && l[i].grade <= high)
            ans.push_back(l[i]);
    }

    if(ans.size() == 0)
        cout << "NONE";
    else
    for(auto it : ans)
        cout << it.name << " " << it.id << endl;
    return 0;
}
