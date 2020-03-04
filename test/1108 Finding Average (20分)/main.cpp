#include <iostream>
#include <bits/stdc++.h>
using namespace std;

float str_to_f(string str){
    stringstream ss;
    float a;
    ss << str; ss >> a;
    return a;
}

string f_to_str(float a){
    stringstream ss;
    string str;
    ss << a; ss >> str;
    return str;
}

int main()
{
    char ch[20], str[20];
    //string ch, str;
    int n, cnt = 0, flag = 0;
    float sum = 0;

    freopen("in.txt", "r", stdin);
    cin >> n;
    for(int i = 0; i < n; i ++){
        double f;
        int flag = 0;


        scanf("%s", ch);
        sscanf(ch, "%lf", &f);
        sprintf(str, "%.2f", f);
        int j = 0;
        while(ch[j] != '\0'){
            if(str[j] != ch[j]){
                flag = 1;
                break;
            }
            j++;
        }
        if(flag || f > 1000 || f < -1000)
            printf("ERROR: %s is not a legal number\n", ch);
        else{
            cnt ++;
            sum += f;
        }


    }
    if(cnt == 1)
        printf("The average of 1 number is %.2f", sum/cnt);
    else if(cnt > 1)
        printf("The average of %d numbers is %.2f", cnt, sum/cnt);
    else
        printf("The average of 0 numbers is Undefined");
    return 0;
}
