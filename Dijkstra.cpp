#include <bits/stdc++.h>
#define mem(a, b) memset(a, b, sizeof a)
#define inf 0x3f3f3f3f
typedef long long ll;
const int maxn = 200005;
using namespace std;

int n, m, st, ed;

struct qnode {
    int v, c;
    qnode(int _v = 0, int _c = 0) : v(_v), c(_c) {}
    bool operator < (const qnode &r) const {
        return c > r.c;
    }
};

struct Edge {
    int s, c;
    Edge(int _s = 0, int _c = 0) : s(_s), c(_c) {}
};

vector<Edge> vec[maxn];
int dist[maxn];
bool vis[maxn];

void addEdge(int u, int v, int w) {
    vec[u].push_back(Edge(v, w));
    vec[v].push_back(Edge(u, w));
}

void dijk(int st) {
    mem(vis, 0); for(int i = 0; i <= n; i++) dist[i] = inf;
    dist[st] = 0;
    priority_queue<qnode> q; q.push(qnode(st, 0));
    qnode tmp;
    while(!q.empty()) {
        tmp = q.top(); q.pop();
        int u = tmp.v;
        if(!vis[u]) {
            vis[u] = true;
            for(int i = 0; i < vec[u].size(); i++) {
                int v = vec[u][i].s, c = vec[u][i].c;
                if(!vis[v]) {
                    dist[v] = min(dist[v], dist[u]+c);
                    q.push(qnode(v, dist[v]));
                }
            }
        }
    }
}

int main() {
    while(~scanf("%d %d", &n, &m) && (n+m)) {
        for(int i = 0; i <= n; i++) vec[i].clear();
        for(int i = 0; i < m; i++) {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            addEdge(u, v, w);
        }
        st = 1, ed = n;
        dijk(st);
        printf("%d\n", dist[ed]);
    }
    return 0;
}