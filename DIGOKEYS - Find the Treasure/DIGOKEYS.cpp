#include <bits/stdc++.h>
using namespace std;

void addEdge(int a,int b,vector<int>adj[])
{
	adj[a].push_back(b);
}
int main() {
	int t,i,j,n,m;
cin>>t;
while(t--)
{
	cin>>n;
	vector<int>adj[n+1];
	for(i=1;i<=n-1;i++)
	{
		scanf("%d",&m);
		int b[m+10];
		for(j=0;j<m;j++)
		{
			scanf("%d",&b[j]);
		
		}
		sort(b,b+m);
		for(j=0;j<m;j++)
		{
				addEdge(i,b[j],adj);
		}
	}
	int parent[n+1],level[n+1];
	bool visited[n+1];
	memset(visited,false,sizeof(visited));
	for(int i=1;i<=n;i++)
	level[i]=INT_MAX;
	queue<int>q;
	q.push(1);
	parent[1]=1;
	level[1]=0;
//	cout<<adj[3].size();
int flag=0;
	while(!q.empty())
	{
	int	x=q.front();
	
	visited[x]=true;
		q.pop();
		if(x==n)
		{
			flag=1;
			break;
		}
		for(int i=0;i<adj[x].size();i++)
		{     if(adj[x][i]==n)
		      flag=1;
			if(visited[adj[x][i]]==false&&level[adj[x][i]]>(level[x]+1))
			{
			    
			    //cout<<adj[x][i]<<" ";
				parent[adj[x][i]]=x;
				q.push(adj[x][i]);
				level[adj[x][i]]=level[x]+1;
			}
		}
	}
	if(flag==1){

	vector<int>v;

int	x=parent[n];
while(x!=1)
{
    v.push_back(x);
    x=parent[x];
}
v.push_back(1);

cout<<level[n]<<"\n";
	for(int i=v.size()-1;i>=0;i--)
	printf("%d ",v[i]);
	printf("\n");
	}
	else
	printf("-1\n");
}
}

