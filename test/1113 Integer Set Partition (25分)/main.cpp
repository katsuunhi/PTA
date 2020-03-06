#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, cnt1 = 0, cnt2 = 0;
    long long int sum = 0;
    vector<int> v;
    cin >> n;
    for(int i = 0; i < n; i ++){
        int temp;
        scanf("%d", &temp);
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i ++){
        if(i < n/2){
            sum -= v[i];
            cnt1 ++;
        }
        else{
            sum += v[i];
            cnt2 ++;
        }
    }
    cout << abs(cnt1-cnt2) << " " << sum;
    system("pause");
    return 0;
}
