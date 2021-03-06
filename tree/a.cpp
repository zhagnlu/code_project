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
void print_inorder(node* root)
{
	if(root==NULL) return ;
	stack<node*> st;
	node* p=root;
	while(p||!st.empty()){
		while(p){
			st.push(p);
			p=p->left;
		}
		if(!st.empty()){
			p=st.top();
			cout<<p->value;
			st.pop();
			p=p->right;
		}
	}
	return ;
}
void print_post(node * root)
{	
	if(root==NULL) return ;
	stack< pair<node*,bool> > st;
	st.push(make_pair(root,false));
	node* p;
	bool visit;
	while(!st.empty()){
		 p=st.top().first;
		 visit=st.top().second;
		 st.pop();
		 if(p==NULL) continue;
		 if(visit==true){
			 cout<<p->value;
		 }
		else{
			st.push(make_pair(p,true));
			st.push(make_pair(p->right,false));
			st.push(make_pair(p->left,false));
		}
	}
}
void print_preorder(node* root)
{
	if(root==NULL) return;
	stack<node*> st;
	st.push(root);
	while(!st.empty()){
		node* p=st.top();
		cout<< p->value;
		st.pop();
		if(p->right)  st.push(p->right);
		if(p->left)   st.push(p->left);
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
//	print_inorder(root);
//	print_post(root);
	print_preorder(root);
}



