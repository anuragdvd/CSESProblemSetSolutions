// Grid Paths :: https://cses.fi/problemset/task/1638/

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
   // freopen ("input.txt","r",stdin);

    si(n); char ch[n+1][n+1];
    fr(i,1,n+1)   fr(j,1,n+1)   cin>>ch[i][j];
    ll dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    /* filling last row . If there is a bomb then all path will be set to 0. Otherwise all path will be 1. */ 
    bool flag=false;
    for(int i=n;i>=1;i--)
    {
        if(ch[n][i]=='*')   flag=true;
        if(flag)    dp[n][i]=0;
        else    dp[n][i]=1;
    }

    flag=false;
    for(int i=n;i>=1;i--)
    {
        if(ch[i][n]=='*')   flag=true;
        if(flag)    dp[i][n]=0;
        else    dp[i][n]=1;
    }


    for(int i=n-1;i>=0;i--)
    {
        for(int j=n-1;j>=0;j--)
        {
            if(ch[i][j]=='*')   dp[i][j]=0;
            else dp[i][j]=dp[i+1][j]+dp[i][j+1];
            if(dp[i][j]>M)  dp[i][j]-=M;
        }
    }
  //  fr(i,0,n+1) { fr(j,0,n+1) { cout<<dp[i][j]<<" "; }  nl; }
    
    cout<<dp[1][1];
    
    
    
}