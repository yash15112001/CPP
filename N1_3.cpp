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

const int N = 2e5+2;
vector<pair<int,int>> adjlist[N];
int dp[N][2];

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


// vector<int> sub(N);
// void dfs(int v,int p){
// 	for(auto c:adjlist[v]){
// 		if(c==p) continue;
// 		dfs(c,v);
// 		sub[v]+=(1+sub[c]);
// 	}
// }

void dfs(int v,int p){
	vector<int> prefix,suffix;
	dp[v][1]=dp[v][0]=0;
	bool ch=true;
	for(auto c:adjlist[v]){
		if(c.f==p) continue;
		ch=false;
		dfs(c.f,v);
	}
	if(ch) return;

	for(auto c:adjlist[v]){
		if(c.f!=p){
			prefix.pb(max(dp[c.f][1],dp[c.f][0]));
			suffix.pb(max(dp[c.f][1],dp[c.f][0]));
		}
	}
	// fr(i,1,(int)prefix.sz()) prefix[i]+=prefix[i-1];
	// rf(i,(int)suffix.sz()-2,-1) suffix[i]+=suffix[i+1];

	for(int i=1;i<(int)prefix.sz();i++) prefix[i]+=prefix[i-1];
	for(int i=(int)suffix.sz()-2;i>=0;i--) suffix[i]+=suffix[i+1];

	dp[v][0] = suffix[0];
	int c_no=0;
	for(auto c:adjlist[v]){
		if(c.f==p) continue;
		int lc,rc;
		if(c_no==0) lc=0;
		else lc = prefix[c_no-1];
		if(c_no==(int)suffix.sz()-1) rc=0;
		else rc = suffix[c_no+1];
		dp[v][1] = max(dp[v][1],c.s+lc+rc+dp[c.f][0]);
		c_no++;
	}
}




void solve()
{	
	// dp on tree (generic,binary)

	// 1) given a structure of a company , calculate the no of subordinates for every employee
	// int n;cin>>n;
	// fr(i,0,n-1){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	adjlist[b].pb(a);
	// }
	// dfs(1,0);
	// fr(i,1,n+1) cout<<sub[i]<<" ";

	// 2) a matching is a set of edges where every node is part of at most one edge , return the max no of edges in the matching.
	// int n;cin>>n;
	// fr(i,0,n-1){
	// 	int a,b,c;
	// 	cin>>a>>b>>c;
	// 	adjlist[a].pb({b,c});
	// 	adjlist[b].pb({a,c});
	// }
	// dfs(1,0);
	// cout<<max(dp[1][1],dp[1][0]);

	// 3) diameter of the tree
	// int n;cin>>n;
	// fr(i,0,n-1){
	// 	int a,b;cin>>a>>b;
	// 	adjlist[a].pb(b);
	// 	adjlist[b].pb(a);
	// }
	// approach 1 : 2 dfs
	// approach 2 : recurssion
	// approach 3 : dp



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