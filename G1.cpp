#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define fr(i,a,n) for(auto i=a;i<n;i++)
#define rf(i,n,a) for(auto i=n;i>a;i--)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define um unordered_map
#define sz size
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define all(x) x.begin(),x.end()
#define scanvector(v,n) int n;cin>>n;vector<int> v(n);fr(i,0,n) cin>>v[i];
#define int_max INT_MAX
#define int_min INT_MIN
#define null NULL
const int M = 1e9 + 7;

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
  
#define pbds_i tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define pbds_c tree<char, null_type,less<char>, rb_tree_tag,tree_order_statistics_node_update>
#define pbds_ll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define pbds_d tree<double, null_type,less<double>, rb_tree_tag,tree_order_statistics_node_update>
#define pbds_s tree<string, null_type,less<string>, rb_tree_tag,tree_order_statistics_node_update>

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

void _print(char x){ cerr<<x; }
void _print(int x){ cerr<<x; }
void _print(string x){ cerr<<x; }
void _print(string x,int a,int b){ cerr<<"["; for(int i=a;i<b;i++){char t=x[i];_print(t);cerr<<" ";} cerr<<"]";}
void _print(ll x){ cerr<<x; }
void _print(bool x){ cerr<<x; }

template<class T>void _print(stack<T> st){ cerr<<"[ "; while(!st.empty()) { _print(st.top()); cerr<<" "; st.pop();} cerr<<"]"; }
template<class T>void _print(queue<T> q){ cerr<<"[ "; while(!q.empty()) { _print(q.front()); cerr<<" "; q.pop();} cerr<<"]"; }
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
	}

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

void inorder1(node* root){
	if(!root) return;
	inorder1(root->l);
	cout<<root->data<<" ";
	inorder1(root->r);
}

// bool search(node* root,int x){
// 	if(!root) return false;
// 	if(root->data==x) return true;
// 	if(root->data > x) return search(root->l,x);
// 	else return search(root->r,x);
// }

bool search(node* root,int x){
	while(root && root->data!=x){
		if(root->data > x) root=root->l;
		else root=root->r;
	}
	return root && root->data==x;
}

int __ceil(node* root,int x){
	int ans;
	while(root){
		if(root->data==x){
			ans = root->data;
			break; 
		}else if(root->data > x){
			ans = root->data;
			root=root->l;
		}else root=root->r;
	}
	return ans;
}

int __floor(node* root,int x){
	int ans;
	while(root){
		if(root->data==x){
			ans = root->data;
			break;
		}else if(root->data < x){
			ans = root->data;
			root=root->r;
		}else root=root->l;
	}
	return ans;
}

void insert(node* root,int x){
	if(!root) {root = new node(x);return;}
	while(1){
		// if(root->data==x) break;
		if(root->data >= x){
			if(root->l) root=root->l;
			else {root->l = new node(x);break;}
		}else{
			if(root->r) root=root->r;
			else {root->r = new node(x);break;}
		}
	}
}

node* findmin(node* root){
	while(root->l) root=root->l;
	return root;
}

node* __delete(node* root,int x){
	if(!root) return null;
	if(root->data > x) 
		root->l=__delete(root->l,x);
	else if(root->data < x)
		root->r= __delete(root->r,x);
	else{
		if(!root->r && !root->l){
			root=null;
		}else if(root->r == null){
			node* t = root->l;
			free(root);
			return t;
		}else if(root->l == null){
			node* t = root->r;
			free(root);
			return t;
		}else{
			node* p=findmin(root->r);
			root->data = p->data;
			root->r = __delete(root->r,p->data);
		}
	}
	return root;
}

int kthsmallest(node* root,int k){
	if(!root) return -1;
	stack<node*> s;
	int c=0;
	node* t=root;
	while(1){
		if(t){
			s.push(t);
			t=t->l;
		}else{
			if(s.empty()) break;
			t=s.top();
			s.pop();
			c++;
			if(c==k) return t->data;
			t=t->r;
		}
	}
	return -1;
}

bool isbst(node* root,int a,int b){
	if(!root) return 1;
	if(root->data < a||root->data > b) return 0;
	return isbst(root->l,a,root->data)&&isbst(root->r,root->data,b);
}

int lca(node* root,int a,int b){
	while(1){
		if(root->data >a && root->data >b) root=root->l;
		else if(root->data <a && root->data <b) root=root->r;
		else break;
	}
	return root->data;
}

node* constructbst(vector<int>& v,int i,int d){
	if(i==v.sz()||v[i]>d) return null;
	node* root = new node(v[i++]);
	root->l = constructbst(v,i,root->data);
	root->r = constructbst(v,i,d);
	return root;
}

int insucc(node*root,int x){
	int ans = -1;
	while(root){
		if(root->data<=x)
			root=root->r;
		else{
			ans = root->data;
			root=root->l;
		}
	}
	return ans;
}

int inpred(node*root,int x){
	int ans = -1;
	while(root){
		if(root->data>=x)
			root=root->l;
		else{
			ans = root->data;
			root=root->r;
		}
	}
	return ans;
}

class bstit{

	stack<node*> s;
	bool rev = true;

	void pushall(node* root){
		for(;root;){
			s.push(root);
			if(rev) root=root->r;
			else root=root->l;
		}
	}

public:

	bstit(node* root,bool b){
		rev = b;
		pushall(root);
	}

	bool hasnext(){
		return !s.empty();
	}

	int next(){
		node* t=s.top();
		s.pop();
		if(rev) pushall(t->l);
		else pushall(t->r);
		return t->data;
	}
};

node* f;
node* m;
node* l;
node* p;

void inorder(node* root){
	if(!root) return;
	inorder(root->l);
	if(p && p->data > root->data){
		if(!f){
			f=p;
			m=root;
		}
		else l=root;
	}
	p = root;
	inorder(root->r);
}

void recoverbst(node* root){
	f=null;
	m=null;
	l=null;
	p=new node(-1);
	inorder(root);
	if(f && l) swap(f->data,l->data);//cout<<f->data<<" "<<l->data<<endl;
	else swap(f->data,m->data);//cout<<f->data<<" "<<m->data<<endl;
}

void solve()
{	
	// node* root = new node(10);
	// root->l = new node(5);
	// root->r = new node(12);
	// root->l->l = new node(2);
	// root->l->r = new node(8);
	// root->r->l = new node(11);
	// root->r->r = new node(15);
	// root->l->l->l = new node(1);
	// root->l->l->r = new node(3);
	// root->l->r->l = new node(6);
	// root->l->r->r = new node(9);
	// root->r->r->l = new node(13);
	// root->r->r->r = new node(17);

	// int x;cin>>x;
	// bool ans = search(root,x);
	// cout<<ans<<endl;

	// ceil v>=x
	// int x;cin>>x;
	// int ans = __ceil(root,x);
	// cout<<ans<<endl;

	// floor <=x
	// int ans2 = __floor(root,x);
	// cout<<ans2<<endl;

	// insert/delete in bst
	// int x;cin>>x;
	// inorder(root);
	// cout<<endl;
	// // insert(root,x);
	// // inorder(root);
	// root = __delete(root,x);
	// inorder(root);

	// kth smallest in bst
	// int k;cin>>k;
	// int ans = kthsmallest(root,k);
	// cout<<ans<<endl;

	// validate the bst
	// bool b = isbst(root,int_min,int_max);
	// cout<<b<<endl;

	// lca of a and b in bst
	// int a,b;cin>>a>>b;
	// int ans = lca(root,a,b);
	// cout<<ans<<endl;

	// construct bst from preorder traversal
	// cout<<endl;
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];

	// node* r = constructbst(v,0,int_max);
	// inorder(r);

	// inorder successor/predcsesor
	// int x;cin>>x;
	// int ans = insucc(root,x);
	// cout<<ans<<endl;
	// cout<<inpred(root,x)<<endl;

	// bstit
	// bstit* it1 = new bstit(root,false);
	// bstit* it2 = new bstit(root,true);

	// int x;cin>>x;
	// int i=it1->next();
	// int j=it2->next();
	// debug(mp(i,j))

	// while(i<j){
	// 	if(i+j==x){
	// 		cout<<i<<" "<<j<<endl;
	// 		i=it1->next();
	// 		j=it2->next();
	// 	}else if(i+j>x){
	// 		j=it2->next();
	// 	}else{
	// 		i=it1->next();
	// 	}
	// }

	// ** recover the bst

	node* root = new node(10);
	root->l = new node(5);
	root->r = new node(6);
	root->l->l = new node(2);
	root->l->r = new node(8);
	root->r->l = new node(11);
	root->r->r = new node(15);
	root->l->l->l = new node(1);
	root->l->l->r = new node(3);
	root->l->r->l = new node(12);
	root->l->r->r = new node(9);
	root->r->r->l = new node(13);
	root->r->r->r = new node(17);

	inorder1(root);
	recoverbst(root);
	cout<<endl;
	inorder1(root);
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