const int maxn = 1010;

int solve(double a[][maxn], bool l[], double ans[], const int &n);

inline int solve(double a[][maxn], bool l[], double ans[], const int &n) {
	int res = 0, r = 0;
	for(int i = 0;i < n;i++) l[i] = false;
	for(int i = 0;i < n;i++) {
		for(int j = r;j < n;j++) {
			if(fabs(a[j][i] > EPS)) {
				for(int k = i;k <= n;k++)
					swap(a[j][k], a[r][k]);
				break;
			}
		}
		if(fabs(a[r][i]) < EPS) {
			++res;
			continue;
		}
		for(int j = 0;j < n;j++) {
			if(j != r && fabs(a[j][i] > EPS)) {
				double tmp = a[j][i] / a[r][i];
				for(int k = i;k <= n;k++)
					a[j][k] -= tmp*a[r][k];
			}
		}
		l[i] = true, ++r;
	}
	for(int i = 0;i < n;i++) {
		if(l[i]) {
			for(int j = 0;j < n;j++) {
				if(fabs(a[j][i] > 0))
					ans[i] = a[j][n] / a[j][i];
			}
		}
	}
	return res;
}