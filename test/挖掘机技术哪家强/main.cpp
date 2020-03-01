#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    const int maxn = 100010;
    int school[maxn] = {0};
    int n;
    int max = -1;
    int k = -1;
    cin >> n;
//    int school[n + 1] = {0};
    int num, grade;
    for(int i = 0; i < n; i ++){
        cin >> num;
        cin >> grade;
        school[num] += grade;
        if(school[num] > max){
            max = school[num];
            k = num;
        }
    }
    cout << k << " " << max;
    return 0;
}
