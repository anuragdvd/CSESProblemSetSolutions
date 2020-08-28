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
   si(n); vector<int>a(n); ll sum=0; 
   fr(i,0,n) {   cin>>a[i]; sum+=a[i]; }
   
   ll dp[sum+1]={0};
   dp[0]=1;

   //watch(sum);
   fr(i,0,n)
   {
       for(int j=sum;j>=a[i];j--)
       {
           dp[j]=max(dp[j],dp[j-a[i]]);
       }
   }
   ll c=0;
   fr(i,1,sum+1)
   {
       if(dp[i]==1)
            c++;
   }
   pll(c); nl;
   fr(i,1,sum+1)
   {
       if(dp[i]==1)
            cout<<i<<" ";
   }
}