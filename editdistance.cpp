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
    string s; cin>>s;
    string t; cin>>t;
    ll n=s.length();
    ll m=t.length();
    ll dp[n+1][m+1];
    fr(i,0,m+1)
    {
        dp[0][i]=i;
    }
    fr(i,0,n+1)
    {
        dp[i][0]=i;
    }
    
    
    fr(i,1,n+1)
    {
        fr(j,1,m+1)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=dp[i-1][j-1]; // not considering this character   
            }
            else
            {
                // replace == dp[i-1][j-1]  delete == dp[i-1][j] insert == dp[i][j-1]
                dp[i][j]=min(dp[i-1][j-1]+1,dp[i-1][j]+1);
                dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
            }
        }
    }
    
   /* fr(i,0,n+1)
    {
        fr(j,0,m+1) cout<<dp[i][j]<<" ";
        nl;
    } */
    
    cout<<dp[n][m];
    
    
}