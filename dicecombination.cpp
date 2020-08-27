// https://cses.fi/problemset/task/1633/

#include<bits/stdc++.h>
#define fr(i,c,b) for(int i=c;i<b;i++)
#define frl(i,c,b) for(ll i=c;i<b;i++)
#define si(x) int x; scanf("%d", &x)
#define sll(x) ll x; scanf("%lld", &x)
#define pi(x) printf("%d", x)
#define pll(x) printf("%lld", x)
#define nl printf("\n")
#define watch(x) cout << (#x) << " is " << (x) << endl
#define MAX 100001
#define M 1000000007
#define pb push_back

typedef long long int ll;

using namespace std;

int main()
{
    // dp[i] == summation of dp[i-k] where k = 1,2,3,4,5,6
    si(n);
    ll dp[n+1];
    dp[0]=0; dp[1]=1;
    ll sum=1;
    fr(i,2,n+1)
    {
        if(i<=6)
            dp[i]=(sum%M+1%M)%M;
        else
            dp[i]=sum%M;
        sum=(sum%M+dp[i]%M)%M;
        if(i-6>0)
            sum-=dp[i-6];
    }
    //fr(i,1,n+1) cout<<dp[i]<<" "; nl;
    cout<<dp[n]%M;
    
}