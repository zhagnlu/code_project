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

template <class T>
struct Node 
{
	T value;
	struct Node<T>* left;
	struct Node<T>* right;
};
typedef Node<int> node;
class tree
{
	
};

int  create_tree( node *&root)
{
	int value;
	scanf("%d",&value);
	if(value==0) {
		root=NULL;
//		return 0;
	}
	else{		
		root=(node*)malloc(sizeof(node));
		root->value=value;
		create_tree(root->left);
		create_tree(root->right);
	}
	return 0;
}	
void print_tree(node* root)
{
	if(root==NULL) return;
	print_tree(root->left);
	pr(root->value);
	print_tree(root->right);
}
int  find_height(node * root, int flag){
	if(flag==1){
		if(root==NULL) return 0;
		int a,b;
			a=find_height(root->left,1);
			b=find_height(root->right,1);
			return a>b? a+1:b+1;
		}
	else if(flag==2){
			int a,b;
			if(root->left==NULL && root->right==NULL)  return 1;
			else if(root->left==NULL)  return find_height(root->right,2);
			else if(root->right==NULL)  return find_height(root->left,2);
			else{
				a=find_height(root->left,2);
				b=find_height(root->right,2);
				return a>b? b+1:a+1;
			}
}
}


int main()
{
#ifdef LOCAL
	freopen("input","r",stdin);
#endif
	node* root;
	create_tree(root);
	print_tree(root);
	cout<<find_height(root,1);
	cout<<find_height(root,2);
	
}



