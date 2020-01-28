#include <bits/stdc++.h>
using namespace std;

int main() {
 // vector<int>adj[10];
 int t,i,j;
  cin>>t;
  while(t--)
  { string s1,s2;
  	cin>>s1>>s2;
  	int lev[9][9];
  	for(i=1;i<=8;i++)
  	  {   //fill(lev[i]+1,lev[i]+9,1e4);
  	      for(j=1;j<=8;j++)
  	      lev[i][j]=10000;
  	  }
  	int x1=int(s1[0])-96;
  	int y1=int(s1[1])-'0';
  	int x2=int(s2[0])-96;
  	int y2=int(s2[1])-'0';
  //	cout<<x2<<y2;
  	queue<pair<int,int>>q;
  	q.push({x1,y1});
  	lev[x1][y1]=0;
     while(!q.empty())
     {  
     	pair<int,int>pr=q.front();
     	int x=pr.first,y=pr.second;
     //	if(x==x2&&y==x2)break;
     	q.pop();
     	if(x>0&&x<9&&y>0&&y<9){
     	    if(x+1>0&&x+1<9&&y-2>0&&y-2<9&&(lev[x+1][y-2]>(lev[x][y]+1))){
     	        
     	q.push(make_pair(x+1,y-2));
     	lev[x+1][y-2]=min(lev[x][y]+1,lev[x+1][y-2]);}
     	
     	 if(x+1>0&&x+1<9&&y+2>0&&y+2<9&&(lev[x+1][y+2]>lev[x][y]+1)){
     	q.push(make_pair(x+1,y+2));
        lev[x+1][y+2]=min(lev[x][y]+1,lev[x+1][y+2]);}
        
         if(x-1>0&&x-1<9&&y-2>0&&y-2<9&&lev[x-1][y-2]>lev[x][y]+1){
     	q.push(make_pair(x-1,y-2));
     		lev[x-1][y-2]=min(lev[x][y]+1,lev[x-1][y-2]);}
     		
     		 if(x-1>0&&x-1<9&&y+2>0&&y+2<9&&lev[x-1][y+2]>lev[x][y]+1){
     	q.push(make_pair(x-1,y+2));
     		lev[x-1][y+2]=min(lev[x][y]+1,lev[x-1][y+2]);}
     	
     	 if(x+2>0&&x+2<9&&y-1>0&&y-1<9&&lev[x+2][y-1]>lev[x][y]+1){
     	q.push(make_pair(x+2,y-1));
     		lev[x+2][y-1]=min(lev[x][y]+1,lev[x+2][y-1]);}
     		
     		 if(x+2>0&&x+2<9&&y+1>0&&y+1<9&&lev[x+2][y+1]>lev[x][y]+1){
     	q.push(make_pair(x+2,y+1));
     		lev[x+2][y+1]=min(lev[x][y]+1,lev[x+2][y+1]);}
     		
     		 if(x-2>0&&x-2<9&&y-1>0&&y-1<9&&lev[x-2][y-1]>lev[x][y]+1){
     	q.push(make_pair(x-2,y-1));
     		lev[x-2][y-1]=min(lev[x][y]+1,lev[x-2][y-1]);}
     		
     		 if(x-2>0&&x-2<9&&y+1>0&&y+1<9&&lev[x-2][y+1]>lev[x][y]+1){
     	q.push(make_pair(x-2,y+1));
     		lev[x-2][y+1]=min(lev[x][y]+1,lev[x-2][y+1]);
     		 }
     	}
     	
     }
     cout<<lev[x2][y2]<<"\n";
  
  	
  }
}