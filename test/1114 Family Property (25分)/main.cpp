#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;
struct Person{
    int rootid;
    int sets;
    int area;
    int num;
    bool flag = false;
}father[maxn];

struct ans{
    int id;
    float sets;
    float area;
    int num;
};

bool cmp(struct ans a, struct ans b){
    if(a.area != b .area)
        return a.area > b.area;
    return a.id < b.id;
}


void init(){
    for(int i = 1; i <= maxn; i ++){
        father[i].rootid = i;
        father[i].num = 1;
    }
}

int findfather(int a){
    if(father[a].rootid == a)  return a;
    else{
        int f = findfather(father[a].rootid);
        father[a].rootid = f;
        return f;
    }
}

void Union(int a, int b){
    int fa = findfather(a);
    int fb = findfather(b);
    if(fa > fb){
        cout << fb <<" is the root of "<< fa << endl;
        father[fa].rootid = fb;
        father[fb].sets += father[fa].sets;
        father[fb].area += father[fa].area;
        father[fb].num += father[fa].num;
    }
    else if(fa < fb){
        cout << fa
        <<" is the root of "<< fb << endl;
        father[fb].rootid = fa;
        father[fa].sets += father[fb].sets;
        father[fa].area += father[fb].area;
        father[fa].num += father[fb].num;
    }
}



int main()
{
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    init();
    for(int i = 0; i < n; i ++){
        int id, f, m, k, sets, area;
        int ks[5];
        scanf("%d%d%d%d", &id, &f, &m, &k);
        for(int j = 0; j < k; j ++){
            scanf("%d", &ks[j]);
        }
        scanf("%d%d", &sets, &area);
        father[id].sets += sets;
        father[id].area += area;
        father[id].flag = true;
        if(father[id].rootid != id){
            father[findfather(id)].sets += sets;
            father[findfather(id)].area += area;
        }
        if(f != -1){
            father[f].flag = true;
            Union(id, f);
        }
        if(m != -1){
            father[m].flag = true;
            Union(id, m);
        }
        for(int j = 0; j < k; j ++){
            father[j].flag = true;
            Union(id, ks[j]);
        }
    }
    int num = 0;
    cout << father[8888].rootid;
    for(int i = 1; i <= maxn; i ++){
        if(father[i].rootid == i && father[i].flag == true)
            num ++;
    }
    cout << num;
    int nu = num;
    struct ans a[num];
    for(int i = 1; num > 0; i ++){
        if(father[i].rootid == i && father[i].flag){
            num --;
            a[num].id = i;
            a[num].num = father[i].num;
            a[num].sets = father[i].sets/(float)father[i].num;
            a[num].area = father[i].area/(float)father[i].num;
 //           printf("\n%04d %d %.3f %.3f, %d, %d", i, father[i].num, father[i].sets/(float)father[i].num, father[i].area/(float)father[i].num, father[i].sets, father[i].area);
        }

    }
    sort(a , a + nu,cmp);
    for(int i = 0; i < nu; i ++){
        printf("\n%04d %d %.3f %.3f", a[i].id, a[i].num, a[i].sets, a[i].area);
    }
    fclose(stdin);
    return 0;
}
