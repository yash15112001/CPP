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

const int N = 1e4+5;
vector<int> adjlist[N],revadjlist[N];
int adjmat[N][N];
vector<int> h(N,0),dis(N,-1e8),level(N,int_max),vis(N,0),dfsvis(N,0);

// void dfs(int v){
// 	vis[v]=1;
// 	cout<<v<<endl;
// 	for(auto c:adjlist[v]){
// 		if(vis[c]) continue;
// 		d[c]=d[v]+1;
// 		dfs(c);
// 		h[v]=max(h[v],1+h[c]);
// 	}
// }

// bool cycle(int v,int p){
// 	vis[v]=1;
// 	bool b=false;
// 	for(auto c:adjlist[v]){
// 		if(vis[c] && c==p) continue;
// 		if(vis[c]) return true;
// 		b|=cycle(c,v);
// 		if(b) return true;
// 	}
// 	return false;
// }

// bool cycle2(int v,int p){
// 	vis[v]=1;
// 	bool b=false;
// 	dfsvis[v]=1;
// 	for(auto c:adjlist[v]){
// 		if(!vis[c]){
// 			if(cycle2(c,v)) return true;
// 		}
// 		else{
// 			if(dfsvis[c]) return true;
// 		}
// 	}
// 	dfsvis[v]=0;
// 	return false;
// }

// void bfs(int v){
// 	queue<int> q;
// 	q.push(v);
// 	vis[v]=1;
// 	level[v]=0;

// 	while(q.size()){
// 		auto cv = q.front();
// 		q.pop();
// 		cout<<cv<<" ";
// 		for(auto c:adjlist[cv]){
// 			if(level[cv]+1<level[c]){
// 				level[c]=1+level[cv];
// 				vis[c]=1;
// 				q.push(c);
// 			}
// 		}
// 	}

// 	cout<<endl;
// 	debugv(level,1,7);
// }

// void zeroonebfs(int v){
// 	deque<int> q;
// 	q.pb(v);
// 	level[v]=0;
// 	vis[v]=1;

// 	while(q.size()){
// 		auto cv = q.front();
// 		q.ppf();
// 		cout<<cv<<" ";
// 		for(auto [c,wt]:adjlist[cv]){
// 			if(level[cv]+wt<level[c]){
// 				level[c]=level[cv]+wt;
// 				if(wt) q.pb(c);
// 				else q.pf(c);
// 			}
// 		}
// 	}
// }

// void msbfs(vector<int>& v){
// 	queue<int> q;
// 	for(auto e:v) {q.push(e);level[e]=0;vis[e]=1}

// 	while(q.size()){
// 		auto cv = q.front();
// 		q.pop();
// 		cout<<cv<<" ";
// 		for(auto c:adjlist[cv]){
// 			if(level[cv]+1<level[c]){
// 				level[c]=1+level[cv];
// 				vis[cv]=1;
// 				q.push(c);
// 			}
// 		}
// 	}
// }

// void dijkstra(int v){
// 	vector<int> dist(N,int_max);
// 	set<pair<int,int>> s;
// 	s.insert(mp(0,v));
// 	dist[v]=0;

// 	while(s.sz()){
// 		auto x = *s.begin();
// 		int d = x.f;
// 		int cv = x.s;
// 		s.erase(s.begin());
// 		if(vis[cv]) continue;
// 		vis[cv]=1;
// 		for(auto c:adjlist[cv]){
// 			int ccv = c.f;
// 			int wt = c.s;
// 			if(dist[cv]+wt<dist[ccv]){
// 				dist[ccv]=dist[cv]+wt;
// 				// q.push(ccv);
// 				s.insert(mp(dist[ccv],ccv));
// 			}
// 		}
// 	}
// 	fr(i,1,7) cout<<dist[i]<<" ";
// }

// vector<int> parent(N),size(N);

// void make(int i){
// 	parent[i]=i;
// 	size[i]=1;
// }

// int find(int i){
// 	if(i==parent[i]) return i;
// 	return parent[i]=find(parent[i]);
// }

// void Union(int i,int j){
// 	i=find(i);
// 	j=find(j);
// 	if(i!=j){
// 		if(size[i]>size[j]) swap(i,j);
// 		parent[i]=j;
// 		size[j]+=size[i];
// 	}
// }
// stack<int> st;
// void dfs(int v){
// 	vis[v]=1;
// 	for(auto c:adjlist[v]){
// 		if(vis[c]) continue;
// 		dfs(c);
// 	}
// 	st.push(v);
// }

// vector<int> order,scc;
// void dfs(int v){
// 	vis[v]=1;
// 	for(auto c:adjlist[v]){
// 		if(vis[c]) continue;
// 		dfs(c);
// 	}
// 	// cout<<v<<" ";
// 	order.pb(v);
// }

// void dfs2(int v){
// 	vis[v]=1;
// 	for(auto c:revadjlist[v]){
// 		if(vis[c]) continue;
// 		dfs2(c);
// 	}
// 	scc.pb(v);
// }

// *************************************************

// bool dfs(int v,int cc){
// 	vis[v]=1;
// 	color[v]=cc;
// 	for(auto c:adjlist[v]){
// 		if(!vis[c]){
// 			if(!dfs(c,cc^1)) return false;
// 			// else return false;
// 		}else if(color[c]==color[v]) return false;
// 	}
// 	return true;
// }
// *************************************************

// vector<int> color(N);
// bool check(int node,int cc){
// 	for(auto c:adjlist[node]){
// 		if(color[c]==cc) return 0;
// 	}
// 	return 1;
// }

// bool mcoloring(int tn,int tc,int node){
// 	if(node==tn+1) return 1;
// 	fr(i,1,tc+1){
// 		if(check(node,i)){
// 			color[node]=i;
// 			if(mcoloring(tn,tc,node+1)) return 1;
// 			color[node]=0;
// 		}
// 	}
// 	return 0;
// }

// vector<int> color(N);

// bool is_Safe(int v,int c){
// 	for(auto c_node:adjlist[v]){
// 		if(color[c_node]==c) return false;
// 	}
// 	return true;
// }

// bool coloring(int node,int total_colors,int total_nodes){
// 	if(node==total_nodes+1) return true;
// 	for(int c=1;c<=total_colors;c++){
// 		if(is_Safe(node,c)){
// 			color[node]=c;
// 			if(coloring(node+1,total_colors,total_nodes)) return true;
// 			color[node]=0;
// 		}
// 	}
// 	return false;
// }

// vector<int> in(N),low(N);
// int t=0;
// void dfs(int v,int p){
// 	vis[v]=1;low[v]=in[v]=t++;
// 	for(auto c:adjlist[v]){
// 		if(c==p) continue;
// 		if(vis[c]){
// 			// backedge
// 			low[v] = min(low[v],in[c]);
// 		}else{
// 			// may be bridge
// 			dfs(c,v);
// 			if(in[v]<low[c]) cout<<c<<" "<<v<<endl;
// 			low[v] = min(low[v],low[c]);
// 		}
// 	}
// }

// int LCA[N][50];

// void dfs(int v,int p){
// 	vis[v]=1;
// 	LCA[v][0]=p;
// 	for(auto c:adjlist[v]){
// 		if(c==p) continue;
// 		level[c]=level[v]+1;
// 		dfs(c,v);
// 	}
// }

// int lca(int u,int v,int n){
// 	if(level[u]<level[v]) swap(u,v);
// 	int d = level[u]-level[v];
// 	while(d){
// 		int i = log(d);
// 		u=LCA[u][i];
// 		d-=(1<<i);
// 	}
// 	if(u==v) return u;
// 	for(int i=log2(n)+1;i>=0;i--){
// 		if(LCA[u][i]!=-1 && LCA[v][i]!=-1 && LCA[u][i]!=LCA[v][i]){
// 			u=LCA[u][i];
// 			v=LCA[v][i];
// 		}
// 	}
// 	return LCA[u][0];
// }

// int gcd(int a,int b){
// 	if(b==0) return a;
// 	return gcd(b,a%b);
// }

// void print(queue<pair<int,pair<int,int>>> q){
// 	while(q.sz()){
// 		auto p  = q.front();
// 		q.pop();
// 		cout<<"{"<<p.f<<","<<p.s.f<<","<<p.s.s<<"}";
// 	}
// }

// int f(int fromcap,int tocap,int d){
// 	int ans=0;
// 	int from = fromcap;
// 	ans++;
// 	int to=0;

// 	while(from!=d && to!=d){
// 		int t = min(from,tocap-to);
// 		to+=t;
// 		from-=t;
// 		ans++;
// 		if(to==d||from==d)break;
// 		if(from==0){
// 			ans++;
// 			from=fromcap;
// 		}else if(to==tocap){
// 			ans++;
// 			to=0;
// 		}
// 	}

// 	return ans;
// }

// pair<int,int> f2(int t,int n,vector<vector<int>>& b){
// 	int x = n-1-((t-1)/n);
// 	int y = abs(t-b[x][0]);
// 	return mp(x,y);
// }

// int f(vector<vector<int>>& b){
// 	// vector<int> v;
// 	// bool p=0;
// 	// int n = b.size();
// 	// if(n%2) p=0;
// 	// else p=1;
// 	// fr(i,0,n){
// 	// 	vector<int> to_add = b[i];
// 	// 	if(p){
// 	// 		for(int i=n-1;i>=0;i--) v.pb(to_add[i]);
// 	// 	}else{
// 	// 		for(int i=0;i<n;i++) v.pb(to_add[i]);
// 	// 	}
// 	// }

// 	// v.pb(0);
// 	// reverse(all(v));
// 	// debug(v)
// 	// vector<int> vis(v.sz(),0);
// 	// vis[1]=1;
// 	// int ans=0;

// 	queue<int> q;
// 	// // bool bb = false;
// 	// q.push(1);
// 	// while(q.sz()){
// 	// 	int t = q.sz();
// 	// 	fr(i,0,t){
// 	// 		int cv = q.front();
// 	// 		q.pop();
// 	// 		if(cv==n*n){
// 	// 			return ans;
// 	// 		}
// 	// 		fr(j,1,7){
// 	// 			if(cv+j>n*n) break;
// 	// 			if(vis[cv+j]) continue;
// 	// 			vis[cv+j]=1;
// 	// 			if(v[cv+j]==-1)
// 	// 				q.push(cv+j);
// 	// 			else
// 	// 				q.push(v[cv+j]);
// 	// 		}
// 	// 	}
// 	// 	ans++;
// 	// }
// 	// return -1;
	
// 	int n = b.sz();
// 	vector<vector<int>> vis(n,vector<int>(n,0));
// 	vis[n-1][0]=1;
// 	q.push(1);
// 	int ans=0;
// 	while(q.sz()){
// 		int t = q.sz();
// 		fr(i,0,t){
// 			int cv =q.front();
// 			q.pop();
// 			if(cv==n*n){
// 				return ans;
// 			}
// 			for(int j=1;j<=6 && cv+j<=n*n;j++){
// 				pair<int,int> p = f2(cv+j,n,b);
// 				if(vis[p.f][p.s]) continue;
// 				vis[p.f][p.s]=1;
// 				b[p.f][p.s]==-1?q.push(cv+j):q.push(b[p.f][p.s]);
// 			}
// 		}
// 		ans++;
// 	}
// 	return -1;
// }

// void dfs(int v,vector<int>& x){
// 	vis[v]=1;
// 	for(auto c:adjlist[v]){
// 		if(!vis[c]) dfs(c,x);
// 	}
// 	x.pb(v);
// }

// int n,ans,k;

// void find_ways(vector<int>& color){
// 	int u=1;
// 	for(;u<=n;u++){
// 		if(color[u]==-1)
// 			break;
// 	}

// 	if(u==n+1){
// 		ans++;
// 		return;
// 	}

// 	vector<bool> available(k,true);

// 	for(auto c:adjlist[u])
// 		if(color[c]!=-1) available[color[c]]=false;

// 	fr(i,0,k){
// 		if(available[i]){
// 			color[u]=i;
// 			find_ways(color);
// 			color[u]=-1;
// 		}
// 	}
// }

// int mincoloring(int n){
// 	vector<int> indegree(N,0);
// 	vector<int> color(N,1);
// 	queue<int> q;
// 	fr(i,1,n+1){
// 		for(auto c:adjlist[i])
// 			++indegree[c];
// 	}
// 	fr(i,1,n+1)
// 		if(indegree[i]==0) q.push(i);
// 	int ans=0;
// 	while(q.sz()){
// 		auto cv = q.front();
// 		q.pop();
// 		for(auto c:adjlist[cv]){
// 			--indegree[c];
// 			if(indegree[c]==0)
// 				q.push(c);
// 			if(color[c]<=color[cv]){
// 				color[c] = 1+color[cv];
// 				ans = max(ans,color[c]);
// 			}
// 		}
// 	}
// 	return ans;
// }

void solve()
{	
	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	adjlist[b].pb(a);
	// }
	// dfs(1);
	// debugv(h,1,n+1);
	// debugv(d,1,n+1);

	// cout<<cycle2(1,0);

	// bfs(1);
	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b,c;cin>>a>>b>>c;
	// 	adjlist[a].pb({b,c});
	// 	// adjlist[b].pb({a,c});
	// }
	// dijkstra(2);

	// int n,m;cin>>n>>m;
	// fr(i,0,n+1) fr(j,0,n+1) adjmat[i][j]=int_max;
	// fr(i,0,m){
	// 	int a,b,c;cin>>a>>b>>c;
	// 	adjmat[a][b]=c;
	// 	adjmat[a][a]=adjmat[b][b]=0;
	// }

	// bool b=false;
	// fr(k,1,n+1){
	// 	fr(i,1,n+1){
	// 		fr(j,1,n+1){
	// 			if(adjmat[i][k]!=int_max && adjmat[k][j]!=int_max)
	// 				adjmat[i][j]=min(adjmat[i][j],adjmat[i][k]+adjmat[k][j]);
	// 			if(i==j && adjmat[i][j]<0){
	// 				b=true;
	// 				break;
	// 			}
	// 		}
	// 	}
	// }

	// if(b) cout<<"cycle exist in graph";
	// else{
	// 	fr(i,1,n+1){
	// 		fr(j,1,n+1){
	// 			if(adjmat[i][j]==int_max)
	// 				cout<<"I ";
	// 			else cout<<adjmat[i][j]<<" ";
	// 		}
	// 		cout<<endl;
	// 	}
	// }

	// class node{
	// public: 
	// 	int u,v,wt;
	// 	node(int x,int y,int z){
	// 		u=x;
	// 		v=y;
	// 		wt=z;
	// 	}
	// };
	// int n,m;cin>>n>>m;
	// vector<node> e;
	// fr(i,0,m){
	// 	int a,b,c;cin>>a>>b>>c;
	// 	e.pb(node(a,b,c));
	// }

	// vector<int> d(n+1,int_max);
	// d[1]=0;
	// fr(i,0,n-1){
	// 	for(auto ee:e){
	// 		if(d[ee.u]+ee.wt<d[ee.v]){
	// 			d[ee.v]=d[ee.u]+ee.wt;
	// 		}
	// 	}
	// }
	// bool b=false;
	// for(auto ee:e){
	// 	if(d[ee.u]+ee.wt<d[ee.v]){
	// 		b=true;
	// 		break;
	// 	}
	// }
	// if(b) cout<<"cycle"<<endl;
	// else{
	// 	fr(i,1,n+1) cout<<d[i]<<" ";
	// }

	// fr(i,0,10) make(i);
	// fr(i,0,10) cout<<parent[i]<<" ";
	// cout<<endl;
	// fr(i,0,10) cout<<size[i]<<" ";

	// int n,m;cin>>n>>m;
	// set<pair<int,pair<int,int>>> s;
	// fr(i,0,m){
	// 	int a,b,c;cin>>a>>b>>c;
	// 	s.insert({c,{a,b}});
	// }
	// fr(i,1,n+1) make(i);
	// // debug(s);
	// // for(auto p:s){
	// // 	cout<<p.f<<" "<<p.s.f<<" "<<p.s.s<<endl;
	// // }
	// int ans=0;
	
	// while(s.sz()){
	// 	auto cv = *s.begin();
	// 	s.erase(s.begin());
	// 	int wt = cv.f;
	// 	int u = cv.s.f;
	// 	int v = cv.s.s;
	// 	if(find(u)==find(v)) continue;
	// 	Union(u,v);
	// 	ans+=wt;
	// 	debug(mp(mp(u,v),wt));
	// 	adjlist[u].pb({v,wt});
	// 	adjlist[v].pb({u,wt});
	// }

	// cout<<ans<<endl;

	// set<pair<int,pair<int,int>>> s;
	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b,c;cin>>a>>b>>c;
	// 	adjlist[a].pb({b,c});
	// 	adjlist[b].pb({a,c});
	// }
	// fr(i,1,n+1) make(i);
	// int r;cin>>r;
	// for(auto c:adjlist[r]){
	// 	s.insert({c.s,{r,c.f}});
	// }
	// int ans=0;
	// while(s.sz()){
	// 	auto cv = *s.begin();
	// 	s.erase(s.begin());
	// 	int wt = cv.f;
	// 	int u = cv.s.f;
	// 	int v = cv.s.s;
	// 	if(find(u)==find(v)) continue;
	// 	Union(u,v);
	// 	cout<<u<<" "<<v<<" "<<wt<<endl;
	// 	ans+=wt;
	// 	for(auto c:adjlist[v]){
	// 		s.insert({c.s,{v,c.f}});
	// 	}
	// }
	// cout<<ans<<endl;

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// }
	// dfs(1);
	// while(st.sz()){
	// 	cout<<st.top()<<" ";
	// 	st.pop();
	// }

	// int n,m;cin>>n>>m;
	// vector<int> indegree(n+1,0);
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	indegree[b]++;
	// }

	// queue<int> q;
	// fr(i,1,n+1) if(indegree[i]==0) q.push(i);

	// while(q.size()){
	// 	auto cv = q.front();
	// 	q.pop();
	// 	cout<<cv<<" ";
	// 	for(auto c:adjlist[cv]){
	// 		--indegree[c];
	// 		if(indegree[c]==0) q.push(c);
	// 	}
	// }

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	revadjlist[b].pb(a);
	// }
	// dfs(1);
	// debug(order)
	// fr(i,1,n+1) vis[i]=0;
	// debugv(vis,1,n+1)
	// rf(i,n-1,-1){
	// 	if(!vis[order[i]]){
	// 		scc.clear();
	// 		dfs2(order[i]);
	// 		for(auto e:scc)
	// 			cout<<e<<" ";
	// 		cout<<endl;
	// 	}
	// }

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	adjlist[b].pb(a);
	// }

	// cout<<dfs(1,1)<<endl;
	// debugv(color,1,n+1)

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	adjlist[b].pb(a);
	// }
	// int k;cin>>k;
	// // coloring(int node,int total_color,int total_node)
	// bool ans = coloring(1,k,n);
	// debugv(color,1,n+1)
	// cout<<ans<<endl;

	// ** bridges
	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	adjlist[b].pb(a);
	// }
	// dfs(1,0);

	// int n;cin>>n;
	// fr(i,0,n-1){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	adjlist[b].pb(a);
	// }
	// memset(LCA,-1,sizeof LCA);
	// level[1]=0;
	// dfs(1,0);
	// fr(i,1,n+1){
	// 	fr(j,1,log2(n)+1){
	// 		if(LCA[i][j-1]!=-1)
	// 			LCA[i][j]=LCA[LCA[i][j-1]][j-1];
	// 	}
	// }

	// int q;cin>>q;
	// while(q--){
	// 	int a,b;cin>>a>>b;
	// 	cout<<lca(a,b,n)<<endl;
	// }

	// int m,n;cin>>m>>n;
	// vector<vector<int>> box(m,vector<int>(n));
	// fr(i,0,m){
	// 	fr(j,0,n){
	// 		cin>>box[i][j];
	// 	}
	// }

	// queue<pair<int,pair<int,int>>> q;
	// // unordered_set<pair<int,pair<int,int>>> s;

	// fr(i,0,n){
	// 	q.push({i,{0,i}});
	// }
	// // cout<<q.front().f<<" "<<endl;
	// // print(q);

	// vector<int> ans(n,-1);
	// while(q.size()){
	// 	// print(q);
	// 	auto cv = q.front();
	// 	q.pop();
	// 	int b = cv.f;
	// 	int x = cv.s.f;
	// 	int y = cv.s.s;
	// 	if(x==m){
	// 		ans[b]=y;
	// 		continue;	
	// 	}
	// 	if(box[x][y]==1 && y+1<n && box[x][y+1]==1){
	// 		q.push({b,{x+1,y+1}});
	// 	}else if(box[x][y]==-1 && y-1>=0 && box[x][y-1]==-1){
	// 		q.push({b,{x+1,y-1}});
	// 	}
	// 	// cout<<endl;
	// }

	// // cout<<"fdsfsdf"<<endl;
	// for(auto e:ans) cout<<e<<" ";

	// word ladder

	// string begin,end;cin>>begin>>end;
	// debug(mp(begin,end))
	// int n;cin>>n;
	// vector<string> v(n);
	// fr(i,0,n) cin>>v[i];
	// unordered_set<string> s(all(v));

	// queue<string> q;
	// q.push(begin);
	// int ans=1;
	// bool b=true;
	// while(q.sz() && b){
	// 	int n=q.sz();
	// 	fr(i,0,n){
	// 		auto cv = q.front();
	// 		q.pop();
	// 		if(cv==end){
	// 			b = false;
	// 			break;
	// 		}
	// 		s.erase(cv);
	// 		fr(j,0,cv.sz()){
	// 			char x = cv[j];
	// 			for(char i='a';i<='z';i++){
	// 				cv[j]=i;
	// 				if(s.find(cv)!=s.end())
	// 					q.push(cv);
	// 			}
	// 			cv[j] = x;
	// 		}
	// 	}
	// 	if(!b) break;
	// 	ans++;
	// 	debug(q)
	// }

	// cout<<ans<<endl;

	// int n,m,d;cin>>n>>m>>d;
	// if(n<m) swap(n,m);
	// if(d%gcd(n,m)) cout<<-1<<endl;
	// else{
	// 	cout<<min(f(n,m,d),f(m,n,d));
	// }

	// int n;cin>>n;
	// vector<vector<int>> b(n,vector<int>(n));

	// fr(i,0,n){
	// 	fr(j,0,n) cin>>b[i][j];
	// }

	// vector<int> v;
	// bool p=0;
	// if(n%2) p=0;
	// else p=1;
	// fr(i,0,n){
	// 	vector<int> to_add = b[i];
	// 	if(p){
	// 		for(int i=n-1;i>=0;i--) v.pb(to_add[i]);
	// 	}else{
	// 		for(int i=0;i<n;i++) v.pb(to_add[i]);
	// 	}
	// }

	// v.pb(0);
	// reverse(all(v));
	
	// queue<int> q;
	// fr(i,2,8){
	// 	if(v[i]==-1) q.push(i);
	// 	else q.push(v[i]);
	// }
	// vector<int> vis(n*n+1,0);
	// int target = n*n;
	// int ans=1;
	// bool bb = true;
	// unordered_set<int> s;
	// while(q.sz() && bb){
	// 	// vector<int> vv;
	// 	// while(q.sz()){
	// 	// 	vv.pb(q.front());
	// 	// 	q.pop();
	// 	// }
	// 	int t = q.sz();
	// 	fr(i,0,t){
	// 		auto cv = q.front();
	// 		q.pop();
	// 		if(cv==target){
	// 			bb=false;
	// 			// break;
	// 		}
	// 		fr(i,1,7){
	// 			int newnode = cv+i;
	// 			if(v[cv+i]==-1 && cv+i<=target && !vis[cv+i]){
	// 				if(s.find(cv+i)==s.end())
	// 					q.push(cv+i);
	// 			}else{
	// 				if(s.find(v[cv+i])==s.end() && v[cv+i]<=target && !vis[v[cv+i]])
	// 					q.push(v[cv+i]);
	// 			}
	// 		}
	// 	}
	// 	if(!bb) break;
	// 	ans++;
	// 	s.clear();
	// 	debug(q);
	// }
	// cout<<ans<<endl;

	// int n;cin>>n;
	// vector<vector<int>> b(n,vector<int>(n));
	// fr(i,0,n) fr(j,0,n) cin>>b[i][j];
	// int ans = f(b);
	// cout<<ans<<endl;

	// int n,m;cin>>n>>m;
	// vector<int> in(n+1,0);
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	++in[b];
	// }

	// // dfs(1);
	// // reverse(all(tsort));
	// // for(auto e:tsort) cout<<e<<" ";

	// queue<int> q;
	// fr(i,1,n+1) if(in[i]==0) q.push(i);
	// while(q.sz()){
	// 	auto cv = q.front();
	// 	q.pop();
	// 	cout<<cv<<" ";
	// 	for(auto c:adjlist[cv]){
	// 		--in[c];
	// 		if(in[c]==0)
	// 			q.push(c);
	// 	}
	// }

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// }

	// vector<int> toposort;
	// dfs(1,toposort);

	// reverse(all(toposort));
	// debug(toposort)

	// vector<int> distance(n+1,int_min);

	// int src;cin>>src;
	// distance[src]=0;

	// for(auto e:toposort){
	// 	if(distance[e]==int_min) continue;
	// 	for(auto c:adjlist[e]){
	// 		int u=e;
	// 		int v=c;
	// 		if(distance[u]+1>distance[v])
	// 			distance[v]=distance[u]+1;
	// 	}
	// }
	// debugv(distance,1,n+1)
	// fr(i,1,n+1){
	// 	if(distance[i]==int_min) cout<<"I ";
	// 	else cout<<distance[i]<<" "; 
	// }
	// cout<<endl;
	// cout<<*max_element(all(distance));

	// ***********************************************************************************************************************************
	// 1) mcoloring -> check if its possible to color the graph using m colors 															 *
	// 2) mcoloring -> total no of ways to color the graph so that it stisfies the m coloring property 									 *
	// 3) mcoloring -> find min no of colors such that the grpah can be colored using these colors and satisfy the m coloring property   *
	// ***********************************************************************************************************************************

	// 2)
	// int m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	adjlist[b].pb(a);
	// }

	// cin>>k;
	// debug(k)
	// ans=0;
	// vector<int> color(n+1,-1);

	// find_ways(color);

	// cout<<ans<<endl;

	// 3) 
	
	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// }
	// int ans = mincoloring(n);
	// cout<<ans<<endl;

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