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
#define all(v) (int)(v.begin(),v.end())
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

const int N = 1e5+7;
vector<int> adjlist[N];
// vector<int> revadjl[N];
// vector<int> dfslist[N];

// vector<int> indegree(N);

// vector<int> topologicalkahn(int n){
// 	vector<int> ans;
// 	queue<int> q;
// 	fr(i,1,n+1){
// 		if(!indegree[i])
// 			q.push(i);
// 	}
// 	while(!q.empty()){
// 		auto cv = q.front();
// 		q.pop();
// 		ans.pb(cv);

// 		for(auto c:adjlist[cv]){
// 			indegree[c]--;
// 			if(indegree[c]==0)
// 				q.push(c);
// 		}O
// 	}
// 	return ans;
// }

vector<int> in(N);
vector<int> out(N);
vector<int> vis(N);
int t=1;
vector<int> ssccheck(N);

// void DFS(int root){
// 	vis[root]=1;
// 	in[root]=t++;

// 	for(auto c:adjlist[root]){
// 		if(!vis[c]){
// 			DFS(c);
// 		}
// 	}
// 	out[root]=t++;
// }

// void DFSINOUT(int v){
// 	vis[v]=1;
// 	in[v]=t++;
// 	for(auto c:adjlist[v]){
// 		if(!vis[c])
// 			DFSINOUT(c);
// 	}
// 	out[v]=t++;
// }

// vector<int> scc;

// void DFS2(int v){
// 	ssccheck[v]=1;
// 	scc.pb(v);
// 	for(auto c:revadjl[v]){
// 		if(!ssccheck[c])
// 			DFS2(c);
// 	}
// }

vector<pair<int,int>> forward,back,bridges;
vector<int> intime(N),lowtime(N);
// int t=1;

// void DFSLIST(int v,int p){
// 	vis[v]=1;
// 	for(auto c:adjlist[v]){
// 		if(c==p) continue;
// 		if(vis[c] && c!=p ) {back.pb(mp(v,c)); continue;}  
// 		else{
// 			forward.pb(mp(v,c));
// 			DFSLIST(c,v);
// 		}
// 	}
// }

void DFSBRIFGE(int v,int p){
	vis[v]=1;
	intime[v]=lowtime[v]=t++;

	for(auto c:adjlist[v]){
		if(c==p) continue;
		if(vis[c]){
			lowtime[v] = min(lowtime[c],lowtime[v]);
		}else{
			DFSBRIFGE(c,v);
			if(intime[v]<lowtime[c])
				bridges.pb(mp(v,c));
			lowtime[v] = min(lowtime[v],lowtime[c]);
		}
	}
}

void solve()
{	
	// only for the graph => continuing on the c.cpp
	// extra topics

	// topological sort and applications
	// in/out time of a vertex
	// strongly connected components : kosaraju's algo and Tarjan's algo
	// bridges and AP
	// bipartite graph 
	// prim's and kruskal's algo for the MST

	// 1 -> topological sort and applications -> task schedular
	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int x,y;cin>>x>>y;
	// 	adjlist[x].pb(y);
	// 	indegree[y]++;
	// }
	// vector<int> ans = topologicalkahn(n);
	// for(auto e:ans) cout<<e<<" ";

	// 2 -> in/out time of a vertex => start time = 1
	// int n;cin>>n;
	// fr(i,0,n-1){
	// 	int x,y;cin>>x>>y;
	// 	adjlist[x].pb(y);
	// }

	// DFS(1);
	// debugv(in,1,n+1);
	// debugv(out,1,n+1);

	// 3** -> kosaraju's algo

	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int x,y;cin>>x>>y;
	// 	adjlist[x].pb(y);
	// 	revadjl[y].pb(x);
	// }
	// DFSINOUT(1);

	// vector<pair<int,int>> vv;

	// for(int i=1;i<n+1;i++){
	// 	vv.pb(mp(out[i],i));
	// }

	// sort(vv.begin(),vv.end());
	// reverse(vv.begin(),vv.end());

	// set<vector<int>> scclist;

	// for(auto c:vv){
	// 	debug(c)
	// 	if(!ssccheck[c.s]){
	// 		scc.clear();
	// 		DFS2(c.s);
	// 		scclist.insert(scc);
	// 	}
	// }

	// cout<<scc.sz()<<endl;

	// for(auto v:scclist){
	// 	for(auto e:v)
	// 		cout<<e<<" ";
	// 	cout<<endl;
	// }

	// 4 -> Bridges and articulation points
	// bridges connection with cycles in graph -> DFS tree -> all edges which are traversed for the BFS 
	// back edges and forward edges concept 

	// 4.1 -> find a tree with no cycles from the graph -> bfstreelist
	// int n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	int x,y;cin>>x>>y;
	// 	adjlist[x].pb(y);
	// 	adjlist[y].pb(x);
	// }
	// DFSLIST(1,-1);

	// cout<<"Total number of forward edges in the graph: "<<forward.sz()<<" ,and this bridges are :"<<endl ;
	// for(auto p:forward)
	// 	cout<<p.f<<" "<<p.s<<endl;

	// cout<<"total number of backward edges are: "<<back.sz()<<" ,and these edges are:"<<endl;
	// for(auto p:back)
	// 	cout<<p.f<<" "<<p.s<<endl;

	// 4.2 -> find all bridges in the graph
	// int n,m,x,y;
	// cin>>n>>m;
	// while(m--)
	// 	cin>>x>>y , adjlist[x].pb(y), adjlist[y].pb(x);

	// DFSBRIFGE(1,-1);
 
	// cout<<"total numbers of bridges are: "<<bridges.sz()<<" ,and these edges are :"<<endl;
	// for(auto c:bridges)
	// 	cout<<c.f<<" "<<c.s<<endl;

	// 4.3 -> articulation point
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