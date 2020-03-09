#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool judge(string str){
    string temp = str;
    reverse(str.begin(), str.end());
    if(temp == str)
        return true;
    return false;
}

string itos(int a){
    stringstream ss;
    string str;
    ss << a; ss >> str;
    return str;
}

string add(string a, string b){
    string s = a;
    int carry = 0;
    for(int i = a.size()-1; i >= 0; i --){
        s[i] = (a[i] - '0' + b[i] - '0' + carry)%10 + '0';
        carry = (a[i] - '0' + b[i] - '0' + carry)/10;
    }
    if(carry > 0)
        s = "1" + s;
    return s;
}

int main()
{
    string n, ans;
    int cnt = 0;
    cin >> n;

    if(stoi(n) < 10){
        cout << n << " is a palindromic number.";
        return 0;
    }
    while(!judge(n)){
        cnt ++;
        if(cnt == 11)
            break;
        string temp = n;
        reverse(n.begin(), n.end());
        ans = add(n, temp);
        cout << temp << " + " << n << " = " << ans << endl;
        n = ans;
    }

    if(cnt == 11){
        cout << "Not found in 10 iterations.";
    }
    else{
        cout << ans << " is a palindromic number.";
    }
    return 0;
}
