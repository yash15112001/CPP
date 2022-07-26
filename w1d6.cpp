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

const int N = 1e3+353;

// int mat[N][N];
// int vis[N][N];
// int level[N][N];
// int n,m;

// vector<int> adjlist[N];
// vector<int> level(N,int_max);

// (0-1) BFS
// int BFS(int s,int d){
// 	deque<int> q;
// 	q.pb(s);
// 	level[s]=0;

// 	while(!q.empty()){
// 		int cv=q.front();
// 		q.ppf();
// 		for(auto c:adjlist[cv]){
// 			int child=c.f;
// 			int wt=c.s;
// 			if(level[cv]+wt<level[child]){
// 				level[child]=level[cv]+wt;
// 				if(wt) q.pb(child);
// 				else q.pf(child);
// 			}
// 		}
// 	}
// 	return level[d]==int_max?-1:level[d];
// }

// BFS using the levels
// void BFS(int s){
// 	queue<int> q;
// 	q.push(s);
// 	level[s]=0;

// 	while(!q.empty()){
// 		int cv=q.front();
// 		q.pop();
// 		cout<<cv<<" ";
// 		for(auto c:adjlist[cv]){
// 			if(level[cv]+1<level[c]){
// 				level[c]=level[cv]+1;
// 				q.push(c);
// 			}
// 		}
// 	}
// }

// void MSBFS(int v1,int v2){
// 	queue<int> q;
// 	q.push(v1);
// 	q.push(v2);
// 	level[v1]=0;
// 	level[v2]=0;

// 	while(!q.empty()){
// 		int cv=q.front();
// 		q.pop();
// 		cout<<cv<<" ";
// 		for(auto c:adjlist[cv]){
// 			if(level[cv]+1<level[c]){
// 				level[c]=level[cv]+1;
// 				q.push(c);
// 			}
// 		}
// 	}
// }

// vector<pair<int,int>> movements {
// 	{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}
// };

// bool isvalid(int i,int j){
// 	return i>=0 && i<n && j>=0 && j<m;
// }

// int MSBFS(){
// 	queue<pair<int,int>> q;
// 	int mx=int_min;
// 	fr(i,0,n){
// 		fr(j,0,m){
// 			mx=max(mx,mat[i][j]);
// 		}
// 	}
// 	fr(i,0,n){
// 		fr(j,0,m){
// 			if(mat[i][j]==mx){
// 				q.push({i,j});
// 				level[i][j]=0;
// 				vis[i][j]=1;
// 			}
// 		}
// 	}

// 	int ans=0;
// 	while(!q.empty()){
// 		auto cv=q.front();
// 		q.pop();
// 		int cv_x=cv.f;
// 		int cv_y=cv.s;
// 		for(auto m:movements){
// 			int c_cv_x=cv_x+m.f;
// 			int c_cv_y=cv_y+m.s;
// 			if(!isvalid(c_cv_x,c_cv_y)) continue;
// 			if(vis[c_cv_x][c_cv_y]) continue;
// 			q.push({c_cv_x,c_cv_y});
// 			level[c_cv_x][c_cv_y]=level[cv_x][cv_y]+1;
// 			ans=max(ans,level[c_cv_x][c_cv_y]);
// 			vis[c_cv_x][c_cv_y]=1;
// 		}
// 	}
// 	return ans;
// }
 
// vector<pair<int,int>> adjlist[N];
// int n;

// void DIJKSTRA(int source){
// 	vector<int> dis(n,int_max);
// 	vector<int> vis(n,0);

// 	set<pair<int,int>> st;
// 	set.insert({source,0});
// 	dis[source]=0;

// 	while(s.size()){
// 		auto n=*s.begin();
// 		s.erase(s.begin());
// 		int v=n.f;
// 		int dis=n.s;
// 		for(auto c:adjlist[v]){
			
// 		}
// 	}
// }

void solve()
{	
	// types of the BFS -> BFS , 0-1 BFS , multi source BFS , ( (0-1) MSBFS ? )
	// if we want find the shortest path where the weights of the edges are not identical( two different weights of the edges possible ) then in that case the 0-1 
	// BFS is used
	// int v1,v2,n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	cin>>v1>>v2;
	// 	if(v1==v2) continue;
	// 	adjlist[v1].pb({v2,0});
	// 	adjlist[v2].pb({v1,1});
	// }	

	// int sp,ep;cin>>sp>>ep;
	// cout<<BFS(sp,ep)<<endl;

	// implementation of the BFS using the level of the  node

	// int n,v1,v2;cin>>n;
	// fr(i,0,n-1){
	// 	cin>>v1>>v2;
	// 	adjlist[v1].pb(v2);
	// 	adjlist[v2].pb(v1);
	// }

	// BFS(1);
	// cout<<endl;
	// fr(i,1,n+1)
	// 	cout<<"level of "<<i<<" is = "<<level[i]<<endl;

	// MSBFS 
	// int v1,v2,n,m;cin>>n>>m;
	// fr(i,0,m){
	// 	cin>>v1>>v2;
	// 	adjlist[v1].pb(v2);
	// 	adjlist[v2].pb(v1);
	// }

	// cin>>v1>>v2;
	// MSBFS(v1,v2);
	// cout<<endl;

	// fr(i,1,n+1)
	// 	cout<<"level of "<<i<<" is : "<<level[i]<<endl;

	// question on MSBFS

	// cin>>n>>m;
	// fr(i,0,n){
	// 	fr(j,0,m){
	// 		cin>>mat[i][j];
	// 		level[i][j]=int_max;
	// 	}
	// }

	// cout<<MSBFS();

	// shortest path in the directed graph with the variable edge weights -> DIJKSTRA's shortest path algo
	// int m,v1,v2,wt;cin>>n>>m;
	// fr(i,0,m){
	// 	cin>>v1>>v2>>wt;
	// 	adjlist[v1].pb({v2,wt});
	// }
	// cin>>v1;
	// vector<int> ans=DIJKSTRA(v1);
	// for(auto e:ans)
	// 	cout<<e<<" ";

	
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