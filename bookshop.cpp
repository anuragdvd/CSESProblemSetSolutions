// Book Shop :: https://cses.fi/problemset/task/1158/

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
   //freopen("input.txt","r",stdin);
    si(n); 
    si(x);
    ll price[n]; fr(i,0,n)  cin>>price[i];
    ll pages[n]; fr(i,0,n)  cin>>pages[i];
    
    ll dp[2][x+1];
    
    memset(dp,0,sizeof(dp));
    ll k=0; ll curr=1;
    fr(i,1,n+1)
    {
        fr(j,0,x+1)
        {
            if(j-price[i-1]>=0)
                dp[curr][j]=max(dp[k][j],dp[k][j-price[i-1]]+pages[i-1]);
            else
                dp[curr][j]=dp[k][j];

        }
        if(k==0)    k=1, curr=0;
        else    k=0, curr=1;
    }
    
    

   /* fr(i,0,2)
    {
        fr(j,0,x+1)
            cout<<dp[i][j]<<" ";
        nl;
    } */

    cout<<dp[k][x];
    
}