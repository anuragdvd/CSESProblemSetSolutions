// Removing Digits :: https://cses.fi/problemset/task/1637/

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

    /*  dp[i] = min. steps required to make 0 from i. Base Case : dp[0]=0   */

    si(n);
    ll dp[n+1]={0};
    
    dp[0]=0;
    if(n==0)    cout<<0;
    else if(n<10)   cout<<1;
    else
    {
    fr(i,1,10)  dp[i]=1;
    fr(i,10,n+1)
    {
        ll mx=0; ll temp=i;
        while(temp)
        {
            ll r=temp%10; 
            mx=max(mx,r); 
            temp=temp/10;
                     
        }
      
        ll x=i-mx;
        dp[i]=1+dp[x];
    }
   // fr(i,0,n+1) cout<<dp[i]<<" "; nl;
    
    cout<<dp[n];
    }
}