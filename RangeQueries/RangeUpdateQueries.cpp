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
ll lazy[800000+1];

void build(ll si, ll ss, ll se)
{
    if(ss==se)
    {    segtree[si]=a[ss]; return; }
    ll mid=(ss+se)/2;
    build(2*si,ss,mid);
    build(2*si+1,mid+1,se);
    segtree[si]=segtree[2*si+1]+segtree[2*si];
}

ll query(ll si,ll ss,ll se,ll qs,ll qe)
{
    if(lazy[si]!=0)
    {
        ll dx=lazy[si];
        lazy[si]=0;
        segtree[si]+=dx*(se-ss+1);
        if(ss!=se)
        {
            lazy[si*2]+=dx;
            lazy[si*2+1]+=dx;
        }
    }
    
    if(qs>se||qe<ss)    return 0; //outside
    if(ss>=qs&&se<=qe)  return segtree[si];
    
    ll mid=(ss+se)/2;
    ll l=query(2*si,ss,mid,qs,qe);
    ll r=query(2*si+1,mid+1,se,qs,qe);
    return l+r;
}

void update(ll si,ll ss,ll se,ll qs,ll qe,ll val)
{
    if(lazy[si]!=0)
    {
        ll dx=lazy[si];
        lazy[si]=0;
        segtree[si]+=dx*(se-ss+1);
        if(ss!=se)
        {
            lazy[si*2]+=dx;
            lazy[si*2+1]+=dx;
        }
    }

        if(ss>qe||se<qs)    return; //outside

    
    if(ss>=qs&&se<=qe)
    {
        ll dx=val;
        segtree[si]+=dx*(se-ss+1);
        if(ss!=se)
        {
        lazy[2*si]+=dx;
        lazy[2*si+1]+=dx;
        }
        return;
    }
    
    ll mid=(ss+se)/2;
    update(2*si,ss,mid,qs,qe,val);
    update(2*si+1,mid+1,se,qs,qe,val);
    segtree[si]=segtree[2*si]+segtree[2*si+1];
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
        si(ind);
        cout<<query(1,1,n,ind,ind);
        nl;
        }
        else
        {
            si(l); si(r); sll(val);
            update(1,1,n,l,r,val);
        }
        
    }
    
    
    
}
