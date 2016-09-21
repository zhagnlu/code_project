#pragma comment(linker,"/STACK:102400000,102400000")
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <math.h>
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

class x{
public:
	int i;
	x(int a){ i=a;}
	x(){cout<<"x construct"<<endl;}
	x(const x& t){cout<<"copyconstruct x"<<endl;}
	x& operator =(const x& t){ cout<<"= construct"<<endl;return *this;}
	virtual void f(){
		cout<<"xx"<<endl;
	}
};

class a: public x{
public:
	int j;
	a(int i){ this->j=i;}
	void f(){
		cout<<"a"<<endl;}
};

class b:public x{
public:
	virtual void f(){
		cout<<"b"<<endl;}
};

int main(){
	x x1(5);
	x x2=x1;


}

