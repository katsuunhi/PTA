#include<bits/stdc++.h>
using namespace std;

int e[510][510], w[510][510], dis[510], dispre[510], weight[510], Time[510], timepre[510], NodeNum[510], visit[510];
int st, fin, inf = 999999999;
vector<int> dans, tans;

void dbfs3(int fin){
    dans.push_back(fin);
   // cout << fin << "\t";
    if(fin == st)   return;
    //dbfs(dispre[fin]);
}
void dbfs(int v) {
    dans.push_back(v);
    if(v == st) return ;
    dbfs(dispre[v]);
}

void tbfs(int fin){
    tans.push_back(fin);
    if(fin == st)   return;
    tbfs(timepre[fin]);
}

int main(){
    fill(e[0], e[0] + 510, inf);
    fill(w[0], w[0] + 510, inf);
    fill(dis, dis + 500, inf);
    fill(Time, Time + 510, inf);
    int n, m;
    cin >> n >> m;
    int a, b, flag, len, t;
    for(int i = 0; i < m; i ++){
        cin >> a >> b >> flag >> len >> t;
        e[a][b] = len;
        w[a][b] = t;
        if(!flag){
            e[b][a] = len;
            w[b][a] = t;
        }
    }
    int st, fin;
    cin >> st >> fin;

    dis[st] = 0;
    for(int i = 0; i < n; i ++){
        dispre[i] = i;
    }
    for(int i = 0; i < n; i ++){
        int u = -1, mmin = inf;
        for(int j = 0; j < n; j ++){
            if(visit[j] == 0 && dis[j] < mmin){
                u = j;
                mmin = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = 1;
        for(int v = 0; v < n; v ++){
            if(visit[v] == 0 && e[u][v] != inf){
                if(dis[v] > e[u][v] + dis[u]){
                    dis[v] = e[u][v] + dis[u];
                    dispre[v] = u;
                    weight[v] = weight[u] + w[u][v];
                }else if(e[u][v] + dis[u] == dis[v] && weight[v] > weight[u] + w[u][v]){
                    dispre[v] = u;
                    weight[v] = weight[u] + w[u][v];
                }
            }
        }
    }
    dbfs(fin);
    fill(visit, visit + 510, 0);
    Time[st] = 0;
    for(int i = 0; i < n; i ++){
        int u = -1, mmin = inf;
        for(int j = 0; j < n; j ++){
            if(visit[j] == 0 && Time[j] < mmin){
                u = j;
                mmin = Time[j];
            }
        }
        if(u == -1) break;
        visit[u] = 1;
        for(int v = 0; v < n; v ++){
            if(visit[v] == 0 && w[u][v] != inf){
                if(w[u][v] + Time[u] < Time[v]){
                    Time[v] = w[u][v] + Time[u];
                    timepre[v] = u;
                    NodeNum[v] = NodeNum[u] + 1;
                }else if(w[u][v] + Time[u] == Time[v] && NodeNum[v] > NodeNum[u] + 1){
                    timepre[v] = u;
                    NodeNum[v] = NodeNum[u] + 1;
                }
            }
        }
    }
    for(int i = 0; i < n; i ++)
        cout << dispre[i] << "\t";

    tbfs(fin);
    if(dans == tans){
        cout << "Distance = "<< dis[fin] << "; Time = "<< Time[fin] <<": " << dans[dans.size() - 1];
        for(int i = dans.size() - 2; i >= 0; i --)
            cout << " -> " << dans[i];
        return 0;
    }
    cout << "Distance = "<< dis[fin] <<": " << dans[dans.size() - 1];
    for(int i = dans.size() - 2; i >= 0; i --)
        cout << " -> " << dans[i];
    cout << endl;
    cout << "Time = "<< Time[fin] <<": " << tans[tans.size() - 1];
    for(int i = tans.size() - 2; i >= 0; i --)
        cout << " -> " << tans[i];

    return 0;
}
