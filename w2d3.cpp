#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,n) for(auto i=a;i<n;i++)
#define rf(i,n,a) for(auto i=n;i>a;i--)
#define pb push_back
#define ppb pop_back
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

int binexpo(int a,int b,int m){int ans=1;while(b){if(b&1) ans=(ans*1ll*a)%m; a=(a*1ll*a)%m; b>>=1;} return ans;}
int MMI(int a){return binexpo(a,M-2,M);}

void _print(int x){ cerr<<x; }
void _print(string x){ cerr<<x; }
void _print(char x){ cerr<<x; }
void _print(ll x){ cerr<<x; }
void _print(bool x){ cerr<<x; }

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
// int parent[N];
// int size[N];
// multiset<int> sizes;

// void make(int vertex){
// 	parent[vertex] = vertex;
// 	size[vertex] = 1;
// 	sizes.insert(size[vertex]);
// }

// int find(int vertex){
// 	if(vertex == parent[vertex]) return vertex;
// 	// path compression
// 	else return parent[vertex] = find(parent[vertex]);
// }

// void merge(int a,int b){
// 	// auto it1 = sizes.find(size[a]);
// 	// auto it2 = sizes.find(size[b]);
// 	sizes.erase(sizes.find(size[a]));
// 	sizes.erase(sizes.find(size[b]));
// 	sizes.insert(size[a]+size[b]);
// }

// void UNION(int vertex1,int vertex2){
// 	// union by size -> union by the no of vertices in sets
// 	// always make the parent of the set with higher size as the parent of the set which has the lower size
// 	// size of a set -> no of vertices in the set
// 	vertex1 = find(vertex1);
// 	vertex2 = find(vertex2);
// 	if(vertex1 != vertex2){
// 		if(size[vertex1]<size[vertex2])
// 			swap(vertex1,vertex2);
// 		parent[vertex2] = parent[vertex1];
// 		merge(vertex1,vertex2);
// 		size[vertex1] += size[vertex2];
// 	}
// }

// int parent[N];
// int size[N];

// void make(int v){
// 	parent[v]=v;
// 	size[v]=1;
// }

// int find(int v){
// 	if(v==parent[v]) return v;
// 	return parent[v]=find(parent[v]);
// }

// void UNION(int v,int u){
// 	v = find(v);
// 	u = find(u);

// 	if(v!=u){
// 		if(size[v]<size[u])
// 			swap(v,u);
// 		parent[u]=v;
// 		size[v]+=size[u];
// 	}
// }

void solve()
{	
	// disjoint set union
	// three finctions in the DSU
	// -> make(vertex) = independent node vertex which is parent of itself
	// -> find(vertex) = return the root of the tree to which the vertex belongs = parent of the group
	// -> union(vertex1,vertex2) = join the two groups -> ( tree form ) -> make the parent of the vertex1 to be the parent of the vetex2
	// or vise versa => ( path compression and union by rank/size )

	// make(1);
	// make(2);
	// make(3);
	// make(4);
	// UNION(1,2);
	// UNION(2,3);

	// union by size => why?
	// every time we union two sets , we are always parent of the second grp = parent of the first grp
	// but in some cases when the size of the second grp is larger than the first grp then the time complexcity to find the parent of 
	// veretx which is the potential leaf node in the second grp is increased thats why we need the union by size/rank

	// example suppose that we have two disjoint set of vertices
	// 	 1     2
	//   |     |
	//   3     4
	//   |     |
	//   7     6
	//         |
	//         8
	//         |
	//         9  

	// before union the find of 9 is only five step process but after the standard union(7,9) we will have the set as following in
	// which the find operation of the vertex 9 is six step process , after union(7,9)

	//		 1
	//		/ \
	//	   3   2
	//	   |   |
	//	   7   4
	//	       |
	//	       6
	//	       |
	//	       8
	//	       |
	//	       9

	// path comparession => why?
	// every time finding the parent of the certain vertex , we will assign the parent of (the each and every temp-vertex ,which lies 
	// between the vertex and parent) as parent of the grp to compress the path.

	// example
	//	1
	//	|
	//	2
	//	|
	//	3
	//	|
	//	4

	// while finding the parent of the node 4 , we will assign the parent of the each and every vertices as the parent of 4

	// after path compression
	//		1
	//	  /	| \
	//	 2  3  4

	// it decreses the time complexcity to find the parent of the vertex

	// time complexcity of the path compression and union by size -> O(α(N)) -> amotorized complexcity
	// α(N) -> reverse ackerman function -> value increase very very slowly
	// α(N) <= 4 , for N < 10^600

	// problem -> given n vertecies and k edges find the conneceted components

	// int a,b,n,k;cin>>n>>k;
	// fr(i,1,n+1) make(i);
	// fr(j,0,k){
	// 	cin>>a>>b;
	// 	UNION(a,b);
	// }

	// int ans=0;
	// fr(i,1,n+1){
	// 	if(find(i)==i) ans++;
	// }
	// cout<<ans; 

	// set<int> st;
	// fr(i,1,n+1)
	// 	st.insert(parent[i]);
	// cout<<st.sz();

	// problem2 
	// city and campers
	// N camper grps wandoring the city , any 2 grps will join in one at the moment the they meet each other
	// at start every grp has only one members
	// given q queries that camper grp i and j meets , return the difference of max size and min size at that moment 
	// int v1,v2,n,q;
	// cin>>n>>q;
	// fr(i,1,n+1)
	// 	make(i);

	// while(q--){
	// 	cin>>v1>>v2;
	// 	UNION(v1,v2);
	// 	if(sizes.sz()==1) cout<<0<<endl;
	// 	else{
	// 		int mn = *sizes.begin();
	// 		int mx = *(--sizes.end());
	// 		cout<<mx-mn<<endl;
	// 	}
	// }

	// kruskal's algorithm --- MST?
	// int v2,v1,wt,n,m;cin>>n>>m;
	// vector< pair< int , pair<int,int> > > edges;
	// fr(i,0,m){
	// 	cin>>v1>>v2>>wt;
	// 	edges.pb({wt,{v1,v2}});
	// }
	// fr(i,1,n+1) make(i);

	// sort(edges.begin(),edges.end());
	// int edges_wt_sum=0;
	// for(auto &edge:edges){
	// 	int wt = edge.f;
	// 	int v = edge.s.f;
	// 	int u = edge.s.s;
	// 	if(find(v)==find(u)) continue;
	// 	UNION(v,u);
	// 	cout<<u<<" "<<v<<" "<<wt<<endl;
	// 	edges_wt_sum+=wt;
	// }

	// // debug(edges)
	// cout<<edges_wt_sum;

	// shinchikuji and power grid problem

	// int a,b,n;cin>>n;
	// vector<pair<int,int>> pos(n+1);
	// fr(i,1,n+1){
	// 	cin>>pos[i].f>>pos[i].s;
	// }
	// vector<int> c(n+1),k(n+1);
	// fr(i,1,n+1) cin>>c[i];
	// fr(i,1,n+1) cin>>k[i];

	// vector<pair<long long,pair<int,int>>> edges;

	// fr(i,1,n+1){
	// 	edges.pb({c[i],{0,i}});
	// }

	// fr(i,1,n+1){
	// 	fr(j,i+1,n+1){
	// 		int dist_charge = abs(pos[i].f-pos[j].f) + abs(pos[i].s-pos[j].s);
	// 		int k_charge = k[i]+k[j];
	// 		ll f_cost = dist_charge * 1LL * k_charge;
	// 		edges.pb({f_cost,{i,j}});
	// 	}
	// } 

	// fr(i,1,n+1) make(i);

	// sort(edges.begin(),edges.end());

	// ll edges_wt_sum=0;
	
	// vector<int> psc;
	// vector<pair<int,int>> connections;

	// for(auto &edge:edges){
	// 	int wt = edge.f;
	// 	int v = edge.s.f;
	// 	int u = edge.s.s;
	// 	if(find(v)==find(u)) continue;
	// 	UNION(v,u);
	// 	if(u==0||v==0) psc.pb(max(u,v));
	// 	else connections.pb({v,u});
	// 	// cout<<u<<" "<<v<<" "<<wt<<endl;
	// 	edges_wt_sum+=wt;
	// }
	// cout<<edges_wt_sum<<endl;
	// cout<<psc.sz()<<endl;
	// for(auto city:psc)
	// 	cout<<city<<" ";
	// cout<<endl;
	// cout<<connections.sz()<<endl;
	// for(auto c:connections)
	// 	cout<<c.f<<" "<<c.s<<endl;

	// trees/graph using the class to implement the rest of the functionalities
	
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