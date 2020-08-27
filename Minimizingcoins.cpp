// Minimizing Coins :: https://cses.fi/problemset/task/1634/


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
    si(n); sll(x);
    ll a[n]; fr(i,0,n)  cin>>a[i];
    
    /* This is a 2d DP solution of this problem. similar to knapsack. 
    However, it won't pass memory constraints
    ll dp[n+1][x+1];
    fr(i,0,x+1)
        dp[0][i]=INF;
    fr(i,0,n+1) dp[i][0]=0;
    fr(i,1,n+1)
    {
        fr(j,1,x+1)
        {
        if(j-a[i-1]>=0)
            dp[i][j]=min(dp[i-1][j],dp[i][j-a[i-1]]+1);
        else
            dp[i][j]=dp[i-1][j];
        }
    }
    */
    
    
    ll dp[x+1]; fr(i,0,x+1) dp[i]=INF; 
    dp[0]=0;
    fr(i,0,n)
    {
        for(int j=a[i];j<=x;j++)
        {
            if(dp[j-a[i]]!=INF && dp[j-a[i]]+1<dp[j])
                dp[j]=dp[j-a[i]]+1;
        }
    }
    
//    fr(i,0,x+1) cout<<dp[i]<<" ";
    
    if(dp[x]==INF)    cout<<-1;
    else cout<<dp[x];
    
    
    
    
    
}