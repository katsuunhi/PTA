#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
    string str;
    int month;
    int day;
    int hour;
    int minute;
    int type;
}l[1010];

double bill(node call, int *cost){
    double total = cost[call.hour]*call.minute + cost[24]*60*call.day;
    for(int i = 0; i < call.hour; i ++)
        total += cost[i]*60;
    return total/100.0;
}

bool cmp(node a, node b){
    if(a.str != b.str)  return a.str < b.str;
    else if(a.day != b.day) return a.day < b.day;
    else if(a.hour != b.hour)   return a.hour < b.hour;
    else if(a.minute != b.minute)   return a.minute < b.minute;
    //else  return a.type < b.type;
}

int main()
{
    int n, cost[25] = {0};
    freopen("in.txt", "r", stdin);
    for(int i = 0; i < 24; i ++){
        cin >> cost[i];
        cost[24] += cost[i];
    }
    cin >> n;

    for(int i = 0; i < n; i ++){
       // char temp[10];
        string temp;
        cin >> l[i].str;
        scanf("%d:%d:%d:%d", &l[i].month, &l[i].day, &l[i].hour, &l[i].minute);
        cin >> temp;
      //  cout << temp <<endl;
        if(temp[1] == 'n')  l[i].type = 0;
        else    l[i].type = 1;
    }
    sort(l, l + n, cmp);
    map<string, vector<node> > custom;
    for(int i = 1; i < n; i ++){
        if(l[i].str == l[i-1].str && l[i].type == 1 && l[i-1].type == 0){
            custom[l[i].str].push_back(l[i-1]);
            custom[l[i].str].push_back(l[i]);
        }
    }
    for(auto it : custom){
        vector<node> temp = it.second;
        cout << it.first;
        printf(" %02d\n", temp[0].month);
        double total = 0.0;
        for(int i = 1; i < temp.size(); i += 2){
            double t = bill(temp[i], cost) - bill(temp[i-1], cost);
            int t1, t2;
            total += t;
            t1 = temp[i-1].day*24*60 + temp[i-1].hour*60 + temp[i-1].minute;
            t2 = temp[i].day*24*60 + temp[i].hour*60 + temp[i].minute;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute, temp[i].day, temp[i].hour, temp[i].minute, t2-t1, t);
        }
        printf("Total amount: $%.2f\n", total);
    }

    return 0;
}
