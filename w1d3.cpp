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

// const int N = 1e4+353;
// vector<int> adjlist[N];
// vector<int> subtreesum(N);
// vector<int> evens(N);

// vector<int> depth(N);

// vector<int> par(N);
// int height[N],depth[N];

// void DFS(int vertex,int p){

// 	if(!(vertex%2)) evens[vertex]++;
// 	subtreesum[vertex]+=vertex;
// 	for(auto c:adjlist[vertex]){

// 		if(c==p) continue;
// 		// depth[c]=depth[vertex]+1;
// 		DFS(c,vertex);
// 		subtreesum[vertex]+=subtreesum[c];
// 		evens[vertex]+=evens[c];
// 		// height[vertex]=max(height[vertex],height[c]+1);

// 	}

// }

// void DFS(int vertex,int p){
// 	par[vertex]=p;
// 	for(auto c:adjlist[vertex]){
// 		if(c==p) continue;
// 		depth[c]=depth[vertex]+1;
// 		DFS(c,vertex);
// 	}
// }

void DFS(vector<vector<int>>& islands,int i,int j,vector<vector<int>>& vis){
	int n=islands.sz();
	int m=islands[0].sz();
	if( i<0 || j<0 || i>=n || j>=m || vis[i][j] || !islands[i][j] ) return;
	// if(i>=n || j>=m) return;
	// if(vis[i][j] || islands[i][j]!=1) return;

	vis[i][j]=1;
	DFS(islands,i+1,j,vis);
	DFS(islands,i-1,j,vis);
	DFS(islands,i,j+1,vis);
	DFS(islands,i,j-1,vis);
}

int total_islands(vector<vector<int>>& islands,vector<vector<int>>& vis){
	int ans=0;
	int n=vis.sz();
	int m=vis[0].sz();
	fr(k,0,n){
		fr(l,0,m){
			if( !vis[k][l] && islands[k][l]){
				DFS(islands,k,l,vis);
				ans++;
			}
		}
	}
	return ans;
}

void solve()
{	
	// int n,v1,v2;cin>>n;
	// fr(i,0,n-1){
	// 	cin>>v1>>v2;
	// 	adjlist[v1].pb(v2);
	// 	adjlist[v2].pb(v1);
	// }
	
	// DFS(1,0);

	// // debug(depth)
	// int new_src=0;
	// fr(i,1,n+1){
	// 	if(depth[i]>depth[new_src]) new_src=i;
	// }
	// debug(new_src)


	// fr(i,1,n+1) depth[i]=0;
	// // debug(depth)

	// DFS(new_src,0);
	// int ans=int_min;
	// fr(i,1,n+1)
	// 	ans=max(ans,depth[i]);

	// cout<<"the diameter of the tree you have given is = "<<ans<<endl;
	// time -> O(no of nodes)

	// // fr(i,1,n+1){
	// // 	cout<<depth[i]<<" "<<height[i]<<endl;
	// // }
	// int q,v3;cin>>q;
	// while(q--){
	// 	cin>>v3;
	// 	cout<<subtreesum[v3]<<" "<<evens[v3]<<endl;
	// }

	// LCA of the tree ( undecided no of nodes on every node )
	// cin>>v1>>v2;
	// vector<int> p1=path(v1),p2=path(v2);
	// fr(i,0,min(p1.sz(),p2.sz())){
	// 	if(p1[i]==p2[i]) continue;
	// 	else{
	// 		ans=i-1;
	// 	}
	// }
	// cout<<p1[ans]<<endl;
	// int ans=0;
	// int minl=min(p1.sz(),p2.sz());
	// fr(i,0,minl){
	// 	if(p1[i]==p2[i]) ans=p1[i];
	// 	else break;
	// }
	// cout<<ans<<endl;	

	// cin>>v1>>v2;
	// int d1=depth[v1],d2=depth[v2];
	// if(d1>d2){
	// 	int diff=d1-d2;
	// 	fr(i,0,diff)
	// 		v1=par[v1];
	// }else{
	// 	int diff=d2-d1;
	// 	fr(i,0,diff)
	// 		v2=par[v2];
	// }
	// while(v1!=v2){
	// 	v1=par[v1];
	// 	v2=par[v2];
	// }
	// cout<<v1<<endl;

	// given the grid of n X m of 1s and 0s , find the total no of connected components

	int n,m,e;cin>>n>>m;
	vector<vector<int>> islands,vis;
	vector<int> temp;
	fr(i,0,n){
		temp.clear();
		fr(i,0,m){
			cin>>e;
			temp.pb(e);
		}
		islands.pb(temp);
	}

	fr(i,0,n){
		temp.clear();
		fr(i,0,m){
			temp.pb(0);
		}
		vis.pb(temp);
	}

	int ans=total_islands(islands,vis);
	cout<<ans<<endl;
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