#include <bits/stdc++.h>
using namespace std;
int graph[50][50];bool vis[50][50];int val[50][50];
int n,m,mi;
bool isValid(int x,int y)
{
	if(x>=0&&x<n&&y>=0&&y<m)
	return true;
	//cout<<n<<" "<<m<<"\n";
	return false;
}
void DFS(int x1,int y1,int level)
{   mi=max(mi,level);
	int ro[]={-1,-1,-1,0,0,1,1,1};
	int co[]={-1,0,1,-1,1,-1,0,1};
	for(int i=0;i<8;i++)
	{  int a=x1+ro[i];
	   int b=y1+co[i];
	   //cout<<a<<" "<<b<<"\n";
		if(isValid(a,b))
		{
		    //cout<<a<<" "<<b<<"\n";
		    //cout<< graph[a][b]<<" "<<graph[x1][y1]+1<<"\n";
			if(vis[a][b]==false && graph[a][b]==graph[x1][y1]+1)
			{
			    //cout<<a<<" "<<b<<"\n";
			    
				vis[a][b]=true;
				DFS(a,b,level+1);
			}
		}
	}
	
	
}
int main() {
	int p=0;
	while(scanf("%d%d",&n,&m)){
		p++;
  if(n==0&&m==0)
  break;
  
  
  for(int i=0;i<n;i++)
  { string s;
  	cin>>s;
  	for(int j=0;j<m;j++)
  	{   int k=int(s[j])-64;
 // 	cout<<k<<" ";
  		graph[i][j]=k;
  	}
 // 	cout<<endl;
  }
  
  for(int i=0;i<n;i++)
  {
      for(int j=0;j<m;j++)
      {
          vis[i][j]=false;
          val[i][j]=1;
      }
  }
  
  
  
  mi=0;
  for(int i=0;i<n;i++)
  {
  	for(int j=0;j<m;j++)
  	{  if(graph[i][j]==1){
  		DFS(i,j,1);
  	}
  	}
  }
  
  printf("Case %d: %d\n",p,mi);
	}
}