#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,n) for(auto i=a;i<n;i++)
#define rf(i,n,a) for(auto i=n;i>a;i--)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
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

template<class T>void _print(vector<T> v1,int a,int b){ cerr<<"[ "; for(int i=a;i<b;i++) { _print(v1[i]); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(stack<T> st){ cerr<<"[ "; while(!st.empty()) { _print(st.top()); cerr<<" "; st.pop();} cerr<<"]"; }
template<class T>void _print(vector<T> v1){ cerr<<"[ "; for(T i:v1) { _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(set<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(unordered_set<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(multiset<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T,class V>void _print(pair<T,V> p){ cerr<<"{";_print(p.f);cerr<<",";_print(p.s);cerr<<"}"; }
template<class T,class V>void _print(map<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }
template<class T,class V>void _print(unordered_map<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }
template<class T,class V>void _print(multimap<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }

const int N = 1e4+353;
// int grid[N][N];
// int vis[N][N];
// int level[N][N];
// vector<pair<int,int>> adjlist[N];
// vector<int> ss(N),even(N);
// vector<int> vis(N),level(N,1e9);
// vector<int> h(N),d(N),par(N);

// void DFS(int v){
// 	vis[v] = 1;
// 	// cout<<v<<" ";
// 	for(auto c:adjlist[v]){
// 		if(vis[c]) continue;
// 		DFS(c); 
// 	}
// }

// bool DFS(int v,int p){
// 	vis[v] = 1;
// 	bool l = false;
// 	for(auto c:adjlist[v]){
// 		if(vis[c] && c==p) continue;
// 		if(vis[c]) return true;
// 		l |= DFS(c,v);
// 	}
// 	return l;
// }

// void DFS(int v,int p){
// 	par[v] = p;
// 	for(auto c:adjlist[v]){
// 		if(c==p) continue;
// 		d[c] = d[v] +1;
// 		DFS(c,v);
// 		h[v] = max(h[v],h[c]+1);
// 	}
// }

// void DFS(int sr,int sc,int n,int m){

// 	if(sr<0 || sc<0) return;
// 	if(sr>=n || sc>=m) return;
// 	if(vis[sr][sc]) return;

// 	vis[sr][sc] = 1;
// 	if(grid[sr][sc]==0) return;

// 	DFS(sr+1,sc,n,m);
// 	DFS(sr,sc+1,n,m);
// 	DFS(sr-1,sc,n,m);
// 	DFS(sr,sc-1,n,m);
 
// }

// void DFS(int v,int p){
// 	ss[v]+=v;
// 	even[v]+=(v%2==0?1:0);
// 	for(auto c:adjlist[v]){
// 		if(c==p) continue;
// 		DFS(c,v);
// 		ss[v]+=ss[c];
// 		even[v]+=even[c];
// 	}
// }

// void BFS(int v){
// 	queue<int> q;
// 	q.push(v);
// 	vis[v]=1;
// 	level[v]=1;
// 	while(!q.empty()){
// 		auto cv = q.front();
// 		q.pop();
// 		cout<<cv<<" ";
// 		for(auto c:adjlist[cv]){
// 			// if(!vis[c]){
// 			// 	q.push(c);
// 			// 	vis[c]=1;
// 			// 	level[c]=1+level[cv];
// 			// }
// 			if(level[cv]+1 < level[c]){
// 				level[c] = 1+level[cv];
// 				vis[c] = 1;
// 				q.push(c);
// 			}
// 		}
// 	}
// }

// void zerooneBFS(int v){
// 	deque<int> dq;
// 	dq.pb(v);
// 	vis[v] = 1;
// 	level[v] = 1;

// 	while(!dq.empty()){
// 		auto cv = dq.front();
// 		dq.ppf();
// 		cout<<cv<<" ";
// 		for(auto c:adjlist[cv]){
// 			int c_cv = c.f;
// 			int wt = c.s;
// 			if(level[cv]+wt < level[c_cv]){
// 				level[c_cv] = level[cv] + wt;
// 				vis[c_cv] = 1;
// 				if(wt) dq.pb(c_cv);
// 				else dq.pf(c_cv);
// 			}
// 		}
// 	}
// }

// void MSBFS(vector<int>& v){
// 	int n = v.sz();
// 	queue<int> q;
// 	fr(i,0,n){
// 		q.push(v[i]);
// 		level[v[i]]=1;
// 		vis[v[i]]=1;
// 	}
// 	while(!q.empty()){
// 		auto cv = q.front();
// 		q.pop();
// 		cout<<cv<<" ";
// 		for(auto c:adjlist[cv]){
// 			if(level[cv]+1<level[c]){
// 				level[c] = level[cv] +1;
// 				vis[c] = 1;
// 				q.push(c); 
// 			}
// 		}
// 	}
// }

// bool isvalid(int x,int y,int n,int m){
// 	return ( x>=0 && x<n && y>=0 && y<m );
// }

// vector<pair<int,int>> mm {
// 	{-1,-1} , {1,1} , {-1,1} , {1,-1} , {1,0} , {-1,0} ,{0,1} , {0,-1} 
// };

// int MSBFS(int n,int m){
// 	queue<pair<int,int>> q;
// 	int mx = int_min;
// 	fr(i,0,n) fr(j,0,m) mx = max(mx,grid[i][j]);

// 	fr(i,0,n) fr(j,0,m){
// 		if(grid[i][j]==mx){
// 			q.push({i,j});
// 			vis[i][j] = 1;
// 			level[i][j] = 0;
// 		}
// 	}

// 	int ans = 0;
// 	while(!q.empty()){
// 		auto cv = q.front();
// 		q.pop();
// 		int cv_x = cv.f;
// 		int cv_y = cv.s;
// 		for(auto &p:mm){
// 			int c_cv_x = p.f + cv_x;
// 			int c_cv_y = p.s + cv_y;
// 			if(!isvalid(c_cv_x,c_cv_y,n,m)) continue;
// 			if(vis[c_cv_x][c_cv_y]) continue;
// 			q.push({c_cv_x,c_cv_y});
	
// 			level[c_cv_x][c_cv_y] = level[cv_x][cv_y] + 1;
// 			ans = max(ans , level[c_cv_x][c_cv_y]);
// 			vis[c_cv_x][c_cv_y] = 1;
// 		}
// 	}
// 	return ans;
// }

// int n;

// void DIJKSTRA(int v){

// 	vector<int> dis(n+1,1e9+3);
// 	vector<int> vis(n+1,0);

// 	set<pair<int,int>> s;
// 	s.insert(mp(0,v));
// 	dis[v] = 0;

// 	while(s.sz()>0){
		
// 		auto x = *(s.begin());
// 		s.erase(s.begin());
// 		int cv = x.s;
// 		if(vis[cv]) continue;
// 		vis[cv] = 1;

// 		for(auto c:adjlist[cv]){
// 			int c_cv = c.f;
// 			int wt = c.s;
// 			if(dis[cv]+wt < dis[c_cv]){
// 				dis[c_cv] = dis[cv] + wt;
// 				s.insert({dis[c_cv],c_cv});
// 			}
// 		}
// 	}

// 	// debugv(dis,1,n+1)
// 	fr(i,1,n+1){
// 		if(dis[i]==(1e9+3)) cout<<"I"<<" ";
// 		else cout<<dis[i]<<" ";
// 	}
// 	cout<<endl;
// }

// int p[N],s[N];

// void make(int v){
// 	p[v] = v;
// 	s[v] = 1;
// }

// int find(int v){
// 	if(v==p[v]) return v;
// 	else return p[v] = find(p[v]);
// }

// void Union(int u,int v){
// 	u = find(u);
// 	v = find(v);

// 	if(v!=u){
// 		if(s[u]>s[v]){
// 			swap(u,v);
// 		}
// 		p[u] = v;
// 		s[v]+=s[u];
// 	}
// }

void solve()
{	
	// graph terminologies
	// graph representation
	// graph traversal => DFS => connected componenets => cycle detection => height and depth
	// DFS using a adjlist and grid
	// diameter of the tree using the depth of the tree
	// lowest command encestor , edge deletion in a tree 
	// graph travsersal => BFS => application of the BFS => 0 1 BFS => multi source BFS(MSBFS)..
	// DIJKSRA's shortest path using the BFS on a graph
	// all pair shortest path algo => floyyd warshell
	// DSU
	// minimum spanning tree (MST) (kruskal's algo) ( tree + DSU )
	
	// all types of the binary tree ( class representation )
	// binary tree traversals
	
	// int n;cin>>n; // no of vertices
	// int adjmat[n+1][n+1];
	// int m;cin>>m; // no of edges
	// fr(i,0,m){
	// 	int x,y;cin>>x>>y;
	// 	adjmat[x][y]=1;
	// 	adjmat[y][x]=1;
	// }
	// fr(i,0,m){
	// 	int x,y;cin>>x>>y;
	// 	adjlist[x].pb(y);
	// 	adjlist[y].pb(x);
	// }
	// DFS(1);
	
	// for a undirected graph , no of connected componenets => total no of independent DFS calls
	// int ans = 0;
	// fr(i,1,n+1){
	// 	if(vis[i]) continue;
	// 	DFS(i);
	// 	ans++;
	// }
	// cout<<ans;
	
	// cycle detection -> idea => during the DFS call , if we come across any child of a particular node if the child is not the parent of that node and is still 
	// visisted that means the cycle is present in the graph
	// cout<<DFS(1,-1);

	// the height and the depth of the tree is defined as 
	// depth[v] = depth[parent[v]] +1
	// height[v] = max of all child of v (height[v]) + 1;
	// DFS(1,-1);
	// debugv(h,1,n+1);
	// debugv(d,1,n+1);

	// DFS on a grid 
	// given a n x m grid of 0's and 1's , find the total no of islands/connected components
	// int n,m;cin>>n>>m;
	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		cin>>grid[i][j];
	// 	}
	// }
	// int ans = 0;
	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		if(vis[i][j] || grid[i][j]==0) continue;
	// 		DFS(i,j,n,m);
	// 		ans++;
	// 	}
	// }
	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		cout<<d[i][j]<<" ";
	// 	}cout<<endl;
	// }
	// cout<<ans;
		
	// subtree sum problem :
	// int n;cin>>n;
	// fr(i,0,n-1){	
	// 	int x,y;cin>>x>>y;
	// 	adjlist[x].pb(y);
	// 	adjlist[y].pb(x);
	// }
	// DFS(1,-1);
	// // debugv(ss,1,n+1);
	// // debugv(even,1,n+1);
	// int newroot = -1;
	// int maxdepth = -1;
	// fr(i,1,n+1){
	// 	maxdepth = max(maxdepth,d[i]);
	// 	if(maxdepth==d[i]) newroot=i;
	// }
	// debug(newroot)
	// fr(i,1,n+1) d[i]=0;
	// DFS(newroot,-1);
	// int ans = -1;
	// fr(i,1,n+1)
	// 	ans = max(ans,d[i]);
	// debugv(d,1,n+1);
	// cout<<ans;
	
	// LCA of node1 and node2
	// int n;cin>>n;
	// fr(i,0,n-1){
	// 	int x,y;
	// 	cin>>x>>y;
	// 	adjlist[x].pb(y);
	// 	adjlist[y].pb(x);
	// }
	// DFS(1,-1);
	// int node1,node2;cin>>node1>>node2;
	// int a = d[node1] , b = d[node2];
	// if(a>b){
	// 	int diff = a-b;
	// 	fr(i,0,diff) node1=par[node1];
	// }else{
	// 	int diff = b-a;
	// 	fr(i,0,diff) node2=par[node2];
	// }
	// while(node1!=node2){
	// 	node1=par[node1];
	// 	node2=par[node2];
	// }
	// cout<<node1<<endl;
	
	// edge deletion using the DFS
	// run the sts 
	// ans = -99999;
	// for every edge in the edgelist ( list<pir<int,int>> )(v1,v2) ans = max(ans , sts(v2)*(sts(root)-sts(v2)))

	// BFS -> level order traversal		// use of FIFO data structure ( queue )  
	// int n,m;cin>>n>>m
	// fr(i,0,m){
	// 	int x,y;cin>>x>>y;	
	// 	adjlist[x].pb(y);
	// 	adjlist[y].pb(x);
	// }
	// BFS(1);
	// debugv(vis,1,n+1);
	// debugv(level,1,n+1);
	
	// (0-1) BFS
	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int x,y;
	// 	cin>>x>>y;
	// 	adjlist[x].pb(y);
	// 	adjlist[y].pb(x);
	// }		// BFS(1);
	// ebugv(level,1,n+1)

	// MSBFS
	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int x,y;cin>>x>>y;
	// 	adjlist[x].pb(y);
	// 	adjlist[y].pb(x);
	// }
	// int l;cin>>l;
	// vector<int> v(l);
	// fr(i,0,l) cin>>v[i];
	// MSBFS(v);

	// int n,m;cin>>n>>m;
	// fr(i,0,n) fr(j,0,m) cin>>grid[i][j];
	// cout<<MSBFS(n,m);

	// DIJKSTRA's shortest path algo
	// int m;cin>>n>>m;	
	// fr(i,0,m){
	// 	int x,y,z;
	// 	cin>>x>>y>>z;
	// 	adjlist[x].pb({y,z});
	// }
	// fr(i,1,n+1) debug(adjlist[i]);
	// fr(i,1,n+1)
	// 	DIJKSTRA(i);
	
	// floyd warshell 
	// int n,m;cin>>n>>m;
	// fr(i,0,n+1){
	// 	fr(j,0,n+1){
	// 		if(i==j) grid[i][j] = 0;
	// 		else grid[i][j] = 1e9+3;
	// 	}
	// }
	// fr(i,0,m){
	// 	int x,y,z;
	// 	cin>>x>>y>>z;
	// 	grid[x][y] = z;
	// }
	// fr(k,0,n+1){
	// 	fr(i,0,n+1){
	// 		fr(j,0,n+1){
	// 			if(grid[i][k]!=1e9+3 && grid[k][j]!=1e9+3)
	// 				grid[i][j] = min(grid[i][j] , grid[i][k]+grid[k][j]);
	// 		}
	// 	}
	// }
	// fr(i,1,n+1){
	// 	fr(j,1,n+1){
	// 		if(grid[i][j]==1e9+3) cout<"I ";
	// 		else cout<<grid[i][j]<<" ";
	// 	}cout<<endl;
	// }}
	
	// DSU
	// make , find , union
	// for all of these we need to maintain the  parent array and size array(for the size compression)

	// make(1);
	// make(2);
	// make(3);
	// make(4);
	// Union(2,3);
	// Union(4,3);
	// cout<<s[4]<<" "<<s[3]<<" "<<s[1]<<endl;
	// cout<<p[4]<<" "<<p[3]<<" "<<p[1]<<endl;

	// MST -> minimum spanning tree
	// the MST of a grpah is a tree such that the edge weights sum is minimum
	// approach => sort the edges based in thier weights => starting from the lowest weighted edge => keep combinning untill all edges are exhausted and the creation of
	// the loop is avoided using the DSU property , if parent of two different nodes are same and forming the cycle then dont combine them

	// int n,m;cin>>n>>m;
	// fr(i,1,n+1) make(i);

	// vector<pair<int,pair<int,int>>> edges;
	// fr(i,0,m){
	// 	int x,y,z;cin>>x>>y>>z;
	// 	edges.pb({z,{x,y}});
	// }

	// vector<pair<pair<int,int>,int>> edgesinmst;
	// sort(edges.begin(),edges.end());
	// int ans = 0;
	// for(auto e:edges){
	// 	int wt = e.f;
	// 	int u = e.s.f;
	// 	int v = e.s.s;
	// 	if(find(u)==find(v)) continue;
	// 	Union(u,v);
	// 	ans+=wt;
	// 	edgesinmst.pb({{u,v},wt});
	// }
	// cout<<ans<<endl<<endl;
	// for(auto p:edgesinmst){
	// 	cout<<"("<<p.f.f<<","<<p.f.s<<") -> "<<p.s<<endl;
	// }
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