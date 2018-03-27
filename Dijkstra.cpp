#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))

const int maxn = 100005;
const int maxm = 10005;

using namespace std;

int n, m;
int s, t;

struct qnode {
    int v, c;

    qnode(int v = 0, int c = 0) : v(v), c(c) {}
    bool operator < (const qnode &r) const {
        return c < r.c;
    }
};

struct Edge {
    int ed, cost;

    Edge(int ed = 0, int cost = 0) : ed(ed), cost(cost) {}
};

vector<Edge> ver[maxn];
int dist[maxn];
bool vis[maxn];

void dijk(int st) {
    mem(dist, inf); mem(vis, 0);
    priority_queue<qnode> pq; while(!pq.empty()) pq.pop();
    dist[st] = 0; pq.push(qnode(st, 0));

    while(!pq.empty()) {
        qnode tmp = pq.top(); po.pop();
        int u = tmp.v;
        if(!vis[u]) {
            vis[u] = true;
            for(int i = 0;i < ver[u].size();i++) {
                int v = ver[u][i].ed;
                int c = ver[u][i].cost;
                if(!vis[v]) {
                    vis[v] = true;
                    dist[v] = min(dist[v], dist[u]+c);
                    pq.push(qnode(v, dist[v]));
                }
            }
        }
    }
}

void addEdge(int u, int v, int w) { // 单向加边
    ver[u].push_back(Edge(v, w));
}

int main() {
    while(scanf("%d %d", &n, &m) != EOF) {
        int u, v, w;
        for(int i = 0;i < n;i++) ver[i].clear();
        for(int i = 0;i < m;i++) {
            scanf("%d %d %d", &u, &v, &w);
            addEdge(u, v, w);
            addEdge(v, u, w);
        }
        s = 1, t = n;
        dijk(s);
        if(dist[t] == inf) printf("-1\n");
        else printf("%d\n", dist[t]);
    }
    return 0;
}
