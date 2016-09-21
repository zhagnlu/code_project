
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

void reserve(int p[],int b, int e)
{
	for(;b<e;b++,e--)
	{ 
		int temp=p[e];
		p[e]=p[b];
		p[b]=temp;
	}
}
void yiwei1(int p[],int n,int flag,int k)
{
	k=k%n;
	if(k==0) return;
	if(flag==1){
	   reserve(p,0,n-k-1);
	   reserve(p,n-k,n-1);
	   reserve(p,0,n-1);
	}
	if(flag==2){
	   reserve(p,0,k-1);
	   reserve(p,k,n-1);
	   reserve(p,0,n-1);
	}

}
void yiwei3(int p[],int n,int flag,int k)
{
	int temp;
	if(flag==1)
	{
	     for(int i=0;i<k;i++)
	     {
		    temp=p[0];
		    for(int j=0;j<n-1;j++)
		    {
				p[j]=p[j+1];
		    }
			p[n-1]=temp;
		 }
	}
	if(flag==2)
	{
	     for(int i=0;i<k;i++)
	     {
		    temp=p[n-1];
		    for(int j=n-1;j>0;j--)
		    {
				p[j]=p[j-1];
		    }
			p[0]=temp;
	     }
	}
}
void yiwei2(int p[],int n,int flag,int k)
{ 
	k=k%n;
	if(k==0) return;
	int* p1=new int[k];
	if(flag==1){
		int i=k-1;
		for(int j=n-1;i>=0;i--)
		{
			p1[i]=p[j];
			j--;
		}
		for(int j=n-1-k;j>=0;j--){
			p[j+k]=p[j];
		}
		for(int j=0;j<k;j++)
		{
			p[j]=p1[j];
		}
	}
	if(flag==2){
		for(int i=0;i<k;i++)
		{
			p1[i]=p[i];
		}
		for(int j=k;j<n;j++){
			p[j-k]=p[j];
		}
		int i=0;
		for(int j=n-k;i<k;i++)
		{
			p[j]=p1[i];
			j++;
		}
	}
		delete[] p1;
}
// 找到最大和子串
int find_max(int a[],int k)
{
	int start_max = 0; int end_max = 0; 
	int max = -10000000; int sum = 0;  int temp = 0;
    for (int i = 0; i < k; i++)
    {
		sum += a[i];
		if(sum < 0){ sum = 0; temp = i + 1;}
	    else if(sum > max){ max = sum; start_max = a[temp]; end_max = a[i]; }	
    }
   if (max < 0)
   {
	   int m=-1000000;
	   for(int i=0;i<k;i++){
		   if(a[i]>m){
			   m=a[i];
		   }
	   }
		max = m;
   
   }
   return max;
}




void solution(int n)
{
	int t=0;
	int **p=new int*[n];
	for(int i=0;i<n;i++){
		p[i]=new int[n];
	}
	int i=0;
	int j=0;
	int in=1;
	while(n-t>1){
		for(j=t;j<=n-1-t-1;j++){
			p[t][j]=in++;
		}
		for(i=t;i<=n-1-t-1;i++){
			p[i][n-1-t]=in++;
		}
		for(int j=n-1-t;j>=t+1;j--){
			p[n-1-t][j]=in++;
		}
		for(int i=n-1-t;i>=t+1;i--){
			p[i][t]=in++;
		}
		t++;
	}
	p[(n-1)/2][(n-1)/2]=in++;
	for (int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<p[i][j];
		}
		cout<<endl;
	}
	delete p;
}
int main()
{
	int p[]={1,2,3,4,5,6};
	yiwei3(p,6,2,2);
	for(int i=0;i<6;i++)
	{
		cout<<p[i]<<" ";
	}
		
		system("pause");
}
