#include<bits/stdc++.h>
#define mod 1000000007
typedef long long ll;
using namespace std;

struct matrix{
    ll a[2][2];
    matrix(){
        memset(a,0,sizeof(a));
    }
    matrix(int x){
        memset(a,0,sizeof(a));
        for(int i=0;i<2;i++)
            a[i][i]=1;
    }
    ll sum(){
        ll ret=0;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                ret+=a[i][j];
        return ret%mod;
    }
    matrix operator+(const matrix&other){
        matrix ret;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    ret.a[i][j]=(ret.a[i][j]+a[i][j]+other.a[i][j])%mod;
        return ret;
    }
    matrix operator*(const matrix&other){
        matrix ret;
        int i,j,k;
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)
                for(k=0;k<2;k++)
                    ret.a[i][j]+=a[i][k]*other.a[k][j],
					ret.a[i][j]%=mod;
        return ret;
    }
    matrix&operator*=(const matrix&other){*this=*this*other;
        return*this;
    }
    matrix operator^(ll index){
        matrix ret(1);
        matrix base(*this);
        while(index){
            if(index&1)
                ret*=base;
            base*=base;
            index>>=1;
        }
        return ret;
    }
};

int main() {
    ll x, u, v, k;
    for(ll x, u, v, k; ~scanf("%lld %lld %lld %lld", &x, &u, &v, &k); ) {
        matrix mm;
        mm.a[0][0] = v, mm.a[0][1] = u, mm.a[1][0] = 1, mm.a[1][1] = 0;
        ll a1 = x%mod, a2 = x*x%mod;
        matrix res = mm^(k-2);
        ll ans = (res.a[0][0]*a2%mod + res.a[0][1]*a1%mod) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}