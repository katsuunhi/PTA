#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main2()
{
    long int n;
    vector<long int> v;
    freopen("in.txt", "r", stdin);
    cin >> n;
    while(n --){
        long int temp;
        scanf("%ld", &temp);
        v.push_back(temp);
    }
    cin >> n;
    while(n --){
        long int temp;
        scanf("%ld", &temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    printf("%ld", v[(v.size()-1)/2]);
    return 0;
}
