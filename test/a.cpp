#pragma comment(linker,"/STACK:102400000,102400000")
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <deque>

#define LOCAL

#define pr(x) cout << x << "  "
#define prln(x) cout << x << endl
#define	INF 1e9
#define eps 1e-12
typedef long long ll;
using namespace std;

int  find_height(vector< pair<int,int> >p, int j);
int n;
int m;
vector< pair<int,int> > p;
int main()
{
#ifdef LOCAL
	freopen("input","r",stdin);
#endif
	scanf("%d%d",&m,&n);
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		p.push_back(make_pair(a,b));
	}
	int heigh=INF;
	for(int j=0;j<n;j++){
		int ans=find_height(p,j);
		if(heigh>ans) heigh=ans;
	}
	cout<<heigh;
}

int  find_height(vector< pair<int,int> >p, int j)
{
	int height=0;
	float propotion=0.0;
	int x=0;int y=0;
	for(int i=0;i<n;i++){
		if(i==j) continue;
		if(x+p[i].first<m){
			x=x+p[i].first;		
			if(p[i].second>y){
				y=p[i].second;
			}
			if(i==n-1) height+=y;
		}
		else if(x+p[i].first==m){
			x=0;
			if(p[i].second>y){
				y=p[i].second;
			}
			height+=y;
			y=0;
		}
		else{
			propotion=(float)(m-x)/p[i].first;
			if(p[i].second*propotion>y) y=p[i].second*propotion;
			x=0;
			height+=y;
			y=0;
		}	
		
	}
	return height;

		
}



