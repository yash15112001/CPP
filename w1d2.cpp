#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,n) for(auto i=a;i<n;i++)
#define rf(i,n,a) for(auto i=n;i>a;i--)
#define pb push_back
#define ppb pop_back
#define f first
#define s second
#define mp make_pair
#define sz size
#define mt make_tuple
#define int_max 1e9
#define int_min -1e9
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

// const int N = 1e3+7;
// bool vis[N];
// vector<int> adjlist[N];

// bool DFS(int vertex,int parent){
// 	//
// 	vis[vertex]=true;
// 	bool l=false;
// 	for(auto child:adjlist[vertex]){
// 		//
// 		if(vis[child] && child==parent) continue;
// 		if(vis[child]) return true;
// 		l|=DFS(child,vertex);
// 		//
// 	}
// 	//
// 	return l;
// }

// void DFS(int sr,int sc,vector<vector<int>>& image,int ic,int nc){

// 	int n=image.sz();
// 	int m=image[0].sz();
// 	if(sr<0 || sc<0 ) return;
// 	if(sr>=n || sc>=m ) return;
// 	if(image[sr][sc]!=ic ) return;

// 	image[sr][sc]=nc;

// 	DFS(sr-1,sc,image,ic,nc);
// 	DFS(sr,sc-1,image,ic,nc);
// 	DFS(sr+1,sc,image,ic,nc);
// 	DFS(sr,sc+1,image,ic,nc);
// }

// vector<vector<int>> floodfill(vector<vector<int>>& image,int sr,int sc,int nc){
// 	int ic=image[sr][sc];
// 	if(ic!=nc)
// 		DFS(sr,sc,image,ic,nc);
// 	return image;
// }

// const int N=1e5+1;
// vector<int> adjlist[N];

// int depth[N],height[N];

// void DFS(int vertex,int p=0){
// 	for(auto child : adjlist[vertex]){
// 		if(child==p) continue;
// 		depth[child]=depth[vertex]+1;
// 		DFS(child,vertex);
// 		height[vertex]=max(height[vertex],height[child]+1);
// 	}
// }

const int N=1e5+7;
vector<int> adjlist[N];

void DFS(int vertex,int p=0){
	cout<<vertex<<" ";
	for(auto c:adjlist[vertex]){
		if(c==p) continue;
		DFS(c,vertex);
	}
}
void solve()
{	
	// cycle detection using the DFS
	// int n,m,v1,v2;cin>>n>>m;
	// fr(i,0,m){
	// 	cin>>v1>>v2;
	// 	adjlist[v1].pb(v2);
	// 	adjlist[v2].pb(v1);
	// }
	// bool loop=false;
	// fr(i,1,n+1){
	// 	if(vis[i]) continue;
	// 	if(DFS(i,0)){
	// 		loop=true;
	// 		break;
	// 	}
	// }
	// cout<<loop;

	// flood fill + rotten tomatoes -> same problem
	// no of islands -> connected components

	// int x,y,e;cin>>x>>y;

	// vector<vector<int>> image;
	// vector<int> temp;
	// fr(i,0,x){
	// 	temp.clear();
	// 	fr(j,0,y){
	// 		cin>>e;
	// 		temp.pb(e);
	// 	}
	// 	image.pb(temp);
	// }

	// int sr,sc,nc;
	// cin>>sr>>sc>>nc;

	// vector<vector<int>> ans=floodfill(image,sr,sc,nc);

	// for(auto v:ans){
	// 	for(auto i:v){
	// 		cout<<i<<" ";
	// 	}
	// 	cout<<endl;
	// }

	// DFS for tree -> in tree we dont have to give the input for the edges because edges = nodes - 1
	// in tree we also dont have to use the visted array because of the structure of the tree and absence of the loop in the tree
	// int n,v1,v2;cin>>n;
	// fr(i,0,n-1){
	// 	cin>>v1>>v2;
	// 	adjlist[v1].pb(v2);
	// 	adjlist[v2].pb(v1);
	// }
	// DFS(1);
	// fr(i,1,n+1){
	// 	cout<<depth[i]<<" "<<height[i]<<endl;
	// }

	// int n;cin>>n;
	// int v1,v2;
	// fr(i,0,n-1){
	// 	cin>>v1>>v2;
	// 	adjlist[v1].pb(v2);
	// 	adjlist[v2].pb(v1);
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