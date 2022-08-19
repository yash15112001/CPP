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

void it_pre(node* root){
	if(!root) return;
	stack<node*> st;
	st.push(root);

	while(st.size()){
		auto cv = st.top();
		st.pop();
		cout<<cv->data<<" ";
		if(cv->r) st.push(cv->r);
		if(cv->l) st.push(cv->l);
	}
}

void it_in(node* root){
	if(!root) return;
	stack<node*> st;
	// st.push(root);
	node* t=root;
	while(1){
		if(t){
			st.push(t);
			t=t->l;
		}else{
			if(st.empty()) return;
			t=st.top();
			st.pop();
			cout<<t->data<<" ";
			t=t->r;
		}
	}
}

void it_post(node* root){
	if(!root) return;
	stack<node*> s1,s2;
	s1.push(root);

	while(s1.sz()){
		auto cv = s1.top();
		s1.pop();
		s2.push(cv);
		if(cv->l) s1.push(cv->l);
		if(cv->r) s1.push(cv->r);
	}

	while(s2.sz()){
		cout<<s2.top()->data<<" ";
		s2.pop();
	}
}

void threetraversals(node* root){
	if(!root) return;
	vector<int> pre,in,post;
	stack<pair<node*,int>> st;
	st.push({root,1});

	while(st.size()){
		auto cv = st.top();
		st.pop();
		if(cv.s==1){
			cv.s++;
			pre.pb(cv.f->data);
			st.push(cv);
			if(cv.f->l) st.push({cv.f->l,1});
		}else if(cv.s==2){
			cv.s++;
			in.pb(cv.f->data);
			st.push(cv);
			if(cv.f->r) st.push({cv.f->r,1});
		}else{
			post.pb(cv.f->data);
		}
	}
	debug(pre)
	debug(in)
	debug(post)
}

int gans = int_min;

int diameter(node* root){
	if(!root) return 0;
	int lh = diameter(root->l);
	int rh = diameter(root->r);
	gans = max(gans,lh+rh);
	return 1+max(lh,rh);
}

bool isbalanced(node* root){
	if(!root) return true;
	int lb = isbalanced(root->l);
	if(lb==-1) return -1;
	int rb = isbalanced(root->r);
	if(rb==-1) return -1;
	if(abs(lb-rb)>1) return -1;
	return 1+max(lb,rb);
}

int fans = 0;

void depth(node* root,int rootd){
	if(!root) return;
	if(root->l || root->r) fans = max(fans,rootd+1);
	if(root->l) depth(root->l,rootd+1);
	if(root->r) depth(root->r,rootd+1);
}

bool isleaf(node* root){
	return !root->l && !root->r ;
}

void left(node* root,vector<int>& ans){
	node* t=root->l;
	while(t){
		if(!isleaf(t)) ans.pb(t->data);
		if(t->l) t=t->l;
		else t=t->r;
	}
}

void leaf(node* root,vector<int>& ans){
	if(isleaf(root)){ans.pb(root->data);return;}
	leaf(root->l,ans);
	leaf(root->r,ans);
}

void right(node* root,vector<int>& ans){
	vector<int> temp;
	node* t=root->r;
	while(t){
		if(!isleaf(t)) temp.pb(t->data);
		if(t->r) t=t->r;
		else t=t->l;
	}
	reverse(all(temp));
	for(auto &e:temp) ans.pb(e);
}

vector<int> boundry(node* root){
	vector<int> ans;
	if(!root) return ans;
	ans.pb(root->data);
	if(isleaf(root)) return ans;
	left(root,ans);
	leaf(root,ans);
	right(root,ans);
	return ans;
}

void vertical(node* root){
	map<int,map<int,multiset<node*>>> m;
	queue<pair<node*,pair<int,int>>> q;
	q.push({root,{0,0}});

	while(q.sz()){
		auto cv = q.front();
		q.pop();
		node* v = cv.f;
		int vertical = cv.s.f;
		int level = cv.s.s;
		m[vertical][level].insert(v);
		if(v->l)
			q.push({v->l,{vertical-1,level+1}});
		if(v->r)
			q.push({v->r,{vertical+1,level+1}});
	}

	for(auto &e:m){
		for(auto &ee:e.s){
			for(auto &t:ee.s){
				cout<<t->data<<" ";
			}
		}
	}
}

void diagnol(node* root){
	queue<node*> q;
	q.push(root);
	while(q.sz()){
		auto cv = q.front();
		q.pop();
		while(cv){
			if(cv->l) q.push(cv->l);
			cout<<cv->data<<" ";
			cv=cv->r;
		}
	}
}

void leftview(node* root){
	if(!root) return;
	queue<node*> q;
	q.push(root);

	while(q.sz()){
		int t=q.sz();
		cout<<q.front()->data<<" ";
		fr(i,0,t){
			auto v = q.front();
			q.pop();
			if(v->l)
				q.push(v->l);
			if(v->r)
				q.push(v->r);
		}
	}
}

void rightview(node* root){
	if(!root) return;
	queue<node*> q;
	q.push(root);

	while(q.sz()){
		int t=q.sz();
		cout<<q.back()->data<<" ";
		fr(i,0,t){
			auto v = q.front();
			q.pop();
			if(v->l) q.push(v->l);
			if(v->r) q.push(v->r);
		}
	}
}

void topview(node* root){
	if(!root) return;
	map<int,node*> m;
	queue<pair<node*,int>> q;
	q.push({root,0});

	while(q.sz()){
		auto cv = q.front();
		q.pop();
		if(m.find(cv.s)==m.end())
			m[cv.s]=cv.f;
		if(cv.f->l)
			q.push({cv.f->l,cv.s-1});
		if(cv.f->r)
			q.push({cv.f->r,cv.s+1});
	}

	for(auto e:m)
		cout<<e.s->data<<" ";
}

void bottomview(node* root){
	if(!root) return;
	map<int,node*> m;
	queue<pair<node*,int>> q;
	q.push({root,0});

	while(q.sz()){
		auto cv = q.front();
		q.pop();
		// if(m.find(cv.s)==m.end())
		m[cv.s]=cv.f;
		if(cv.f->l)
			q.push({cv.f->l,cv.s-1});
		if(cv.f->r)
			q.push({cv.f->r,cv.s+1});
	}

	for(auto e:m)
		cout<<e.s->data<<" ";
}

bool path(node* root,int x,vector<int>& ans){
	if(!root) return 0;
	if(root->data == x){ans.pb(root->data);return 1;}
	bool l = path(root->l,x,ans);
	if(l) {ans.pb(root->data);return 1;}
	bool r = path(root->r,x,ans);
	if(r) {ans.pb(root->data);return 1;}
	return 0;
}

node* lca(node* root,int x,int y){
	if(!root || root->data == x || root->data == y) return root;
	node* l = lca(root->l,x,y);
	node* r = lca(root->r,x,y);
	if(!l) return r;
	if(!r) return l;
	return root;
}

int width(node* root){
	if(!root) return 0;
	int ans=0;
	queue<pair<node*,int>> q;
	q.push({root,0});

	while(q.sz()){
		int n = q.sz();
		int min = q.front().s;
		int l,r;
		fr(i,0,n){
			auto cv = q.front();
			q.pop();
			int c = cv.s;
			c-=min;
			if(i==0) l=c;
			if(i==n-1) r=c;
			if(cv.f->l) q.push({cv.f->l,2*c+1});
			if(cv.f->r) q.push({cv.f->r,2*c+2});
		}
		ans = max(ans,r-l+1);
	}
	return ans;
}

void inorder(node* root){
	if(!root) return;
	inorder(root->l);
	cout<<root->data<<" ";
	inorder(root->r);
}

void preorder(node* root){
	if(!root) return;
	cout<<root->data<<" ";
	preorder(root->l);
	preorder(root->r);
}

void childsum(node* root){
	if(!root) return;
	int c=0;
	if(root->l) c+=root->l->data;
	if(root->r) c+=root->r->data;
	if(root->data <= c) root->data = c;
	else{
		if(root->l) root->l->data = c;
		if(root->r) root->r->data = c;
	}
	childsum(root->l);
	childsum(root->r);
	int r=0;
	if(root->l) r+=root->l->data;
	if(root->r) r+=root->r->data;
	if(root->l || root->r) root->data = r;
}

bool checkforcbt(node* root){
	if(!root) return 1;
	int c=0;
	if(root->l) ++c;
	if(root->r) ++c;
	return (!(c%2) && checkforcbt(root->l) && checkforcbt(root->r));
}

node* t(vector<int> pre,int pre_st,int pre_end,vector<int> in,int in_st,int in_end,unordered_map<int,int> m){
	if(pre_st>pre_end || in_st>in_end) return null;
	node* root = new node(pre[pre_st]);
	int le = m[root->data] - in_st;
	root->l = t(pre,pre_st+1,pre_st+le,in,in_st,m[pre[pre_st]]-1,m);
	root->r = t(pre,pre_st+le+1,pre_end,in,m[pre[pre_st]]+1,in_end,m);
	return root;
}

node* build(vector<int> pre,vector<int> in){
	// int n = pre.sz();
	unordered_map<int,int> m;
	fr(i,0,in.sz()) m.insert({in[i],i});
	debug(m)
	node* root = t(pre,0,pre.sz()-1,in,0,in.sz()-1,m);
	return root;
}

node* build(vector<int> v,int i,int j){
	if(i>j) return null;
	if(i==j) return (new node(v[i]));
	int m = (i+j)/2;
	node* root = new node(v[m]);
	root->l = build(v,i,m-1);
	root->r = build(v,m+1,j);
	return root;
}

node* bst(vector<int>& v){
	int i=0,j=v.sz()-1;
	node* root = build(v,i,j);
	return root;
}

void solve()
{	
	// node* root = new node(1);
	// root->l = new node(2);
	// root->r = new node(3);
	// root->l->l = new node(4);
	// root->l->r = new node(5);
	// root->r->l = new node(6);
	// root->r->r = new node(7);
	// root->r = new node(3);
	// root->l->l = new node(4);
	// root->l->l->l = new node(8);
	// root->l->l->r = new node(9);
	// root->l->r = new node(5);
	// root->r->l = new node(6);
	// root->r->l->l = new node(10);
	// root->r->l->l->l = new node(14);
	// root->r->l->r = new node(11);
	// root->r->r = new node(7);
	// root->r->r->l = new node(12);
	// root->r->r->l->r = new node(15);
	// root->r->r->r = new node(13);
	// root->r->r->r->l = new node(16);
	// root->r->r->r->r = new node(17);

	// it_in(root);
	// cout<<endl;
	// it_pre(root);
	// cout<<endl;
	// it_post(root);
	// cout<<endl;
	// threetraversals(root);
	// int ans = diameter(root);
	// cout<<ans;
	// depth(root,0);
	// cout<<fans<<endl;

	// level order,zigzag,boundry,vertical order traversal
	// left,right,top,bottom view
	
	// boundry
	// vector<int> ans = boundry(root);
	// for(auto &e:ans) cout<<e<<" ";

	// vertical
	// vertical(root);	

	// diagnol
	// diagnol(root);

	// bottomview(root);
	
	// vector<int> ans;
	// int x;cin>>x;
	// bool b = path(root,x,ans);
	// reverse(all(ans));
	// debug(ans);

	// int a,b;cin>>a>>b;
	// node* ans = lca(root,a,b);
	// if(ans) cout<<ans->data<<" ";

	// int ans = width(root);
	// cout<<ans<<endl;

	// inorder(root);
	// // cout<<endl;
	// // childsum(root);
	// // inorder(root);

	// // cout<<checkforcbt(root)<<endl;

	// int n;cin>>n;
	// vector<int> pre(n),in(n); 
	// fr(i,0,n) cin>>pre[i];
	// fr(i,0,n) cin>>in[i];

	// node* root1 = build(pre,in);

	// preorder(root1);cout<<endl;
	// inorder(root1);

	// construct the height balanced binary tree from given sorted array
	int n;cin>>n;
	vector<int> v(n);
	fr(i,0,n) cin>>v[i];

	node* root = bst(v);
	inorder(root);
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