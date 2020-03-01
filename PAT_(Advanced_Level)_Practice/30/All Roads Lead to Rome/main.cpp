#include <bits/stdc++.h>

using namespace std;
int inf = 999999999;
int n, k;
int e[210][210], dis[210], weight[210], len[210], happy[210], pre[210], cntpath[210];
double avg[210];
bool visit[210];
vector<int>  path;
map<string, int> m;
map<int, string> m2;

int maxvalue = 0, mindepth;

void dfs(int fin){
    path.push_back(fin);
    if(fin == 1)    return;
    dfs(pre[fin]);
}

int main()
{
    fill(e[0], e[0] + 205 * 205, inf);
    fill(dis, dis + 205, inf);
    fill(cntpath, cntpath + 210, 1);
    scanf("%d %d", &n, &k);
    string s;
    cin >> s;
    m[s] = 1;
    m2[1] = s;
    for(int i = 1; i < n; i++) {
        cin >> s >> weight[i+1];
        m[s] = i+1;
        m2[i+1] = s;
    }
    string sa, sb;
    int temp;
    for(int i = 0; i < k; i++) {
        cin >> sa >> sb >> temp;
        e[m[sa]][m[sb]] = temp;
        e[m[sb]][m[sa]] = temp;
    }
//    for(int i = 1; i <= n; i ++){
//        for(int j = 1; j <= n; j ++){
//            cout << e[i][j] << "\t";
//        }
//        cout << endl;
//    }

    dis[1] = 0;
    for(int i = 0; i < n; i ++){
        int u = -1, minn = inf;
        for(int j = 1; j <= n; j ++){
            if(visit[j] == false && dis[j] < minn){
                u = j;
                minn = dis[j];
            }
        }
        if(u == -1) break;
        visit[u] = true;
        for(int v = 1; v <= n; v++){
            if(visit[v] == false && e[u][v] != inf){
                if(dis[v] > dis[u] + e[u][v]){
                    dis[v] = dis[u] + e[u][v];
                    pre[v] = u;
                    len[v] = len[u] + 1;
                    cntpath[v] = cntpath[u];
                    happy[v] = happy[u] + weight[v];
                    avg[v] = happy[v]/(double)len[v];
                }
                else if(dis[v] == dis[u] + e[u][v]){
                        cntpath[v] += cntpath[u];
                        if(happy[v] < happy[u] + weight[v]){
                            pre[v] = u;
                            len[v] = len[u] + 1;
                            happy[v] = happy[u] + weight[v];
                            avg[v] = happy[v]/(double)len[v];
                        }
                        else if(happy[v] == happy[u] + weight[v] && len[v] > len[u] + 1){
                            pre[v] = u;
                            len[v] = len[u] + 1;
                            avg[v] = happy[v]/(double)len[v];
                        }
                }
            }
        }
    }
//    for(int i = 1; i <= n; i ++){
//        cout << pre[i] << "\t";
//    }

    int rom = m["ROM"];
    dfs(rom);
    printf("%d %d %d %d\n", cntpath[rom], dis[rom], happy[rom], happy[rom]/len[rom]);
    for(int i = path.size() - 1; i >= 1; i--) {
        cout << m2[path[i]] << "->";
    }
    cout << "ROM";
    return 0;
}
