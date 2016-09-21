#pragma comment(linker,"/STACK:102400000,102400000")
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <deque>

//#define LOCAL

#define pr(x) cout << x << "  "
#define prln(x) cout << x << endl
#define	INF 1e9
#define eps 1e-12
typedef long long ll;
using namespace std;

int m,n,A[10000],B[10000];
int x,y,p,q,pp[10000][10000]={0};
int minlen,k,Q;
int dir[][4]={{1,0},{-1,0},{0,1},{0,-1}};
void func(int a[],int b[],int x,int y,int p,int q,int & value){
	if(x==p&&y==q){
		if(value<minlen){
			minlen=value;
		}
		return ;
	}
	for(int i=0;i<4;i++){
		int na=x+dir[i][0];
		int ny=y+dir[i][1];
		int append;
		if(i==0) append=b[x-1];
		if(i==1) append=b[x];
		if(i==2) append=a[y-1];
		if(i==3) append=a[y];
		if(na>=1&&na<=m&&ny>=1&&ny<=n&&!pp[na][ny]){
			pp[na][ny]=1;
			value+=append;
			func(a,b,na,ny,p,q,value);
			pp[na][ny]=0;
		}	
	}
}
						
int main()
{
	freopen("input","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d",&A[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&B[i]);
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		pp[a][b]=1;
	}
		
	scanf("%d",&Q);
	for(int i=0;i<Q;i++){
		scanf("%d%d%d%d",&x,&y,&p,&q);
		minlen=0x7fffffff;
		int value=0;
		func(A,B,x,y,p,q,value);
		cout<<minlen<<endl;
	}
}
