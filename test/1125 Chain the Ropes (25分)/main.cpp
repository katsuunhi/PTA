#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    vector<int> v;
    while(n--){
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    ans = v[0];
    for(int i = 1; i < v.size(); i ++){
        ans = (ans + v[i])/2;
    }
    cout << ans;
    system("pause");
    return 0;
}
