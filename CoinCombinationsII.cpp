// Coin Combinations II :: https://cses.fi/problemset/task/1636/

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
    int dp[x+1]={0}; dp[0]=1;
    fr(i,0,n)
    {   
        for(int j=a[i];j<=x;j++)
        {
            dp[j]+=dp[j-a[i]]; if(dp[j]>=M) dp[j]-=M;
        }
    }
  //  fr(i,0,x+1) cout<<dp[i]<<" ";
    pi(dp[x]);
}
