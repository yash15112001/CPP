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

const int inf = 1e9+3;
const int N = 1e4+7;

// void DIJKSTRA(int source,int n,vector<pair<int,int>> adjlist[]){

// 	vector<int> vis(N,0);
// 	vector<int> d(N,inf);

// 	set<pair<int,int>> st;
// 	st.insert({0,source});
// 	d[source]=0;

// 	while(st.size()>0){
// 		auto n=*st.begin();
// 		int v=n.s;
// 		int dist=n.f;
// 		st.erase(st.begin());
// 		if(vis[v]) continue;
// 		vis[v]=1;

// 		for(auto c:adjlist[v]){
// 			int c_v = c.f;
// 			int wt = c.s;

// 			if(d[v]+wt < d[c_v]){
// 				d[c_v] = d[v] + wt;
// 				st.insert({d[c_v],c_v});
// 			}
// 		}
// 	}

// 	fr(i,1,n+1)
// 		cout<<((d[i]==1e9+3)?-1:d[i])<<" ";
// 	cout<<endl;
// 	// int ans=0;
// 	// fr(i,1,n+1){
// 	// 	if(d[i]==inf) return -1;
// 	// 	ans=max(ans,d[i]);
// 	// }
// 	// return ans;
// }

// void networktimedelay(vector<vector<int>>& times,int n,int source){
// 	vector<pair<int,int>> adjlist[N];
// 	for(auto v:times){
// 		adjlist[v[0]].pb({v[1],v[2]});
// 	}

// 	DIJKSTRA(source,n,adjlist);
// }

/*
int dijkstra(int source,int n,vector<pair<int,int>> adjlist[]){
        vector<int> vis(N,0);
        vector<int> d(N,inf);
        
        set<pair<int,int>> st;
        st.insert({0,source});
        d[source]=0;
        
        while(st.size()>0){
            auto n=*st.begin();
            int v = n.second;
            int v_d = n.first;
            
            st.erase(st.begin());
            if(vis[v]) continue;
            vis[v]=1;

            for(auto c:adjlist[v]){
                int c_v = c.first;
                int c_d = c.second;
                
                if(d[v]+c_d < d[c_v]){
                    d[c_v] = d[v]+c_d;
                    st.insert({d[c_v],c_v});
                }
                
            }
        }
        int a=0;
        for(int i=1;i<=n;i++){
            if(d[i]==inf) return -1;
            a=max(a,d[i]);
        }
        return a;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adjlist[N];
        for(auto v:times){
            adjlist[v[0]].push_back({v[1],v[2]});
        }
        return dijkstra(k,n,adjlist);
    }
*/

void DIJKSTRA(vector<pair<int,int>> adjlist[],int n,int source){
	vector<int> vis(n+1,0);
	vector<int> d(n+1,inf);

	set<pair<int,int>> st;
	st.insert({0,source});

	d[source] = 0;

	while(st.size()>0){
		auto nn = *st.begin();
		int v = nn.s;
		int dist = nn.f;

		st.erase(st.begin());

		if(vis[v]) continue;
		vis[v]=1;

		for(auto c:adjlist[v]){
			int c_v = c.f;
			int wt = c.s;

			if(d[v]+wt<d[c_v]){
				d[c_v]=d[v]+wt;
				st.insert({d[c_v],c_v});
			}
		}
	}

	for(int i=1;i<=n;i++){
		if(d[i]==1e9+3)
			cout<<"I"<<" ";
		else
			cout<<d[i]<<" ";
	}
	cout<<endl;
}

// vector<pair<int,int>> adjlist[N];
int d[N][N];

void solve()
{	
	// int n,m;cin>>n>>m;
	// vector<vector<int>> times;
	// fr(i,0,m){
	// 	vector<int> temp(3);
	// 	fr(i,0,3)
	// 		cin>>temp[i];
	// 	times.pb(temp);
	// }

	// fr(i,1,n+1)
	// networktimedelay(times,n,i);
	// int source;cin>>source;
	// int ans=networktimedelay(times,n,source);
	
	// final DIJKSTRA

	// int n,m;cin>>n>>m;
	// vector<pair<int,int>> adjlist[n+1];
	// int v1,v2,wt;
	// fr(i,0,m){
	// 	cin>>v1>>v2>>wt;
	// 	adjlist[v1].pb({v2,wt});
	// }
	// fr(i,1,n+1)
	// 	DIJKSTRA(adjlist,n,i);

	// time -> O( N logN )
	// space -> O( N )

	// all pair shortest path algorithm -> floyd warshell algo
	// DP 

	// fr(i,0,N) fr(j,0,N) { 
	// 	if(!(i-j)) d[i][j]=0; 
	// 	else d[i][j]=inf;
	// }

	// int v1,v2,wt,n,m;
	// cin>>n>>m;
	// fr(i,0,m){
	// 	cin>>v1>>v2>>wt;
	// 	d[v1][v2]=wt;
	// }

	// fr(k,1,n+1){
	// 	fr(i,1,n+1){
	// 		fr(j,1,n+1){
	// 			if(d[i][k]!=inf and d[k][j]!=inf)
	// 				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
	// 		}
	// 	}
	// }

	// fr(i,1,n+1){
	// 	fr(j,1,n+1){
	// 		if(d[i][j]==inf) cout<<"I"<<" ";
	// 		else cout<<d[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// int n,v1,v2,wt;cin>>n;
	// for(int i=0;i<n*(n-1);i++){
	// 	cin>>v1>>v2>>wt;
	// 	d[v1][v2]=wt;
	// }
	// vector<int> del(n);
	// fr(i,0,n)
	// 	cin>>del[i];

	// reverse(del.begin(),del.end());
	// vector<int> ans;
	// fr(k,0,n){
	// 	int vertex=del[k];
	// 	fr(i,1,n+1){
	// 		fr(j,1,n+1){
	// 			d[i][j]=min(d[i][j],d[i][vertex]+d[vertex][j]);
	// 		}
	// 	}
	// 	int a=0;
	// 	fr(i,0,k+1){
	// 		fr(j,0,k+1){
	// 			a+=d[del[i]][del[j]];
	// 		}
	// 	}
	// 	ans.pb(a);
	// }

	// reverse(ans.begin(),ans.end());
	// for(auto a:ans)
	// 	cout<<a<<" ";
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