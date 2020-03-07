#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int index;
    int left;
    int right;
}t[13];
bool start = true;
void in(int root){
    if(root == -1)  return;
    in(t[root].left);
    if(start)   printf("%d", t[root].index);
    else    printf(" %d", t[root].index);
    start = false;
    in(t[root].right);
}
void level(int root){
    queue<int> q;
    q.push(root);
    start = true;
    while(!q.empty()){
        int now = q.front();
        q.pop();
        printf("%s%d", start ? "" : " ", now);
        start = false;
        if(t[now].left != -1)   q.push(t[now].left);
        if(t[now].right != -1)   q.push(t[now].right);
    }
}


int main1()
{
    int n, root;
    freopen("in.txt", "r", stdin);
    cin >> n;
    int book[n] = {0};
    for(int i = 0; i < n; i ++){
        t[i].index = i;
        t[i].left = -1;
        t[i].right = -1;
        string right, left;
        cin >> right >> left;
        if(right != "-"){
            t[i].right = stoi(right);
            book[stoi(right)] = 1;
            //cout << i << " r " << stoi(right) << book[stoi(right)] << endl;
        }
        if(left != "-"){
            t[i].left = stoi(left);
            book[stoi(left)] = 1;
            //cout << i << " l " << left << endl;
        }
    }

    for(int i = 0; i < n; i ++){
        //cout << i << " " << book[i] << endl;
        if(book[i] == 0){
            //cout << i << "   " << book[i];
            root = i;
        }
    }
    //cout << "root is " << root << endl;
    //in(root);
    level(root);
    cout << endl;
    start = true;
    in(root);
    return 0;
}
