#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
struct Node{
    int index;
    int data;
    int next;
}node[maxn];
bool book[10000]={false};
vector<Node> l1, l2;

int main()
{
    int s, n;
    freopen("in.txt", "r", stdin);
    cin >> s >> n;
    for(int i = 0;i<n;i++){
        int index,data,next;
        scanf("%d%d%d",&index,&data,&next);
        node[index].index = index;
        node[index].data=data;
        node[index].next=next;
     }
     int p=s;
     while(p!=-1){
        if(book[abs(node[p].data)] == false){
            book[abs(node[p].data)] = true;
            l1.push_back(node[p]);
        }
        else{
            l2.push_back(node[p]);
        }
        p = node[p].next;
     }

     for(int i=0;i<l1.size()-1;i++){
        printf("%05d %d %05d\n", l1[i].index, l1[i].data, l1[i+1].index);
     }
     printf("%05d %d -1", l1[l1.size()-1].index, l1[l1.size()-1].data);
     if(l2.size() >0){
        cout << "\n";
        for(int i=0;i<l2.size()-1;i++){
            printf("%05d %d %05d\n", l2[i].index, l2[i].data, l2[i+1].index);
        }
        printf("%05d %d -1", l2[l2.size()-1].index, l2[l2.size()-1].data);
     }
    return 0;
}
