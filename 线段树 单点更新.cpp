#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
#define fi first
#define se second
#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define mem(a,b) memset(a,b,sizeof(a))
#define ull unsigned long long
#define inf 0x3f3f3f3f

const int maxn = 200000+5;
const double eps = 1e-6;
const double pi = 3.141592653589793238462643385;

template <class T>
void show(T a[], int len) {
    for(int i = 0; i <= len; i ++) cout << a[i] << " "; cout << endl;
}

inline int read() {
    int x = 0, f = 1; char ch = getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

int sum[maxn << 2];
int a[maxn];
int n, m;

void pushup(int root) {sum[root] = max(sum[root<<1], sum[root<<1|1]);}

void build(int l, int r, int rt) {
    if(l == r) {sum[rt] = a[l]; return;}
    int m = (l+r) >> 1;
    build(l, m, rt<<1);
    build(m+1, r, rt<<1|1);
    pushup(rt);
}

void update(int key, int value, int tree_l, int tree_r, int rt) {
    if(tree_l == tree_r) {
        sum[rt] = value;
        return;
    }
    int m = (tree_l+tree_r) >> 1;
    if(key <= m) update(key, value, tree_l, m, rt<<1);
    else update(key, value, m+1, tree_r, rt<<1|1);
    pushup(rt);
}

int query(int query_l, int query_r, int tree_l, int tree_r, int rt) {
    if(query_l <= tree_l && tree_r <= query_r) return sum[rt];
    int m = (tree_l+tree_r) >> 1;
    int ans = 0;
    if(query_l <= m) ans = max(ans, query(query_l, query_r, tree_l, m, rt<<1));
    if(query_r > m) ans = max(ans, query(query_l, query_r, m+1, tree_r, rt<<1|1));
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(cin >> n >> m) {
        for(int i = 1; i <= n; i++) cin >> a[i];
        build(1, n, 1);
        while(m--) {
            char c[2];
            int x, y;
            cin >> c >> x >> y;
            if(c[0] == 'Q') {
                cout << query(x, y, 1, n, 1) << endl;
            }
            else if(c[0] == 'U') {
                update(x, y, 1, n, 1);
            }
        }
    }
    return 0;
}