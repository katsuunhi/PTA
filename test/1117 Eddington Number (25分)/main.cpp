#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, e = 0;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; i ++){
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end(), greater<int>());
    for(int i = 0; i < n; i ++){
        if(v[i] > i + 1)
            e = i;
    }
    cout << e;
    system("pause");
    return 0;
}
