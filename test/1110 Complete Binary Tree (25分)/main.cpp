//#include <iostream>
//#include <bits/stdc++.h>
//using namespace std;
////
////struct node{
////    int id, l, r;
////}node[21];
//
//vector<int> v;
//bool level(int root){
//    queue<int> q;
//    q.push(root);
//    int now = root;
//    bool flag = 0;
//    while(!q.empty()){
//        now = q.front();
//        q.pop();
//        v.push_back(node[now].id);
//        if(flag){
//            if(node[now].l != -1 || node[now].r != -1)
//                return false;
//        }
//        if(node[now].l == -1)   flag = 1;
//        else    q.push(node[now].l);
//        if(flag && node[now].r != -1)   return false;
//        if(node[now].r == -1)   flag = 1;
//        else    q.push(node[now].r);
//    }
//    return true;
//}
//
//
//int main1()
//{
//    int n, root = 0;
//    freopen("in.txt", "r", stdin);
//    cin >> n;
//    int book[n] = {0};
//    for(int i = 0; i < n; i ++){
//        node[i].id = i;
//        string l, r;
//        cin >> l >> r;
//        if(l != "-"){
//            node[i].l = stoi(l);
//            book[stoi(l)] = 1;
//        }
//        else    node[i].l = -1;
//        if(r != "-"){
//            node[i].r = stoi(r);
//            book[stoi(r)] = 1;
//        }
//        else    node[i].r = -1;
//    }
//    while(book[root] != 0) root ++;
//    bool flag = level(root);
//    if(flag)    cout << "YES " << v[v.size()-1];
//    else    cout << "NO " << root;
//    //printf("%s %d", (level(root)?"YES":"NO"), v[v.size()-1]);
//    return 0;
//}
