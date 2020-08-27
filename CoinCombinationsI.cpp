// Coin Combinations I :: https://cses.fi/problemset/task/1635


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
#define INF 10000001
typedef long long int ll;

using namespace std;

int main()
{
    si(n); si(x); int a[n]; fr(i,0,n)    scanf("%d",&a[i]);
    int dp[x+1]; dp[0]=1;
    fr(i,1,x+1)
    {   dp[i]=0;
        fr(j,0,n)
        {
            if(i-a[j]>=0)
             dp[i]=(dp[i]+dp[i-a[j]])%M;
        }
    }
  //  fr(i,0,x+1) cout<<dp[i]<<" ";
    pi(dp[x]);
}
