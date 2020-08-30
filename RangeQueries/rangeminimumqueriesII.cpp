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
#define INF 1000000001

typedef long long int ll;

using namespace std;

ll a[200000+1];
ll segtree[800000+1];


void build(int si, int ss, int se)
{
    if(ss==se)
    {    segtree[si]=a[ss]; return; }
    int mid=(ss+se)/2;
    build(2*si,ss,mid);
    build(2*si+1,mid+1,se);
    segtree[si]=min(segtree[2*si+1],segtree[2*si]);
}

ll query(int si,int ss,int se,int qs,int qe)
{
    if(qs>se||qe<ss)    return INF; //outside
    if(ss>=qs&&se<=qe)  return segtree[si];
    
    ll mid=(ss+se)/2;
    ll l=query(2*si,ss,mid,qs,qe);
    ll r=query(2*si+1,mid+1,se,qs,qe);
    return min(l,r);
}

void update(int si,int ss,int se,int qi)
{
    if(ss==se)  // leaf node
    {
        segtree[si]=a[ss]; return;
    }
    
    ll mid=(ss+se)/2;
    if(qi<=mid)
        update(2*si,ss,mid,qi);
    else
        update(2*si+1,mid+1,se,qi);
    segtree[si]=min(segtree[2*si],segtree[2*si+1]);
}

int main()
{
    si(n); si(q);

    fr(i,1,n+1)   cin>>a[i];
    build(1,1,n);
    
    while(q--)
    {
        si(k);     
        if(k==2)
        {
        si(l); si(r);
        cout<<query(1,1,n,l,r);
        nl;
        }
        else
        {
            si(pos); si(v);
            a[pos]=v;
            update(1,1,n,pos);
        }
        
    }
    
    
    
}