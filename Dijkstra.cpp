#include <bits/stdc++.h>
#define MOD 1000000007
#define inf 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;

const int maxn = 200005;

int n, m;
int st, ed;

struct qnode {
    int v, c;
    qnode(int v = 0, int c = 0) : v(v), c(c) {}
    bool operator < (const qnode &r) const {
        return c > r.c ;
    }
};

struct Edge {
    int start, cost;
    Edge(int start = 0 , int cost = 0) : start(start), cost(cost) {}

};

vector <Edge> vec[maxn] ;
bool vis[maxn];
int dist[maxn];

void dijk(int st) {
    mem(vis, 0);
    for(int i = 0; i <= n; i++) dist[i] = inf;
    priority_queue<qnode> pq; while(!pq.empty()) pq.pop();
    dist[st] = 0; pq.push(qnode(st, 0));
    qnode tmp;
    while(!pq.empty()) {
        tmp = pq.top(); pq.pop();
        int u = tmp.v;
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = 0; i < vec[u].size(); i++) {
            int v = vec[u][i].start;
            int cost = vec[u][i].cost;
            if(!vis[v]) {
                dist[v] = min(dist[v], dist[u]+cost);
                pq.push(qnode(v, dist[v]));
            }
        }
    }
}

void addedge(int u, int v, int w) { // µ¥Ïò¼Ó±ß
    vec[u].push_back(Edge(v,w));
}

int main() {
    int cas; cin >> cas;
    while(cas--) {
        scanf("%d %d", &n, &m);
        for(int i = 0; i <= n; i++) vec[i].clear();
        int u, v, w;
        for(int i = 0; i < m; i++) {
            scanf("%d %d %d", &u, &v, &w);
            addedge(u, v, w);
        }
        st = 1, ed = n;
        dijk(st);
        printf("%d\n", dist[ed]);
    }
    return 0;
}
