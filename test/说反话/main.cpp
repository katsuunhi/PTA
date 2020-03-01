#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num = 0;
    char str[90][90];
    freopen("in.txt", "r", stdin);
    while(scanf("%s", str[num]) != EOF){
        num ++;
    }
    num --;
    while(num > 0){
        printf("%s ", str[num--]);
    }
    printf("%s", str[num]);
    return 0;
}
