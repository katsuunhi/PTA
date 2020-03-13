#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 10010;
struct node{
    int id;
    string name;
    int grade;
}l[maxn];

bool cmp1(node a, node b){
    return a.id < b.id;
}

bool cmp2(node a, node b){
    return a.name != b.name ? a.name < b.name : a.id < b.id;
}

bool cmp3(node a, node b){
    return a.grade != b.grade ? a.grade < b.grade : a.id < b.id;
}

int main()
{
    int n, c;
    freopen("in.txt", "r", stdin);
    cin >> n >> c;
    for(int i = 0; i < n; i ++){
        cin >> l[i].id >> l[i].name >> l[i].grade;
    }
    if(c == 1)  sort(l, l + n, cmp1);
    if(c == 2)  sort(l, l + n, cmp2);
    if(c == 3)  sort(l, l + n, cmp3);
    for(int i = 0; i < n ; i ++){
        printf("%06d %s %d\n", l[i].id, l[i].name.c_str(), l[i].grade);
    }
    return 0;
}
