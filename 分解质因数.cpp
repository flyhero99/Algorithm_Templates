#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define inf 0x3f3f3f3f
#define mod 1000000007
#define mem(a,b) memset(a,b,sizeof(a))
typedef long long ll;

const int maxn = 100005;

int t;
ll a[maxn]; // 存储质因数
ll b[maxn]; // 存储各个质因数的幂
ll n; // 待分解的数
ll tot; // 质因数个数

void factor() {
	ll tmp = (ll) ((double)sqrt(n)+1);
	ll now = n; tot = 0;
	for(int i = 2;i*i <= now;i++) {
		if(now % i == 0) {
			a[++tot] = i;
			b[tot] = 0;
			while(now%i == 0) {
				++b[tot];
				now /= i;
			}
		}
	}
	if(now != 1) { // n为质数
		a[++tot] = now;
		b[tot] = 1;
	}
}

int main() {

}