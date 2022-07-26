#include<bits/stdc++.h>
using namespace std;
#define fr(i,a,n) for(auto i=a;i<n;i++)
#define rf(i,n,a) for(auto i=n;i>a;i--)
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define ud unordered
#define sz size
#define f first
#define s second
#define mp make_pair
#define mt make_tuple
#define all(x) x.begin(),x.end()
#define int_max 1e9
#define int_min -1e9
#define null NULL
#define scanvector(v,n) int n;cin>>n;vector<int> v(n);fr(i,0,n) cin>>v[i];
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
template<class T>void _print(vector<T> v1){ cerr<<"[ "; for(T i:v1) { _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(vector<T> v1,int a,int b){ cerr<<"[ "; for(int i=a;i<b;i++) { _print(v1[i]); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(set<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(unordered_set<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T>void _print(multiset<T> s){ cerr<<"[ "; for(T i:s){ _print(i); cerr<<" "; } cerr<<"]"; }
template<class T,class V>void _print(pair<T,V> p){ cerr<<"{";_print(p.f);cerr<<",";_print(p.s);cerr<<"}"; }
template<class T,class V>void _print(map<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }
template<class T,class V>void _print(unordered_map<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }
template<class T,class V>void _print(multimap<T,V> s){ cerr<<"[ "; for(auto i:s){ cerr<<"{";_print(i.f); cerr<<","; _print(i.s); cerr<<"} "; } cerr<<"]"; }

// int dp[100001];
vector<int> dp(10001,-1);

// int fibrec(int n){
// 	if(n==0||n==1) return n;
// 	return fibrec(n-1)+fibrec(n-2);
// }

// int fibmem(int n){
// 	if(n==0||n==1) return n;
// 	if(dp[n]!=-1) return dp[n];
// 	return dp[n]=fibmem(n-1)+fibmem(n-2);
// }

// int fibiter(int n){
// 	dp[0]=0;
// 	dp[1]=1;
// 	fr(i,2,n+1)
// 		dp[i]=dp[i-1]+dp[i-2];
// 	return dp[n];
// }

// int frog1(int n,vector<int> v){
// 	if(n==0) return 0;
// 	if(n==1) return abs(v[n]-v[n-1]);

// 	return min(abs(v[n]-v[n-1])+frog1(n-1,v),abs(v[n]-v[n-2])+frog1(n-2,v));
// }

// int frog1mem(int n,vector<int> v){
// 	if(n==0) return 0;
// 	if(n==1) return abs(v[n]-v[n-1]);
// 	if(dp[n]!=-1) return dp[n];

// 	return dp[n] = min(frog1mem(n-1,v)+abs(v[n]-v[n-1]),frog1mem(n-2,v)+abs(v[n]-v[n-2]));
// }

// int frog2(int n,int k,vector<int> v){
// 	if(n==0) return 0;
// 	if(dp[n]!=-1) return dp[n];
// 	int ans = int_max;
// 	fr(i,1,k+1){
// 		if(n-i>=0)
// 			ans = min(ans,frog2(n-i,k,v)+abs(v[n]-v[n-i]));
// 	}
// 	return dp[n]=ans;
// }

int LIS(int n,vector<int> v){
	if(dp[n]!=-1) return dp[n];
	int ans = 1;
	fr(j,0,n){
		if(v[j]<v[n])
			ans = max(ans,LIS(j,v)+1);
	}
	return dp[n]=ans;
}

void solve()
{	
	// basic 1D DP

	// 1 -> fibonacci numbers - recursive
	// int n;cin>>n;
	// cout<<fibrec(n)<<endl;

	// // 1.1 -> fibonacci - top down - memoize
	// // int n;cin>>n;
	// memset(dp,-1,sizeof(dp));
	// cout<<fibmem(n)<<endl;

	// // 1.2 -> fibonacci - bottom up - tabulation
	// cout<<fibiter(n);

	// 2 -> frog 1 reccursive
	// int n;cin>>n;
	// vector<int> v(n);
	// fr(i,0,n) cin>>v[i];
	// cout<<frog1(n-1,v);

	// 2.1 -> frog1 memoize top down
	// int n;cin>>n;
	// vector<int> v(n);
	// memset(dp,-1,sizeof(dp));
	// fr(i,0,n) cin>>v[i];
	// cout<<frog1mem(n-1,v)<<endl;
	// cout<<dp[n-1]<<endl;

	// 3 -> frog 2
	// int n,k;cin>>n>>k;
	// vector<int> v(n);
	// // memset(dp,-1,sizeof(dp));
	// fr(i,0,n) cin>>v[i];
	// cout<<frog2(n-1,k,v);
	// debugv(dp,0,n+1);

	// 4 -> LIS
	int n;cin>>n;
	vector<int> v(n);
	fr(i,0,n) cin>>v[i];
	int ans = int_min;
	fr(i,0,n)
		ans = max(ans,LIS(i,v));
	cout<<ans;
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