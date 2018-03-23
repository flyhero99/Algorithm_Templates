// 单源最短路 spfa
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define mod 1000000007
#define mem(a,b) memset(a,b,sizeof(a))

const int maxn = 1010;

vector<Edge> ver[maxn]; // 邻接表存图
bool vis[maxn]; // 是否在队列
int cnt[maxn];  // 每个顶点的入队列次数，用于判定是否存在负环回路
int dist[maxn]; // 距离数组
int n, m; // n个顶点，m条边

struct Edge {
    int v, cost;

    Edge(int v, int cost) {
        this.v = v;
        this.cost = cost;
    }
}

void addEdge(int u, int v, int w) {
    ver[u].push_back(Edge(v, w));
}

bool spfa(int st) {
    mem(dist, inf); dist[st] = 0; vis[st] = true; cnt[st] = 1;
    queue<int> q; q.push(st);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for(int i = 0;i < ver[u].size();i++) {
            int v = ver[u][i].v;
            int c = ver[u][i].c;
            if(dist[u] > dist[v]+c) {
                dist[u] = dist[v] + c;
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                    if(++cnt[v] > n) return false; // 判定负环回路
                }
            }
        }
    }
    return true;
}

int main() {
    while(scanf("%d %d", &n, &m) != EOF) {
        for(int i = 0;i <= n;i++) ver[i].clear();
        int u, v, w;
        for(int i = 0;i < m;i++) {
            cin >> u >> v >> w;
            addEdge(u, v, w);
        }
        int start = 1;
        spfa(start);
        cout << dist[n] << endl;
    }
    return 0;
}