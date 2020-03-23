#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct node{
    int index, l, r;
    string data;
}l[21];
int flag = 1;
void in(int root){
    if(root == -1)  return;
    if(flag){
        flag = 0;
        in(l[root].l);
    //cout << "test" << endl;
        printf("%s", l[root].data.c_str());
        in(l[root].r);
        return;
    }
    else{
        if(l[root].r != -1 || l[root].l != -1)
            cout << "(";
        in(l[root].l);
        //cout << "test" << endl;
        printf("%s", l[root].data.c_str());
        in(l[root].r);
        if(l[root].r != -1 || l[root].l != -1)
            cout << ")";
        return;
    }
}

int main()
{
    int n, book[21] = {0}, root = 1;
    freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> l[i].data >> l[i].l >> l[i].r;
        //scanf("%c%d%d", &l[i].data, &l[i].l, &l[i].r);
        //cout << l[i].data << l[i].l << l[i].r << endl;
        if(l[i].l != -1)    book[l[i].l] = 1;
        if(l[i].r != -1)    book[l[i].r] = 1;
    }
    while(book[root] == 1)  root ++;
    //cout << root << l[root].r << endl;
    in(root);
    return 0;
}
