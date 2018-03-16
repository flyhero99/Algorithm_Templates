const int maxn = 1000010;

bool valid[maxn];

/*素数筛法O(NlogN)*/
void getPrime(int n, int &tot, int ans[maxn]) {
	tot = 0;
	int i, j;
	for(i = 2;i <= n;++i) valid[i] = true;
	for(i = 2;i <= n;++i) if(valid[i]) {
		if(n/i < i) break;
		for(j = i*i;j <= n;j += i) valid[j] = false;
	}
	for(i = 2;i <= n;++i) if(valid[i]) ans[++tot] = i;
}

/*素数筛法*/
void getPrime(int n, int &tot, int ans[maxn]) {
	memset(valid, true, sizeof(valid));
	for(int i = 2;i <= n;i++) {
		if(valid[i]) {
			tot++;
			ans[tot] = i;
		}
		for(int j = 1;((j<=tot) && (i*ans[j]<=n));j++) {
			valid[i*ans[j]] = false;
			if(i % ans[j] == 0) break;
		}
	}
}