#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int book[maxn] = {0};
int main()
{
    int n;

    freopen("in.txt", "r", stdin);
    cin >> n;
    int a, b;
    for(int i = 0; i < n; i ++){

        scanf("%d%d", &a, &b);
        cout << a << b<<endl;
        book[a] = b;
        book[b] = a;
    }

    int k;
    cin >> k;
    set<int> s;
    for(int i = 0; i < k; i ++){
        int temp;
        scanf("%d", &temp);
        if(s.find(book[temp]) != s.end()){
            s.erase(book[temp]);
        }
        else    s.insert(temp);
    }
    cout << s.size() << endl;
    bool start = true;
    for(auto x:s){
        if(start)   printf("%05d", x);
        else    printf(" %05d", x);
        start = false;
    }
    return 0;
}
