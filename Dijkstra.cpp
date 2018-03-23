#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define INF 0x3f3f3f3f
#define mem(a,b) memset(a,b,sizeof(a))

const int maxn = 100005;
const int maxm = 10005;

using namespace std;

int point, road;
int u, v, w, st, ed;

struct qnode{
    int v, c;
    qnode(int tempv = 0, int tempc = 0) : v(tempv), c(tempc) {}
    bool operator < (const qnode &r) const {
        return c > r.c;
    }
};

struct Edge {
    int start, cost;
    Edge(int tempstart = 0, int tempcost = 0 ) : start(tempstart), cost(tempcost) {}

};
vector <Edge> E[250];
bool vis[250];
int dist[250];

void dij(int start) {
    memset(vis, 0, sizeof(vis));
    for(int i = 0; i < point; i++) dist[i] = INF;
    priority_queue <qnode> pq;
    while(!pq.empty()) pq.pop(); // reset
    dist[start] = 0;
    pq.push(qnode(start, 0));
    qnode tmp;
    while(!pq.empty()) {
        tmp = pq.top();
        pq.pop();
        int u = tmp.v;
        if(vis[u]) continue;
        vis[u] = true;
        for(int i = 0; i < E[u].size(); i++) {
            int v = E[u][i].start;
            int cost = E[u][i].cost;
            if(!vis[v]) {
                dist[v] = min(dist[v], dist[u]+cost);
                pq.push(qnode(v, dist[v]));
            }
        }
    }
}

void addedge(int u, int v, int w) {
  	E[u].push_back(Edge(v, w));
  	E[v].push_back(Edge(u, w));
}

int main(){
 	while(cin >> point >> road ) {
    	for(int i = 0; i <= point; ++i) E[i].clear();
    	for(int i = 0; i < road; ++i) {
        	scanf("%d %d %d", &u, &v, &w);
        	addedge(u, v, w);
    	}
    	scanf("%d %d", &st, &ed);
    	dij(st);
    	if(dist[ed] == INF) puts("-1");
    	else printf("%d\n", dist[ed]);
 	}
 	return 0;
}
