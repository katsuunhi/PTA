#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;

struct Node{
    int index;
    int data;
    int next;
}node[maxn];
vector<Node> l;

int main(){
    int s, n,k;
    cin >> s >> n >> k;
    for(int i = 0; i < n;i ++){
        int index, data, next;
        scanf("%d%d%d",&index,&data,&next);
        node[index].index = index;
        node[index].data = data;
        node[index].next = next;
    }
    int p = s;
    while(p != -1){
        l.push_back(node[p]);
        p = node[p].next;
    }
    for(int i = 0; i < l.size()/k; i ++){
        reverse(l.begin() + i*k, l.begin()+i*k+k);
    }
    for(int i = 0; i < l.size() - 1; i ++){
        printf("%05d %d %05d\n", l[i].index, l[i].data, l[i+1].index);
    }
    printf("%05d %d -1",l[l.size()-1].index, l[l.size()-1].data);

    return 0;
}
