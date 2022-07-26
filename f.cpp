#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,n) for(auto i=a;i<n;i++)
#define rf(i,n,a) for(auto i=n;i>a;i--)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ud unordered
#define sz size
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define int_max 1e9
#define int_min -1e9
#define null NULL
const int M = 1e9 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" "; _print(x); cerr<<endl;
#else
#define debug(x)
#endif

#ifndef ONLINE_JUDGE
#define debugv(x,a,b) cerr<<#x<<" "; _print(x,a,b); cerr<<endl;
#else
#define debugv(x)
#endif

int binexpo(int a,int b,int m){int ans=1;while(b){if(b&1) ans=(ans*1ll*a)%m; a=(a*1ll*a)%m; b>>=1;} return ans;}
int MMI(int a){return binexpo(a,M-2,M);}

void _print(int x){ cerr<<x; }
void _print(string x){ cerr<<x; }
void _print(char x){ cerr<<x; }
void _print(ll x){ cerr<<x; }
void _print(bool x){ cerr<<x; }

template<class T>void _print(stack<T> st){ cerr<<"[ "; while(!st.empty()) { _print(st.top()); cerr<<" "; st.pop();} cerr<<"]"; }
template<class T>void _print(vector<T> v1){ cerr<<"[ "; for(T i:v1) { _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(vector<T> v1,int a,int b){ cerr<<"[ "; for(int i=a;i<b;i++) { _print(v1[i]); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(set<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(unordered_set<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(multiset<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T,class V>void _print(pair<T,V> p){ cerr<<"{";_print(p.f);cerr<<",";_print(p.s);cerr<<"}"; }
template<class T,class V>void _print(map<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }
template<class T,class V>void _print(unordered_map<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }
template<class T,class V>void _print(multimap<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }

class node{
public:
	int data;
	node* l;
	node* r;

	node(){
		data = 0;
		l = null;
		r = null;
	}// for the dummy/null node

	node(int val){
		data = val;
		l = null;
		r = null;
	}

	node(int val,node* left,node* right){
		data = val;
		l = left;
		r = right;
	}
};

//////////////////////////////////////////////////////

class bstit{

	stack<node*> st;
	bool rev = true;

	void pushall(node* root){
		for(;root;){
			st.push(root);
			if(!rev) root=root->l;
			else root=root->r;
		}
	}

public:

	bstit(node* root,bool b){
		rev = b;
		pushall(root);
	}

	bool hasnext(){
		return !st.empty();
	}

	int next(){
		node* t = st.top();
		st.pop();
		if(!rev)
			pushall(t->r);
		else 
			pushall(t->l);
		return t->data;
	}
};

//////////////////////////////////////////////////////

void preorder(node* root){
	if(root==null) return;
	cout<<root->data<<" ";
	preorder(root->l);
	preorder(root->r);
}

void inorder(node* root){
	if(root==null) return;
	inorder(root->l);
	cout<<root->data<<" ";
	inorder(root->r);
}

void postorder(node* root){
	if(root==null) return;
	postorder(root->l);
	postorder(root->r);
	cout<<root->data<<" ";
}

// node* search(node* root,int x){
// 	if(root==null) return null;
// 	if(root->data ==x) return root;
// 	if(root->data > x) return search(root->l,x);
// 	return search(root->r,x);
// }

int step = 1;

node* search(node* root,int x){
	while(root && root->data!=x){
		root = root->data > x ? root->l : root->r;
		step++;
	}
	return root;
}

int CEIL(node* root,int x){
	int ans;
	// CEIL(x) ==> value v such that v is smallest and v >= x
	while(root){
		if(root->data==x){
			ans = root->data;
			break;
		}
		if(root->data > x){
			ans = root->data;
			root = root->l;
		}else root=root->r;
	}
	return ans;
}

int FLOOR(node* root,int x){
	int ans;
	// FLOOR(x) ==> value v such that v is biggest and v <= x
	while(root){
		if(root->data==x){
			ans = root->data;
			break;
		}
		if(root->data < x){
			ans = root->data;
			root = root->r;
		}else root=root->l;
	}
	return ans;
}

node* INSERT(node* root,int x){
	if(!root) return new node(x);
	node* t = root;
	while(1){
		if(t->data > x){
			if(t->l) t=t->l;
			else{
				t->l = new node(x);
				break;
			}
		}else{
			if(t->r) t=t->r;
			else{
				t->r = new node(x);
				break;
			}
		}
	}
	return root;
}

// O(N) time & O(log N) approach

// unordered_map<node*,node*> parent;

// void theparentfinder(node* root){
// 	if(root==null) return;
// 	if(root->l){
// 		parent[root->l]=root;
// 		theparentfinder(root->l);
// 	}
// 	if(root->r){
// 		parent[root->r]=root;
// 		theparentfinder(root->r);
// 	}
// }

node* finder(node* root,int x){
	if(root==null) return null;
	if(root->data==x) return root;
	node* ans = finder(root->l,x);
	if(!ans) ans = finder(root->r,x);
	return ans;
}

// void DELETE(node* root,int x){
// 	node* findnode = finder(root,x);
// 	theparentfinder(root);
// 	if(findnode->l==null){
// 		if(parent[findnode]->l==findnode)
// 			parent[findnode]->l = findnode->r;
// 		else	
// 			parent[findnode]->r = findnode->r;
// 		return ;
// 	}
// 	node* p = parent[findnode];
// 	node* it=findnode->l;
// 	while(it->r) it=it->r;
// 	it->r = findnode->r;
// 	findnode->r = null;

// 	if(parent[findnode]->l==findnode)
// 		parent[findnode]->l = findnode->l;
// 	else
// 		parent[findnode]->r = findnode->l;
// 	findnode->l = null;
// }

// O(log N) time & O(1) space approach

// node* findmin(node* root){
// 	while(root->l) root=root->l;
// 	return root;
// }

// node* DELETE(node* root,int x){
// 	if(root==null) return null;
// 	else if(x < root->data) root->l = DELETE(root->l,x);
// 	else if(x > root->data) root->r = DELETE(root->r,x);
// 	else{
// 		if(!root->l && !root->r) root=null;
// 		else if(root->l == null){
// 			node* t = root->r;
// 			root->r = t->r;
// 			root->l = t->l;
// 			t->l = null;
// 			t->r = null;
// 			delete t;
// 		}else if(root->r == null){
// 			node* t = root->l;
// 			root->l = t->l;
// 			root->r = t->r;
// 			t->l = null;
// 			t->r = null;
// 			delete t;
// 		}else{
// 			node* t = findmin(root->r);
// 			root->data = t->data;
// 			root->r = DELETE(root->r,t->data);
// 		}
// 	}
// 	return root;
// }

// int KthSmallest(node* root,int x){
// 	stack<node*> s;
// 	node* t = root;
// 	int c = 0;

// 	while(1){
// 		if(t){
// 			s.push(t);
// 			t=t->l;
// 		}else{
// 			if(s.empty()) break;
// 			t = s.top();
// 			s.pop();
// 			c++;
// 			if(c==x) return t->data;
// 			t=t->r;
// 		}
// 	}
// 	return -1;
// }

// bool check(node* root,int a,int b){
// 	if(root==null) return true;
// 	if(root->data < a || root->data > b) return false;
// 	return check(root->l,a,root->data) && check(root->r,root->data,b);
// }

// int LCA(node* root,int a,int b){
// 	node* t=root;

// 	while(1){
// 		if( a<t->data && b<t->data )t=t->l;
// 		else if( a>t->data && b>t->data )t=t->r;
// 		else{
// 			break;
// 		}
// 	}
// 	return t->data;
// }

// node* build(vector<int>& v,int& i,int b){
// 	if(i==v.sz()||v[i]>b) return null;
// 	node* root = new node(v[i++]);
// 	root->l = build(v,i,root->data);
// 	root->r = build(v,i,b);
// 	return root;
// }

// node* buildbst(vector<int>& v){
// 	int i= 0;
// 	node* ans = build(v,i,int_max);
// 	return ans;
// }

// node* insucc(node* root,node* x){
// 	node* ans = null;
// 	while(root){
// 		if(root->data <= x->data) root=root->r;
// 		else{
// 			ans = root;
// 			root=root->l;
// 		}
// 	}
// 	return ans;
// }

// node* inpred(node* root,node* x){
// 	node* ans = null;
// 	while(root){
// 		if(root->data >= x->data) root=root->l;
// 		else{
// 			ans = root;
// 			root=root->r;
// 		}
// 	}
// 	return ans;
// }

void solve()
{	
	// full binary search tree
	// concept of the BST in book
	// structure => same as the tree , the position and value of every nodes are vital

	node* root = new node(10);
	root->l = new node(5);
	root->r = new node(12);
	root->l->l = new node(2);
	root->l->r = new node(8);
	root->l->l->l = new node(1);
	root->l->l->r = new node(3);
	root->l->r->l = new node(6);
	root->l->r->r = new node(9);
	root->r->l = new node(11);
	root->r->r = new node(15);
	root->r->r->l = new node(13);
	root->r->r->r = new node(17);

	// int N = 17;

	// int x;cin>>x;	
	// node* ans = search(root,x);
	// if(ans) cout<<ans->data<<endl;
	// else cout<<"null"<<endl;
	
	// cout<<(step<(1+(int)(log2(N))));
	// int x;cin>>x;
	// cout<<CEIL(root,x)<<endl<<FLOOR(root,x)<<endl;
	// inorder(root);
	// cout<<endl;
	// node* newroot = INSERT(root,x);
	// inorder(newroot);

	// root=DELETE(root,x);
	// inorder(root);

	// Kth smallest element in the BST
	// int ans = KthSmallest(root,x);
	// cout<<ans<<endl;

	// Is Valid BST?
	// cout<<check(root,int_min,int_max);

	// LCA in BST
	// int a,b;cin>>a>>b;
	// cout<<LCA(root,a,b);

	// construct the BST from preorder
	// int n;cin>>n;
	// vector<int> v(n);fr(i,0,n) cin>>v[i];

	// node* r = buildbst(v);
	// preorder(r);

	// inorder successor / predecessor
	// int x;cin>>x;
	// node* n=finder(root,x);

	// cout<<insucc(root,n)->data<<endl;
	// cout<<inpred(root,n)->data<<endl;

	// BST iterator
	// bstit* it = new bstit(root);
	// cout<<it->next()<<endl;
	// cout<<it->next()<<endl;
	// cout<<it->hasnext()<<endl;

	int x;cin>>x;
	bstit* it1 = new bstit(root,false);
	bstit* it2 = new bstit(root,true);

	int i=it1->next();
	int j=it2->next();
	debug(mp(i,j));
	// bool b=false;
	while(i<j){
		if(i+j==x) {
			// b = true;
			// break;
			cout<<i<<" "<<j<<endl;
			i=it1->next();
			j=it2->next();
		}
		else if(i+j<x) i=it1->next();
		else j=it2->next(); 
	}
	// cout<<b;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    #ifndef ONLINE_JUDGE
	freopen("error.txt","w",stderr); 
    #endif
	/*int t;
	cin>>t;
	int p=t;
	while(t--){
		cout<<"Case #"<<p-t<<" : ";
		solve();
	}*/
	solve();
	return 0;
}