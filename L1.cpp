#include<bits/stdc++.h>
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

const int N = 1001;
// int adjmat[N][N];
vector<vector<int>> adjmat(N,vector<int>(N,INT_MAX));
vector<int> edges(N);
int grid[N][N],visgrid[N][N];
vector<int> adjlist[N],revadjlist[N],adjlist2[N],cadjlist[N];
vector<int> vis(N),height(N),depth(N),level(N,INT_MAX),d(N,INT_MAX);
vector<int> subtreesum(N),evens(N),parent1(N);
vector<int> parent(N),size(N),color(N);

// void dfs(int v){
// 	vis[v]=1;
// 	cout<<v<<" ";
// 	for(auto c:adjlist[v]){
// 		if(vis[c]) continue;
// 		dfs(c);
// 	}
// }

// void DFS(int v,int k){
// 	vis[v]=k;
// 	cout<<v<<" ";
// 	for(auto c:adjlist[v]){
// 		if(!vis[c]) {DFS(c,k);}
// 	}
// }

// bool DFS1(int v,int p){
// 	vis[v]=1;
// 	bool b=false;
// 	for(auto c:adjlist[v]){
// 		if(vis[c] && c==p) continue;
// 		if(vis[c]) return true;
// 		if(b |= DFS1(c,v)) return true;
// 	}
// 	return b;
// }

// void DFS2(int n,int m,int i,int j){
// 	if(i<0 || j<0 || i>=n || j>=m || visgrid[i][j] || !grid[i][j]) return;
// 	visgrid[i][j]=1;
// 	DFS2(n,m,i+1,j);
// 	DFS2(n,m,i,j+1);
// 	DFS2(n,m,i-1,j);
// 	DFS2(n,m,i,j-1);
// }

// void DFS3(int v,int p){
// 	for(auto c:adjlist[v]){
// 		if(c==p) continue;
// 		depth[c]=depth[v]+1;
// 		DFS3(c,v);
// 		height[v]=max(height[v],height[c]+1);
// 	}
// }

// void DFS4(int v){
// 	vis[v]=1;
// 	for(auto c:adjlist[v]){
// 		if(vis[c]) continue;
// 		depth[c]=depth[v]+1;
// 		DFS4(c);
// 		height[v]=max(height[v],height[c]+1);
// 	}
// }

// void DFS5(int v,int p){
// 	subtreesum[v]+=v;
// 	evens[v]+=(v%2==0?1:0);
// 	for(auto c:adjlist[v]){
// 		if(c==p) continue;		
// 		DFS5(c,v);
// 		subtreesum[v]+=subtreesum[c];
// 		evens[v]+=evens[c];
// 	}
// }

// void DFS6(int v,int p){
// 	for(auto c:adjlist[v]){
// 		if(c==p) continue;
// 		depth[c]=1+depth[v];
// 		DFS6(c,v);
// 	}
// }

// void DFS7(int v,int p){
// 	parent[v]=p;
// 	for(auto c:adjlist[v]){
// 		if(c==p) continue;
// 		depth[c]=1+depth[v];
// 		DFS7(c,v);
// 	}
// }

// void bfs(int v){
// 	queue<int> q;
// 	q.push(v);
// 	vis[v]=1;
// 	level[v]=0;
// 	while(!q.empty()){
// 		auto cv = q.front();
// 		q.pop();
// 		if(cv) cout<<cv<<" ";
// 		for(auto c:adjlist[cv]){
// 			if(!vis[c] && level[cv]+1<level[c]){
// 				level[c] = 1+level[cv]; 
// 				vis[c] = 1;
// 				q.push(c);
// 			}
// 		}
// 	}
// }

// void zeroonebfs(int v){
// 	deque<int> q;
// 	q.pb(v);
// 	level[v]=0;
// 	vis[v]=1;
// 	while(!q.empty()){
// 		auto cv = q.front();
// 		q.ppf();
// 		cout<<cv<<" ";
// 		for(auto c:adjlist[cv]){
// 			int ccv = c.f;
// 			int wt = c.s;
// 			if(level[cv]+wt<level[ccv]){
// 				level[ccv]=level[cv]+wt;
// 				if(wt) q.pb(ccv);
// 				else q.pf(ccv);
// 				vis[ccv]=1;
// 			}
// 		}
// 	}
// }

// void msbfs(vector<int>& v){
// 	queue<int> q;
// 	for(auto e:v){
// 		q.push(e);
// 		vis[e]=1;
// 		level[e]=0;
// 	}
// 	while(!q.empty()){
// 		auto cv=q.front();
// 		q.pop();
// 		cout<<cv<<" ";
// 		for(auto c:adjlist[cv]){
// 			if(!vis[c] && level[cv]+1<level[c]){
// 				vis[c]=1;
// 				level[c]=level[cv]+1;
// 				q.push(c);
// 			}
// 		}
// 	}
// }

// void dijkstra(int v,int n){
// 	fr(i,1,n+1) vis[i]=0,d[i]=INT_MAX;
// 	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
// 	// set<pair<int,int>> s;
// 	// s.insert({0,v});
// 	pq.push({0,v});
// 	d[v]=0;

// 	while(!pq.empty()){
// 		// auto p = *s.begin();
// 		auto p = pq.top();
// 		// s.erase(s.begin());
// 		pq.pop();
// 		int cv = p.s;
// 		if(vis[cv]) continue;
// 		vis[cv]=1;

// 		for(auto c:adjlist[cv]){
// 			int ccv = c.f;
// 			int wt = c.s;
// 			if(d[cv]+wt<d[ccv]){
// 				d[ccv]=d[cv]+wt;
// 				// s.insert({d[ccv],ccv});
// 				pq.push({d[ccv],ccv});
// 			}
// 		}
// 	}

// 	fr(i,1,n+1) d[i]==INT_MAX?cout<<"I ":cout<<d[i]<<" ";
// 	cout<<endl;
// }

// void floydwarshell(int n){
// 	bool b=false;
// 	fr(k,1,n+1){
// 		fr(i,1,n+1){
// 			fr(j,1,n+1){
// 				if(adjmat[i][k]!=INT_MAX && adjmat[k][j]!=INT_MAX)
// 					adjmat[i][j]=min(adjmat[i][j],adjmat[i][k]+adjmat[k][j]);
// 				if(i==j && adjmat[i][j]<0){b=true;break;}
// 			}
// 			if(b) break;
// 		}
// 		if(b) break;
// 	}
// 	if(b) cout<<"Negative cycle detected"<<endl;
// 	else{
// 		fr(i,1,n+1){
// 			fr(j,1,n+1){
// 				if(adjmat[i][j]==INT_MAX) cout<<"I ";
// 				else cout<<adjmat[i][j]<<" ";
// 			}
// 			cout<<endl;
// 		}
// 	}
// }

// void make(int v){
// 	parent[v]=v;
// 	size[v]=1;
// }

// int find(int v){
// 	if(v==parent[v]) return v;
// 	else return parent[v]=find(parent[v]);
// }

// void Union(int v,int u){
// 	u=find(u);
// 	v=find(v);
// 	if(v!=u){
// 		if(size[u]>size[v]) swap(u,v);
// 		parent[u]=v;
// 		size[v]+=size[u];
// 	}
// }

// stack<int> t;

// void topologicaldfs(int v){
// 	vis[v]=1;
// 	for(auto c:adjlist[v]){
// 		if(!vis[c]) topologicaldfs(c);
// 	}
// 	t.push(v);
// }

// void topologicalbfs(int n){
// 	queue<int> q;
// 	vector<int> indegree(n+1,0);
// 	fr(i,1,n+1){
// 		for(auto c:adjlist[i])
// 			indegree[c]++;
// 	}
// 	fr(i,1,n+1){
// 		if(indegree[i]==0) q.push(i);
// 	}
// 	while(!q.empty()){
// 		auto cv=q.front();
// 		q.pop();
// 		cout<<cv<<" ";
// 		for(auto c:adjlist[cv]){
// 			indegree[c]--;
// 			if(!indegree[c]) q.push(c);
// 		}
// 	}
// }

// int t=1;
// vector<int> in(N),out(N),low(N);

// void DFS8(int v){
// 	vis[v]=1;
// 	in[v]=t++;
// 	for(auto c:adjlist[v]){
// 		if(!vis[c]) DFS8(c);
// 	}
// 	out[v]=t++;
// }

// bool bipartite_dfs(int v,int cc){
// 	vis[v]=1;
// 	color[v]=cc;
// 	for(auto c:adjlist[v]){
// 		if(!vis[c]){
// 			if(!bipartite_dfs(c,cc^1))return false;
// 		}
// 		else if(color[c]==color[v]) return false;
// 	}
// 	return true;
// }

// int t;

// void DFS9(int v,int p){
// 	vis[v]=1;
// 	in[v]=low[v]=t++;
// 	for(auto c:adjlist[v]){
// 		if(c==p) continue;
// 		if(vis[c]){
// 			// backedge 
// 			low[v]=min(low[v],in[c]);
// 		}else{
// 			// forwardedge
// 			DFS9(c,v);
// 			if(low[c]>in[v]){
// 				cout<<c<<" "<<v<<endl;
// 			}
// 			low[v]=min(low[v],low[c]);
// 		}
// 	}
// }

// void DFS9(int v,int p){
// 	vis[v]=1;
// 	in[v]=low[v]=t++;
// 	for(auto c:adjlist[v]){
// 		if(c==p) continue;
// 		if(vis[c]){
// 			low[v]=min(low[v],in[c]);
// 		}else{
// 			DFS9(c,v);
// 			cout<<c<<" "<<v<<endl;
// 			low[v]=min(low[v],low[c]);
// 		}
// 	}
// }

// vector<int> tscc;

// void DFS10(int v){
// 	vis[v]=1;
// 	tscc.pb(v);
// 	for(auto c:adjlist[v]){
// 		if(!vis[c]) DFS10(c);
// 	}
// }

// vector<int> order,scc,who(N);

// void DFSorder(int v){
// 	vis[v]=1;
// 	for(auto c:adjlist[v]){
// 		if(!vis[c]) DFSorder(c);
// 	}
// 	order.pb(v);
// }

// void DFSSCC(int v){
// 	vis[v]=1;
// 	for(auto c:revadjlist[v]){
// 		if(!vis[c]) DFSSCC(c);
// 	}
// 	scc.pb(v);
// }

// void dfs(int v,int p){
// 	vis[v]=1;
// 	parent[v]=p;
// 	for(auto c:adjlist[v]){
// 		if(!vis[c]) depth[c]=1+depth[v],dfs(c,v);
// 	}
// }

// int LCA[N+1][N+1];

// int binupliftLCA(int a,int b,int N){
// 	if(depth[a]<depth[b]) swap(a,b);
// 	int d = depth[a]-depth[b];
// 	while(d){
// 		int i=log2(d);
// 		a=LCA[a][i];
// 		d-=(1<<i);
// 	}
// 	if(a==b) return a;
// 	for(int i=log2(N);i>=0;i--){
// 		if(LCA[a][i]!=-1 && LCA[a][i]!=LCA[b][i]){
// 			a=LCA[a][i];
// 			b=LCA[b][i];
// 		}
// 	}
// 	return parent[a];
// }

// void dfs(int s,int d,int& ans){
// 	if(s==d){
// 		ans++;
// 		vis[d]=0;
// 		return;
// 	}
// 	for(auto c:adjlist[s]){
// 		if(!vis[c]){
// 			vis[c]=1;
// 			dfs(c,d,ans);
// 		}
// 	}
// 	vis[s]=0;
// }

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


void preorder(node* root){
	if(!root) return;
	cout<<root->data<<" ";
	preorder(root->l);
	preorder(root->r);
}


void inorder(node* root){
	if(!root) return;
	inorder(root->l);
	cout<<root->data<<" ";
	inorder(root->r);
}

void postorder(node* root){
	if(!root) return;
	postorder(root->l);
	postorder(root->r);
	cout<<root->data<<" ";
}

void it_pre(node* root){
	if(!root) return;
	stack<node*> s;
	s.push(root);

	while(s.sz()){
		auto cn=s.top();
		s.pop();
		cout<<cn->data<<" ";
		if(cn->r) s.push(cn->r);
		if(cn->l) s.push(cn->l);
	}
}

void it_in(node* root){
	if(!root) return;
	stack<node*> s;
	node* t=root;

	while(1){
		if(t){
			s.push(t);
			t=t->l;
		}else{
			if(s.empty()) break;
			t=s.top();
			s.pop();
			cout<<t->data<<" ";
			t=t->r;
		}
	}
}

void it_post2(node* root){
	if(!root) return;
	stack<node*> s1,s2;
	s1.push(root);

	while(s1.sz()){
		auto cn=s1.top();
		s1.pop();
		s2.push(cn);
		if(cn->l) s1.push(cn->l);
		if(cn->r) s1.push(cn->r);
	}

	while(s2.sz()){
		cout<<s2.top()->data<<" ";
		s2.pop();
	}
}

void all_three(node* root){
	stack<pair<node*,int>> s;
	vector<int> pre,in,post;
	s.push(mp(root,1));

	while(s.sz()){
		auto cv = s.top();
		s.pop();
		if(cv.s==1){
			cv.s++;
			pre.pb(cv.f->data);
			s.push(cv);
			if(cv.f->l) s.push(mp(cv.f->l,1));
		}else if(cv.s==2){
			cv.s++;
			in.pb(cv.f->data);
			s.push(cv);
			if(cv.f->r) s.push(mp(cv.f->r,1));
		}else{
			post.pb(cv.f->data);
		}
	}

	for(auto e:pre) cout<<e<<" ";
	cout<<endl;

	for(auto e:in) cout<<e<<" ";
	cout<<endl;

	for(auto e:post) cout<<e<<" ";
	cout<<endl;
}

bool isBalanced(node* root){
	if(root==null) return 0;
	int lh = isBalanced(root->l);
	if(lh==-1) return -1;
	int rh = isBalanced(root->r);
	if(rh==-1) return -1;
	if(abs(lh-rh)>1) return -1;
	return 1+max(lh,rh);
}

int _height(node* root){
	if(!root) return 0;
	int lh = _height(root->l);
	int rh = _height(root->r);
	return height[root->data]=1+max(lh,rh);
}

void _depth(node* root){
	if(!root) return;
	queue<node*> q;
	q.push(root);
	depth[root->data]=0;

	while(!q.empty()){
		auto cv=q.front();
		q.pop();
		if(cv->l) {depth[cv->l->data]=depth[cv->data]+1;q.push(cv->l);}
		if(cv->r) {depth[cv->r->data]=depth[cv->data]+1;q.push(cv->r);}
	}
}
	
int ans = int_min;

int diameter(node* root){
	if(!root) return 0;
	int lh = diameter(root->l);
	int rh = diameter(root->r);
	ans = max(ans,lh+rh);
	return 1+max(lh,rh);
}

int maxpathsum(node* root){
	if(!root) return 0;
	int lh = maxpathsum(root->l);
	int rh = maxpathsum(root->r);
	ans = max(ans,lh+rh+root->data);
	return max(lh,rh)+root->data;
}

vector<int> zigzagtraversal(node* root){
	vector<int> ans;
	queue<node*> q;
	q.push(root);
	bool ltor=true;

	while(!q.empty()){
		int s=q.sz();
		vector<node*> v(s);
		fr(i,0,s){
			auto cv = q.front();
			q.pop();
			v[i] = cv;
		}
		for(auto e:v){
			if(e->l) q.push(e->l);
			if(e->r) q.push(e->r);
		}
		if(!ltor) reverse(all(v));
		for(auto e:v){
			ans.pb(e->data);
		}
		ltor = !ltor;
	}

	return ans;
}

bool isleaf(node* root){return((!(root->l))&&(!(root->r)));}

void left(node* root,vector<int>& ans){
	node* t=root->l;
	while(t){
		if(!isleaf(t)) ans.pb(t->data);
		if(t->l) t=t->l;
		else t=t->r;
	}
}

void leaves(node* root,vector<int>& ans){
	if(isleaf(root)) {ans.pb(root->data);}
	if(root->l) leaves(root->l,ans);
	if(root->r) leaves(root->r,ans);
}

void right(node* root,vector<int>& ans){
	node* t=root->r;
	vector<int> temp;
	while(t){
		if(!isleaf(t)) temp.pb(t->data);
		if(t->r) t=t->r;
		else t=t->l;
	}
	reverse(all(temp));
	for(auto e:temp) ans.pb(e);
}

vector<int> boundrytraversal(node* root){
	vector<int> ans;
	if(!root) return ans;
	ans.pb(root->data);
	if(isleaf(root)) return ans;
	left(root,ans);
	leaves(root,ans);
	right(root,ans);
	return ans;
}

vector<int> vreticalorder(node* root){
	map<int,map<int,multiset<node*>>> m;
	queue<pair<node*,pair<int,int>>> q;
	q.push(mp(root,mp(0,0)));
	vector<int> ans;
	while(!q.empty()){
		auto cv = q.front();
		q.pop();
		node* v = cv.f;
		int vertical = cv.s.f;
		int level = cv.s.s;
		m[vertical][level].insert(v);
		if(v->l){
			q.push(mp(v->l,mp(vertical-1,level+1)));
		}
		if(v->r){
			q.push(mp(v->r,mp(vertical+1,level+1)));
		}
	}

	for(auto e:m){
		for(auto ee:e.s){
			for(auto eee:ee.s){
				ans.pb(eee->data);
			}
		}
	}

	return ans;
}

vector<int> topview(node* root){
	vector<int> ans;
	queue<pair<node*,int>> q;
	map<int,int> m;
	q.push(mp(root,0));

	while(!q.empty()){
		auto cv = q.front();
		q.pop();
		node* v = cv.f;
		int ver = cv.s;
		if(m.find(ver)==m.end())
			m.insert({ver,v->data});
		if(v->l){
			q.push(mp(v->l,ver-1));
		}
		if(v->r){
			q.push(mp(v->r,ver+1));
		}
	}

	for(auto p:m)
		ans.pb(p.s);

	return ans;
}

vector<int> bottomview(node* root){
	vector<int> ans;
	queue<pair<node*,int>> q;
	map<int,int> m;
	q.push(mp(root,0));

	while(!q.empty()){
		auto cv = q.front();
		q.pop();
		node* v = cv.f;
		int ver = cv.s;
		m[ver] = v->data;
		if(v->l){
			q.push(mp(v->l,ver-1));
		}
		if(v->r){
			q.push(mp(v->r,ver+1));
		}
	}

	for(auto p:m)
		ans.pb(p.s);

	return ans;
}

vector<int> leftview(node* root){
	vector<int> ans;
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		int s = q.sz();
		auto cv = q.front();
		ans.pb(cv->data);
		fr(i,0,s){
			auto v = q.front();
			q.pop();
			if(v->l){
				q.push(v->l);
			}
			if(v->r){
				q.push(v->r);
			}
		}
	}

	return ans;
}

vector<int> rightview(node* root){
	vector<int> ans;
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		int s = q.sz();
		auto cv = q.back();
		ans.pb(cv->data);
		fr(i,0,s){
			auto v = q.front();
			q.pop();
			if(v->l){
				q.push(v->l);
			}
			if(v->r){
				q.push(v->r);
			}
		}
	}

	return ans;
}

vector<int> anspath;

bool path(node* root,int x){
	if(!root) return 0;
	if(root->data==x) {anspath.pb(root->data);return 1;}
	bool l = path(root->l,x);
	if(l) {anspath.pb(root->data);return 1;}
	bool r = path(root->r,x);
	if(r) {anspath.pb(root->data);return 1;}
	return 0;
}

node* LCA(node* root,int x,int y){
	if(!root || root->data==x || root->data==y) return root;
	node* l = LCA(root->l,x,y);
	node* r = LCA(root->r,x,y);
	if(!l) return r;
	if(!r) return l;
	return root;
}

int width(node* root){
	int ans = 0;
	if(!root) return ans;
	queue<pair<node*,int>> q;
	q.push({root,0});

	while(!q.empty()){
		int ss = q.sz();
		int m = q.front().s;
		int l,r;
		fr(i,0,ss){
			auto cv = q.front();
			q.pop();
			int c = cv.s;
			c-=m;
			if(i==0) l=c;
			if(i==ss-1) r=c;
			if(cv.f->l){q.push({cv.f->l,2*c+1});}
			if(cv.f->r){q.push({cv.f->r,2*c+2});}
		}
		ans = max(ans,r-l+1);
	}
	return ans;
}

void childsum(node* root){
	if(!root) return;
	int c=0;
	if(root->l) c+=root->l->data;
	if(root->r) c+=root->r->data;
	if(root->data <=c) root->data = c;
	else{
		if(root->l) root->l->data = root->data;
		if(root->r) root->r->data = root->data;
	}
	childsum(root->l);
	childsum(root->r);
	int r=0;
	if(root->l) r+=root->l->data;
	if(root->r) r+=root->r->data;
	if(root->l || root->r) root->data=r;
}

node* find(node* root,int k){
	node* ans;
	if(root==null || root->data==k) return root;
	ans = find(root->l,k);
	if(ans==null) ans = find(root->r,k);
	return ans;
}

unordered_map<node*,node*> p;
void findparents(node* root){
	queue<node*> q;
	q.push(root);
	p[root]=null;
	while(!q.empty()){
		auto cv = q.front();
		q.pop();
		if(cv->l){
			p[cv->l]=cv;
			q.push(cv->l);
		}
		if(cv->r){
			p[cv->r]=cv;
			q.push(cv->r);
		}
	}
}

vector<int> nodesatdisk(node* root,node* t,int d){
	queue<node*> q;
	q.push(t);
	int cl=0;
	vis[t->data]=1;
	while(!q.empty()){
		if(cl==d) break;
		int s = q.sz();
		fr(i,0,s){
			auto cv = q.front();
			q.pop();
			if(cv->l && !vis[cv->l->data]){
				q.push(cv->l);
				vis[cv->l->data]=1;
			}
			if(cv->r && !vis[cv->r->data]){
				q.push(cv->r);
				vis[cv->r->data]=1;
			}
			if(p[cv] && !vis[p[cv]->data]){
				q.push(p[cv]);
				vis[p[cv]->data]=1;
			}
		}
		cl++;
	}
	
	vector<int> ans;
	while(q.sz()){
		ans.pb(q.front()->data);
		q.pop();
	}
	return ans;
}

bool checkforcbt(node* root){
	if(!root) return 1;
	int c=0;
	if(root->l) c++;
	if(root->r) c++;
	return ( !(c%2) && checkforcbt(root->l) && checkforcbt(root->r));
}

int left(node* root){
	int ans=0;
	node* t=root;
	while(t) {ans++;t=t->l;}
	return ans;
}

int right(node* root){
	int ans=0;
	while(root) ans++,root=root->r;
	return ans;
}

int nodes(node* root){
	if(!root) return 0;
	int lh = left(root);
	int rh = right(root);
	debug(mp(lh,rh))
	if(lh==rh) return ((1<<lh)-1);
	return 1+nodes(root->l)+nodes(root->r);
}

node* build(vector<int> pre,int ps,int pe,vector<int> in,int ins,int ine,unordered_map<int,int> m){
	if(ps>pe || ins>ine) return null;
	node* root = new node(pre[ps]);
	// node* rooot = new node(post[pe]);
	int le = m[root->data]-ins;
	root->l = build(pre,ps+1,ps+le,in,ins,m[root->data]-1,m);
	root->r = build(pre,ps+le+1,pe,in,m[root->data]+1,ine,m);
	// root->l = build(post,ps,ps+le-1,in,ins,m[root->data]-1,m);
	// root->r = build(post,ps+le,pe-1,in,m[root->data]+1,ine,m);
	return root;

}

node* buildtree(vector<int> in,vector<int> pre){
	unordered_map<int,int> m;
	fr(i,0,in.sz()) m[in[i]]=i;
	node* root = build(pre,0,pre.sz()-1,in,0,in.sz()-1,m);
	return root;
}

void ff(node* root){
	if(!root) return;
	cout<<root->data<<" ";
	ff(root->l);
	ff(root->r);
}

string serialize(node* root){
	string ans;
	if(!root) return ans;
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		auto cv = q.front();
		q.pop();
		if(cv==null){
			ans = ans + "# ";
		}	
		else{
			int d = cv->data;
			string c = to_string(d);
			ans = ans + c + " ";
			q.push(cv->l);
			q.push(cv->r);
		}
	}
	return ans;
}

node* deserialize(string s){
	if(!s.sz()) return null;
	stringstream ss(s);
	string str;
	getline(ss,str,' ');
	node* root = new node(stoi(str));
	queue<node*> q;
	q.push(root);

	while(!q.empty()){
		auto cv = q.front();
		q.pop();
		getline(ss,str,' ');
		if(str=="#") cv->l = null;
		else{
			cv->l = new node(stoi(str));
			q.push(cv->l);
		}
		getline(ss,str,' ');
		if(str=="#") cv->r = null;
		else{
			cv->r = new node(stoi(str));
			q.push(cv->r);
		}
	}
	return root;
}

vector<int> morrisinorder(node* root){
	vector<int> ans;
	if(!root) return ans;
	node* t=root;
	while(t){
		if(!t->l){
			ans.pb(t->data);
			t=t->r;
		}
		else{
			node* c=t->l;
			while(c->r && c->r!=t)
				c=c->r;
			if(c->r==null){
				c->r=t;
				t=t->l;
			}
			else{
				c->r=null;
				ans.pb(t->data);
				t=t->r;
			}
		}
	}
	return ans;
}

vector<int> morrispreorder(node* root){
	vector<int> ans;
	if(!root) return ans;
	node* t=root;
	while(t){
		if(!t->l){
			ans.pb(t->data);
			t=t->r;
		}
		else{
			node* c=t->l;
			while(c->r && c->r!=t)
				c=c->r;
			if(c->r==null){
				c->r=t;
				ans.pb(t->data);
				t=t->l;
			}
			else{
				c->r=null;
				t=t->r;
			}
		}
	}
	return ans;
}

node* pp = null;
void flattenrec(node* root){
	if(!root) return;
	flattenrec(root->r);
	flattenrec(root->l);
	root->r=pp;
	root->l=null;
	pp=root;
}

void flatten(node* root){
	if(!root) return;
	stack<node*> s;
	s.push(root);

	while(!s.empty()){
		auto cv = s.top();
		s.pop();
		if(cv->r) s.push(cv->r);
		if(cv->l) s.push(cv->l);
		if(!s.empty()) cv->r = s.top();
		cv->l = null;
	}
}

void flatten1(node* root){
	node* c=root;
	node* p;
	while(c){
		if(c->l){
			p=c->l;
			while(p->r) p=p->r;
			p->r=c->r;
			c->r=c->l;
			c->l=null;
		}
		c=c->r;
	}
}









void solve()
{	
	// int n,m;cin>>n>>m;
	
	// vector<vector<int>> adjmat(n+1,vector<int>(n+1,0));
	// int adjmat[n+1][n+1];
	// fr(i,0,n+1) fr(j,0,n+1) adjmat[i][j]=0;
	
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjmat[a][b]=adjmat[b][a]=1;
	// 	adjlist[a].pb(b);
	// 	adjlist[b].pb(a);
	// }

	// fr(i,0,n+1){
	// 	fr(j,0,n+1){
	// 		cout<<adjmat[i][j]<<" ";
	// 	}cout<<endl;
	// }

	// cout<<endl;

	// fr(i,0,n+1){
	// 	cout<<i<<" -> ";
	// 	for(auto e:adjlist[i])
	// 		cout<<e<<" ";
	// 	cout<<endl;
	// }

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	edges.pb(mp(a,b));
	// 	adjlist[a].pb(b);
	// 	adjlist[b].pb(a);
	// }

	// DFS -----------------------------------------------------

	// DFS(1);
	// debugv(level,1,n+1)
	// there is no sense of level in the DFS traversal as the
	// ordering of the nodes are irrespective of their levels

	// connected components

	// int ans=0;
	// int ccc=1;
	// fr(i,1,n){
	// 	if(!vis[i]){
	// 		DFS(i,ccc++);
	// 		ans++;
	// 	}
	// }

	// map<int,vector<int>> mm;
	// fr(i,1,n+1){
	// 	mm[vis[i]].pb(i);
	// }

	// debug(ans)
	// debugv(vis,1,n+1)

	// for(auto p:mm){
	// 	for(auto e:p.s){
	// 		cout<<e<<" ";
	// 	}cout<<endl;
	// }

	// cycle detection
	// bool b=DFS1(1,-1);
	// cout<<b<<endl;

	// DFS on a grid

	// int n,m;cin>>n>>m;
	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		cin>>grid[i][j];
	// 	}
	// }
	// int ans=0;
	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		if(!visgrid[i][j] && grid[i][j]){
	// 			DFS2(n,m,i,j);
	// 			ans++;
	// 		}
	// 	}
	// }
	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		cout<<visgrid[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<ans<<endl;

	// height and depth(level) in graph/tree
	
	// tree ;;
	// DFS3(1,-1);

	// debugv(depth,1,n+1);
	// debugv(height,1,n+1);

	// graph

	// DFS4(1); 
	// debugv(depth,1,n+1);
	// debugv(height,1,n+1);

	// subtree sum and total number of even numbers on subtree of every node

	// DFS5(1,-1);
	// debugv(subtreesum,1,n+1);
	// debugv(evens,1,n+1);

	// diameter of the tree

	// DFS6(1,-1);
	// int md = *max_element(depth.begin()+1,depth.begin()+n);
	// int mdi = 0;
	// fr(i,1,n+1){
	// 	if(depth[i]==md) mdi=i;
	// 	depth[i]=0;
	// }
	// DFS6(mdi,-1);
	// int diameter = *max_element(depth.begin()+1,depth.begin()+n);
	// cout<<diameter<<endl;

	// LCA of two nodes in tree
	
	// int a,b;cin>>a>>b;
	// DFS7(1,-1);

	// int da=depth[a],db=depth[b];
	
	// if(da>db){
	// 	while(da>db){
	// 		a=parent[a];
	// 		da--;
	// 	}
	// }else{
	// 	while(db>da){
	// 		b=parent[b];
	// 		db--;
	// 	}
	// }

	// while(a!=b){
	// 	a=parent[a];
	// 	b=parent[b];
	// }
	// cout<<a<<" "<<b<<endl;

	// edge deletion

	// DFS5(1,-1);
	// int ans=int_min;
	// for(auto e:edges){
	// 	ans=max(ans,subtreesum[e.s]*(subtreesum[1]-subtreesum[e.s]));
	// }
	// debugv(subtreesum,1,n+1)
	// for(auto e:edges){
	// 	if(ans==subtreesum[e.s]*(subtreesum[1]-subtreesum[e.s])){
	// 		cout<<"delete the edge between nodes "<<e.f<<" and "<<e.s<<endl;
	// 		break;
	// 	}
	// }
	// cout<<ans<<endl;

	// BFS -----------------------------------------------------

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	adjlist[b].pb(a);
	// }

	// dfs(1);
	// cout<<endl;
	// fr(i,1,n+1) vis[i]=0;
	// bfs(1);
	// debugv(level,1,n+1);

	// zeroonebfs(1);
	// debugv(vis,1,n+1)

	// msbfs

	// int x;cin>>x;
	// vector<int> v(x);
	// fr(i,0,x) cin>>v[i];
	// for(auto e:v) adjlist[0].pb(e);
	// bfs(0);

	// msbfs(v);

	// dijkstra's shortest path algo

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int x,y,z;cin>>x>>y>>z;
	// 	adjlist[x].pb(mp(y,z));
	// }
	// fr(i,1,n+1)
	// 	dijkstra(i,n);

	// all pair shortest path - floyd warshell algorithm

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b,c;cin>>a>>b>>c;
	// 	adjmat[a][b]=c;
	// 	adjmat[a][a]=adjmat[b][b]=0;
	// }

	// bool b=false;
	// floydwarshell(n);
	// int p;
	// fr(k,1,n+1){ 
	// 	fr(i,1,n+1){ 
	// 		fr(j,1,n+1){
	// 			if(adjmat[i][k]!=INT_MAX && adjmat[k][j]!=INT_MAX)
	// 				adjmat[i][j]=min(adjmat[i][j],adjmat[i][k]+adjmat[k][j]);
	// 			if(i==j && adjmat[i][j]<0) {p=i;b=true;}
	// 			if(b) break; 
	// 		}
	// 		if(b) break;
	// 	}
	// 	if(b) break;
	// }

	// if(b) cout<<"negative cycle detected at "<<p<<endl;
	// else{
	// 	fr(i,1,n+1){
	// 		debugv(adjmat[i],1,n+1)
	// 	}
	// }

	// DSU -----------------------------------------------------

	// int n;cin>>n;
	// fr(i,1,n+1) make(i);
	// int q;cin>>q;
	// fr(i,0,q){
	// 	int a,b;cin>>a>>b;
	// 	Union(a,b);
	// 	cout<<size[a]<<" "<<size[b]<<" "<<parent[a]<<" "<<parent[b]<<endl;
	// }
	// // fr(i,1,n+1) cout<<size[i]<<" ";
	// cout<<endl;
	// fr(i,1,n+1) cout<<find(i)<<" "; cout<<endl;

	// MST - minimum spanning tree (kruskal's and prim's algorithm)

	// kruskal's algo --------------------------------------------------------------
	
	// int n,m;cin>>n>>m;
	// vector<pair<int,pair<int,int>>> e;
	// fr(i,0,m){
	// 	int x,y,z;cin>>x>>y>>z;
	// 	e.pb(mp(z,mp(x,y)));
	// }
	// sort(all(e));
	// fr(i,1,n+1) make(i);
	// int ans=0;
	// for(auto p:e){
	// 	int wt=p.f;
	// 	int u=p.s.f;
	// 	int v=p.s.s;
	// 	if(find(u)==find(v)) continue;
	// 	Union(u,v);
	// 	ans+=wt;
	// 	cout<<u<<" "<<v<<" "<<wt<<endl;
	// 	adjlist[u].pb(mp(v,wt));
	// 	adjlist[v].pb(mp(u,wt));
	// }
	// cout<<endl<<endl;
	// cout<<ans<<endl;
	// cout<<endl<<endl;

	// fr(i,1,n+1){
	// 	cout<<i<<" ->";
	// 	for(auto p:adjlist[i]){
	// 		cout<<" {"<<p.f<<","<<p.s<<"}";
	// 	}
	// 	cout<<endl;
	// }

	// prim's algorithm ------------------------------------------------------------

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b,c;cin>>a>>b>>c;
	// 	adjlist[a].pb(mp(b,c));
	// 	adjlist[b].pb(mp(a,c));
	// }

	// fr(i,1,n+1) make(i);

	// priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
	// int r;cin>>r;
	// for(auto c:adjlist[r]){
	// 	pq.push(mp(c.s,mp(c.f,r)));
	// }

	// cout<<pq.top().f<<endl;

	// while(!pq.empty()){
	// 	auto p=pq.top();
	// 	pq.pop();
	// 	int d=p.f;
	// 	int u=p.s.s;
	// 	int v=p.s.f;
	// 	if(find(u)==find(v)) continue;
	// 	Union(u,v);
	// 	for(auto c:adjlist[v]){
	// 		pq.push(mp(c.s,mp(c.f,v)));
	// 	}
	// 	cout<<u<<" "<<v<<" "<<d<<endl; 
	// }

	// topological sort ------------------------------------------------------------

	// using DFS

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b,c;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// }

	// topologicaldfs(1);
	// while(!t.empty()){
	// 	cout<<t.top()<<" ";
	// 	t.pop();
	// }

	// using BFS
	// topologicalbfs(n);

	// Check if given graph is bipartite or not -------------------------------------

	// in bipartite graph the vertices can be divided in 2 
	// distinct sets such that edge will be only between sets

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// }

	// bool b = bipartite_dfs(1,color[1]);
	// cout<<b<<endl;
	// if(b){
	// 	fr(i,1,n+1) if(color[i]) cout<<i<<" ";
	// 	cout<<endl;
	// 	fr(i,1,n+1) if(!color[i]) cout<<i<<" ";
	// }

	// In/Out time for every nodes
	
	// DFS8(1);
	// debugv(in,1,n+1);
	// debugv(out,1,n+1);
	
	// int a,b;cin>>a>>b;
	// if(((in[a]>in[b])&&(out[a]<out[b]))||((in[a]<in[b])&&(out[a]>out[b]))) cout<<1<<endl;
	// else cout<<0<<endl;

	// ***************************************************************************************************************
	//																												 *
	// concept of forward edges and backward edges : 																 *
	// edges which participate in dfs calls are called the forward edges                                             *
	// edges which does not participate in the dfs calls are called the backward edges                               *
    //																											     *
	// removal of all backward edges results into the tree , graph with no loops									 *
	//																												 *
	// backward edges are part of atleat one loop 																	 *
	// every other edges which are not part of the loops are called the bridges of the graph						 *
	// because removal of those edges results in to the disconnected graph or no of connected components increases   *
	// every backedge connects to its ansestor which is not its direct parent 										 *
	//																												 *
	// ***************************************************************************************************************
	// DFS9(1,-1);

	// **find and print cycle in the graph

	// **strongly connected components in directed graph

	// ****************************************************************************************************
	// approach 1 : using map of vectors of same length

	// map<int,vector<vector<int>>> x;
	// fr(i,1,n+1){
	// 	DFS10(i);
	// 	x[tscc.sz()].pb(tscc);
	// 	tscc.clear();
	// 	fr(i,1,n+1) vis[i]=0;
	// }

	// debug(x)
	// cout<<x.sz()<<endl;
	// for(auto p:x){
	// 	vector<vector<int>> vv = p.second;
	// 	for(auto v:vv){
	// 		cout<<v[0]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// fails when there are more than 2 scc with same number of elements
	// can use multimap<int,vector<set<int>>> x;
	// every time inserting the tscc in x, check if multimap[tscc.sz()][0].begin() == tscc.begin() then 
	// add in existing multimap[tscc.sz()] else create new one ...
	// ****************************************************************************************************

	// int n,m;cin>>n>>m;
	// vector<pair<int,int>> ge;
	// vector<int> who(n+1);
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	revadjlist[b].pb(a);
	// 	ge.pb(mp(a,b));
	// }



	// fr(i,1,n+1) if(!vis[i]) DFSorder(i);
	// debug(order)

	// fr(i,1,n+1) vis[i]=0;

	// for(int i=n-1;i>=0;i--){
	// 	if(!vis[order[i]]){
	// 		scc.clear();
	// 		DFSSCC(order[i]);
	// 		cout<<"dfs call from "<<order[i]<<" : ";
	// 		for(auto e:scc){
	// 			cout<<e<<" ";
	// 			who[e]=order[i];
	// 		}
	// 		cout<<endl;
	// 	}
	// }

	// debug(who)

	// kosaraju's algorithm to make the condensed graph only made of the representative nodes of the sccs

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	revadjlist[b].pb(a);
	// }

	// fr(i,1,n+1) if(!vis[i]) DFSorder(i);
	// fr(i,1,n+1) vis[i]=0;
	// debugv(order,0,n)
	// map<int,unordered_set<int>> cond_graph;

	// for(int i=order.sz()-1;i>=0;i--){
	// 	if(!vis[order[i]]){
	// 		scc.clear();
	// 		DFSSCC(order[i]);
	// 		cout<<"dfs call from "<<order[i]<<" : ";
	// 		for(auto e:scc)
	// 			who[e]=order[i],cout<<e<<" ";
	// 		cout<<endl;
	// 	}
	// }	

	// fr(i,1,n+1){
	// 	for(auto c:adjlist[i]){
	// 		if(who[i]!=who[c]){
	// 			if(cond_graph[who[i]].find(who[c])==cond_graph[who[i]].end()){
	// 				cond_graph[who[i]].insert(who[c]);
	// 				cadjlist[who[i]].pb(who[c]);
	// 			}
	// 		}
	// 	}
	// }

	// fr(i,1,n+1){
	// 	if(cadjlist[i].sz()){
	// 		cout<<i<<" -> ";
	// 		for(auto e:cadjlist[i])
	// 			cout<<e<<" ";
	// 		cout<<endl;
	// 	}
	// }

	// binary uplifting for the LCA of two nodes in O(logN)

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	adjlist[b].pb(a);
	// }
	
	// dfs(1,-1);
	// int x = log2(n);
	// // int LCA[n+1][x+1];
	// memset(LCA,-1,sizeof LCA);
	// fr(i,1,n+1){
	// 	LCA[i][0]=parent[i];
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,x+1){
	// 		if(LCA[i][j-1]!=-1)
	// 			LCA[i][j]=LCA[LCA[i][j-1]][j-1];
	// 	}
	// }

	// int a,b;cin>>a>>b;

	// cout<<binupliftLCA(a,b,n)<<endl;

	// **find total number of paths from a to b in the graph

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	adjlist[b].pb(a);
	// }

	// int s,d;cin>>s>>d;
	// int ans=0;
	// fr(i,1,n+1){
	// 	if(i==s){
	// 		vis[s]=1;
	// 		dfs(i,d,ans);
	// 	}
	// }

	// cout<<ans<<endl;

	// **total number of loops in the graph
	
	// find all backward edges using the dfs = O((v+e)logv)
	// for all backward edges find its lca <= v*v*log(v)
	// for u and v of backward edge with lca w , find no of paths from u to w and v to w = O((v+e)logv)
	// if x backward edges : total time O(x*(v+e)*logv)

	// x<=(v-1)*(v-2)/2<=v*v
	// e<=v*v

	// total time to count all loops : O(v*v*v*v*logv) = O(v^4 * logv)

	node* root = new node(1);
	root->l = new node(2);
	root->r = new node(5);
	root->l->l = new node(3);
	root->l->r = new node(4);
	root->r->l = new node(6);
	root->r->r = new node(7);
	root->l->l->l = new node(8);
	root->l->l->r = new node(9);
	root->l->r->l = new node(12);
	root->l->r->r = new node(13);
	root->r->l->l = new node(14);
	root->r->l->r = new node(15);
	root->r->r->l = new node(10);
	root->r->r->r = new node(11);

	// node* root = new node(1);
	// root->l = new node(2);
	

	// preorder(root);cout<<endl;
	// inorder(root);cout<<endl;
	// postorder(root);cout<<endl<<endl;

	// it_pre(root);cout<<endl; // easy
	// it_in(root);cout<<endl; // medium
	// it_post2(root);cout<<endl<<endl; // easy 
	
	// all_three(root);cout<<endl; // medium

	// depth(root) = 1 = level(root)
	// depth(n) = depth(parent(n)) + 1;

	// level = depth

	// height(root) = max(height(all))
	// height(n) = max(height(child(n))) + 1

	// dfsonbt(root);
	// cout<<height[root->data]<<" "<<depth[root->data]<<endl;

	// if(isBalanced(root))cout<<1<<endl;
	// else cout<<0<<endl;

	// cout<<_height()<<endl;

	// _depth(root);
	// fr(i,1,8){
	// 	cout<<depth[i]<<endl;
	// }

	// cout<<endl<<endl;
	// cout<<_height(root)<<endl;
	// cout<<endl<<endl;

	// fr(i,1,8){
	// 	cout<<height[i]<<endl;
	// }

	// diameter of a tree
	// cout<<diameter(root)<<endl;
	// cout<<ans<<endl;

	// max path sum
	// cout<<maxpathsum(root)<<endl;
	// cout<<ans<<endl;

	// zig zag traversal
	// vector<int> ans = zigzagtraversal(root);
	// debug(ans);

	// boundry traversal(anti clockwise)
	// ans = root + all left nodes + leaves + reverse all right nodes
	// vector<int> ans = boundrytraversal(root);
	// debug(ans);

	// vertical order traversal
	// vector<int> ans = vreticalorder(root);
	// for(auto e:ans){
	// 	cout<<e<<" ";
	// }

	// top/bottom view
	// vector<int> ans = topview(root);
	// for(auto e:ans) cout<<e<<" ";
	// cout<<endl;
	// vector<int> ans1 = bottomview(root);
	// for(auto e:ans1) cout<<e<<" ";

	// right/left view
	// vector<int> ans = leftview(root);
	// debug(ans);
	// vector<int> ans1 = rightview(root);
	// debug(ans1);

	// node to root path
	// int x;cin>>x;
	// bool b = path(root,x);
	// if(b) debug(anspath);

	// LCA
	// node* lca = LCA(root,6,13);
	// cout<<lca->data<<" ";

	// max width of the bt
	// int mw = width(root);
	// cout<<mw<<endl;

	// childsum property
	// inorder(root);cout<<endl;
	// childsum(root);
	// inorder(root);

	// find all nodes at distance d from target node k
	// int k,d;cin>>k>>d;
	// node* t = find(root,k);
	// findparents(root);
	// vector<int> ans = nodesatdisk(root,t,d);
	// for(auto e:ans)
	// 	cout<<e<<" ";

	// min time to burn the tree from target node
	// same as above , count the level

	// total no of nodes in cbt
	// cout<<checkforcbt(root);
	// cout<<nodes(root)<<endl;

	// requirements to construct the unique binary tree from 
	// 1. inorder + preorder traversals
	// 2. inorder + postorder traversals

	// 1.
	// int n;cin>>n;
	// vector<int> inorder(n),preorder(n);
	// fr(i,0,n) cin>>inorder[i];
	// fr(i,0,n) cin>>preorder[i];

	// node* root1 = buildtree(inorder,preorder);
	// ff(root1);

	// serialize
	// inorder(root);
	// cout<<endl;
	// // string ans = serialize(root);
	// // cout<<ans<<endl;

	// // deserialize
	// // string s;cin>>s;
	// // node* r = deserialize(ans);
	// // inorder(r);
	// inorder(deserialize(serialize(root)));

	// morris traversal
	// inorder(root);cout<<endl;
	// vector<int> mi = morrisinorder(root);
	// // add when breaking the thread
	// for(auto e:mi) cout<<e<<" ";
	// cout<<endl;
	// preorder(root);cout<<endl;
	// vector<int> mp = morrispreorder(root);
	// // add when making the thread
	// for(auto e:mp) cout<<e<<" ";
	// cout<<endl;

	// flatten the binary tree - recurssive
	// preorder(root);cout<<endl;
	// flattenrec(root);
	// preorder(root);

	// iterative using stack
	// preorder(root);cout<<endl;
	// flatten(root);
	// preorder(root);

	// iterative in O(1) space
	preorder(root);cout<<endl;
	flatten1(root);
	preorder(root);

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