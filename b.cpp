#include<stdio.h>
#include<iostream>

using namespace std;



void yiwei2(int p[],int n,int flag,int k)
{ 
	k=k%n;
	if(k==0) return;
	int* p1=new int[k];
	if(flag==1){
		int i=0;
		for(int j=n-k;i<k;i++)
		{
			p1[i]=p[j];
			j++;
		}
		for(int j=0;j<=n-1-k;j++){
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

int main(){
        int p[]={1,2,3,4,5,6};
	yiwei2(p,6,1,2);
	for(int i=0;i<6;i++){
		cout<<p[i];
	}
}
