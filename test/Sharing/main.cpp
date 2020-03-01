    #include <iostream>
    #include <bits/stdc++.h>
    using namespace std;

    const int maxn = 100010;

    struct Node{
        char data;
        int next;
        bool flag = false;
    }node[maxn];

    int main()
    {
        int s1, s2, n;
        freopen("in.txt", "r", stdin);
        //freopen("out.txt", "w", stdout);
        cin >> s1 >> s2 >> n;
        int index, next;
        char ch;
        int p;
        for(int i = 0; i < n; i ++){
            scanf("%d %c %d", &index, &ch, &next);
            node[index].data = ch;
            node[index].next = next;
        }
        for(p = s1; p != -1; p = node[p].next){
            node[p].flag = true;
        }
        for(p = s2; p != -1; p = node[p].next){
            if(node[p].flag)    break;
        }
        if(p != -1) printf("%05d", p);
        else cout << "-1";
        return 0;
    }
