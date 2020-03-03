#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int f(int n){
    if(n < 10) return n;
    else    return f(n/10) + n%10;
}

int main()
{
    int n;
    set<int> s;
    freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i ++){
        int temp;
        scanf("%d", &temp);
        s.insert(f(temp));
    }
    cout << s.size() << endl;
    bool start = true;
    for(auto x:s){
        if(start)   printf("%d", x);
        else    printf(" %d", x);
        start = false;

    }
    return 0;
}
