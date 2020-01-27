#include<bits/stdc++.h>
using namespace std;
#define lld long long int
#define speed ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define M 1000000007
set<lld>s;
#define MAX_SIZE 1299910
void SieveOfEratosthenes(vector<lld>&primes) 
{ 
	bool IsPrime[MAX_SIZE]; 
	memset(IsPrime, true, sizeof(IsPrime)); 
	
	for (lld p=2;p*p<MAX_SIZE; p++) 
	{ 
 
		if (IsPrime[p] == true) 
		{ 
			for (int i = p * p; i < MAX_SIZE; i += p) 
				IsPrime[i] = false; 
		} 
	} 

	for (lld p = 2; p < MAX_SIZE; p++) 
	if (IsPrime[p]) 
			primes.push_back(p); 
//  cout<<primes[100000];			
			
}

lld find_key(lld c,lld parent[])
{
	if(parent[c]==c)
		return c;
	else
	{
		parent[c]=find_key(parent[c],parent);
		return parent[c];
	}
}

int main()
{
    speed
    lld t,n,m,i,x,y;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(m==0)
        {
            cout<<-1<<"\n";
        }
        else
        {
        lld a[n+2],b[n+2];
        for(i=0;i<=n;i++)
        {
            a[i]=i;
        }
        for(i=0;i<=n;i++)
        {
            b[i]=1;
        }
        for(i=0;i<m;i++)
        {
            cin>>x>>y;
            lld c=find_key(x,a);
    lld d=find_key(y,a);
    if(c!=d)
    {
    	
    	b[c]=b[c]+b[d];
    	b[d]=0;
    	a[d]=c;
    }
           
        }
        sort(b,b+n,greater<lld>());
           vector<lld>primes; 
	SieveOfEratosthenes(primes); 
        cout<<primes[b[0]-1]<<"\n";
        }
    }
    return 0;
}  